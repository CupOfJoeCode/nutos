void kernel_draw_set_char(unsigned int x, unsigned int y, char color, char c);

void kernel_draw_print_at(unsigned int x, unsigned int y, char color, char *text);

void kernel_draw_fill(char color);

void kernel_screen_reset();

unsigned char kernel_get_color_byte(unsigned char foreground, unsigned char background, unsigned char blink);

char *kernel_get_screen_buf();

void kernel_screen_get(unsigned char *charptr, unsigned char *colorptr, unsigned int x, unsigned int y);
void kernel_screen_get_dims(unsigned int *widthptr, unsigned int *heightptr);

#define VGA_COLOR_BLACK 0
#define VGA_COLOR_DBLUE 1
#define VGA_COLOR_DGREEN 2
#define VGA_COLOR_DCYAN 3
#define VGA_COLOR_DRED 4
#define VGA_COLOR_DMAGENTA 5
#define VGA_COLOR_BROWN 6
#define VGA_COLOR_GRAY 7

#define VGA_COLOR_DGRAY 8
#define VGA_COLOR_BLUE 9
#define VGA_COLOR_GREEN 10
#define VGA_COLOR_CYAN 11
#define VGA_COLOR_RED 12
#define VGA_COLOR_MAGENTA 13
#define VGA_COLOR_YELLOW 14
#define VGA_COLOR_WHITE 15
