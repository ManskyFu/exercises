#include "count.h"
#include <stdio.h>

int file(char_num *arr, char *filename)
{
    char ch;
    FILE * fp = fopen(filename, "r");
    if (fp == NULL)
        return FAILURE;

    while ((ch = fgetc(fp)) != EOF)
    {
        for (int m = 0; m < ARRLEN; m++)
        {
            if (arr[m].c == ch)
                arr[m].num ++;
        }
    }
    fclose(fp);

    return SUCCESS;
}
