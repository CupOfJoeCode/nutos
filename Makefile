all:
	nasm -f elf32 src/main.asm -o ks.o
	gcc -m32 -c src/kernel.c -o kernel.o -fno-stack-protector
	gcc -m32 -c src/screen.c -o screen.o -fno-stack-protector
	gcc -m32 -c src/std.c -o std.o -fno-stack-protector
	gcc -m32 -c src/terminal.c -o terminal.o -fno-stack-protector
	gcc -m32 -c src/io.c -o io.o -fno-stack-protector
	gcc -m32 -c src/keyboard.c -o keyboard.o -fno-stack-protector
	ld -melf_i386 -T linker.ld -o iso/boot/kernel.bin ks.o kernel.o screen.o std.o terminal.o io.o keyboard.o
	grub-mkrescue -o os.iso iso
clean:
	rm *.o
	rm *.iso
	rm iso/boot/kernel.bin
