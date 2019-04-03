#include "count.h"
#include <stdio.h>
#include <stdlib.h>

char_num *init_char(void)
{
    char_num *arr = (char_num*)malloc(sizeof(char_num) * ARRLEN);

    for (int m = 0, ch = 'A'; ch <= 'Z'; m++, ch++)
    {
        arr[m].c      = ch;
        arr[m].num    = 0;
        arr[m + 26].c = ch + 32;
        arr[m + 26].num = 0;
    }
    return arr;
}
