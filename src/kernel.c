#include "terminal.h"
#include "keyboard.h"

void kernel_entry()
{
    kernel_keyboard_init();
    kernel_terminal_start();
}
