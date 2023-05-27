#include "std.h"

unsigned int std_strlen(char *string)
{
    int len = 0;
    while (string[len] != 0)
    {
        len++;
    }
    return len;
}