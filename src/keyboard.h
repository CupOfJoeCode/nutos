void kernel_keyboard_init();
unsigned char kernel_keyboard_get_raw();
char kernel_keyboard_get_char();
unsigned char kernel_keyboard_get_arrow();
#define KEYBOARD_ARROW_NONE 0
#define KEYBOARD_ARROW_UP 1
#define KEYBOARD_ARROW_DOWN 2
#define KEYBOARD_ARROW_LEFT 3
#define KEYBOARD_ARROW_RIGHT 4
