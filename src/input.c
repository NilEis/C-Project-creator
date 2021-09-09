#include "include/input.h"
#include <stdio.h>

int get_string(char *buffer, int size)
{
    char in = 0;
    while (size--)
    {
        in = getchar();
        if (in == 0x0A)
        {
            break;
        }
        switch(in){
            case ' ':
                in = '_';
            break;
        }
        *(buffer++) = in;
    }
    *buffer = '\0';
    return 0;
}