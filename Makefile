all:
	nasm -f elf32 src/kernel_start.asm -o ks.o
	gcc -m32 -c src/kernel.c -o kernel.o
	ld -melf_i386 -T linker.ld -o iso/boot/kernel.bin ks.o kernel.o 
	grub-mkrescue -o os.iso iso
clean:
	rm *.o
	rm *.iso
	rm iso/boot/kernel.bin
