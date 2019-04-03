#include "count.h"
#include <stdio.h>

void print_arr(char_num *arr)
{
    for (int m = 0; m < ARRLEN; m++)
    {
        printf("%c : %d   ", arr[m].c, arr[m].num);
        if ((m+1) % 5 == 0)
            putchar('\n');
    }
}
