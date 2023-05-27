void kernel_outb(unsigned short port, unsigned char val)
{
    asm volatile("outb %0, %1" ::"a"(val), "Nd"(port));
}

unsigned char kernel_inb(unsigned short port)
{
    unsigned char val;

    asm volatile("inb %1, %0"
                 : "=a"(val)
                 : "dN"(port));

    return val;
}