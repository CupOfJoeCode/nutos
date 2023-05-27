#include "terminal.h"
#include "screen.h"
#include "std.h"

unsigned int cursor_x = 0;

void term_draw_splash()
{
    kernel_terminal_prints(" ");
    kernel_terminal_prints_color("    \n", kernel_get_color_byte(0, VGA_COLOR_RED, 0));
    kernel_terminal_prints_color(" ", kernel_get_color_byte(0, VGA_COLOR_BROWN, 0));
    kernel_terminal_prints_color("    ", kernel_get_color_byte(0, VGA_COLOR_RED, 0));
    kernel_terminal_prints_color(" \n      \n      \n", kernel_get_color_byte(0, VGA_COLOR_BROWN, 0));
    kernel_terminal_prints(" ");
    kernel_terminal_prints_color("    \n", kernel_get_color_byte(0, VGA_COLOR_BROWN, 0));
    kernel_terminal_prints("  ");
    kernel_terminal_prints_color("  ", kernel_get_color_byte(0, VGA_COLOR_BROWN, 0));
    kernel_terminal_prints("   NutOS v0.0.0\n\n");
}

void kernel_terminal_start()
{
    kernel_screen_reset();
    term_draw_splash();
}

void kernel_terminal_newline()
{
    int line;
    int i;
    unsigned char current_char;
    unsigned char current_color;
    unsigned int width;
    unsigned int height;
    kernel_screen_get_dims(&width, &height);
    for (line = 1; line < height; line++)
    {
        for (i = 0; i < width; i++)
        {
            kernel_screen_get(&current_char, &current_color, i, line);
            kernel_draw_set_char(i, line - 1, current_color, current_char);
        }
    }
    for (i = 0; i < width; i++)
    {
        kernel_draw_set_char(i, height - 1, 0, ' ');
    }
    cursor_x = 0;
}

void kernel_terminal_prints_color(char *string, unsigned char color)
{
    unsigned int i;
    unsigned int len = std_strlen(string);
    unsigned int width;
    unsigned int height;
    kernel_screen_get_dims(&width, &height);
    for (i = 0; i < len; i++)
    {
        if (string[i] == '\n')
        {
            kernel_terminal_newline();
            continue;
        }
        kernel_draw_set_char(cursor_x, height - 1, color, string[i]);
        cursor_x++;
    }
}

void kernel_terminal_prints(char *string)
{
    kernel_terminal_prints_color(string, 0b00000111);
}