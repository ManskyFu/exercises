#include "choice.h"
#include <stdio.h>

int decrypt(char *filename, char *result)
{
    int ch;
    FILE *fp = fopen(filename, "r");
    FILE *ft = fopen(result, "w+");

    if (fp == NULL)
        return FAILURE;

    while (fscanf(fp, "%d", &ch) != EOF)
    {
        if (ch < 0)
            ch = -ch;
        ch = (ch + 1) / 9;

        fprintf(ft, "%c", ch);
    }
    fclose(fp);
    fclose(ft);

    return SUCCESS;
}
