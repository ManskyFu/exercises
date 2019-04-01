#include "choice.h"
#include <stdio.h>

int encrypt(char *filename, char *result)
{
    int ch;
    FILE * fp = fopen(filename, "r");
    FILE * ft = fopen(result, "w+");
    
    if (fp == NULL)
        return FAILURE;

    while ((ch = fgetc(fp)) != EOF)
    {
        ch = ch * 9 -1;
        if (ch > 880)
            ch = -ch;
        fprintf(ft, "%d ", ch);
    }
    fclose(fp);
    fclose(ft);

    return SUCCESS;
}
