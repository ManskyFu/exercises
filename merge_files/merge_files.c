/*
 * This program is to emerge two files.
 * You should put in commands like    merge_files file1 file2 destination
 */ 
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        puts("Error: check your command!");
        return 1;
    }

    char ch;
    FILE *fp = fopen(argv[1], "r");
    FILE *ft = fopen(argv[2], "r");
    FILE *fd = fopen(argv[3], "w+");

    if (fp == NULL || ft == NULL)
    {
        puts("Error: check your files!");
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF)
    {
        fputc(ch, fd);
    }

    while ((ch = fgetc(ft)) != EOF)
    {
        fputc(ch, fd);
    }

    fclose(fp);
    fclose(ft);
    fclose(fd);

    return 0;
}
