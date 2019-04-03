#include "count.h"
#include <stdio.h>

int input(char_num* arr)
{
    char ch;
    puts("Please enter a string:");

    while ((ch = getchar()) != '\n')
    {
        for (int m = 0; m < ARRLEN; ++m)
        {
            if (arr[m].c == ch)
                arr[m].num++;
        }
    }
    return SUCCESS;
}
