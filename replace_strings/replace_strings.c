// replace strings
#include <stdio.h>
#include <string.h>

#define MAXLEN 20

int main(int argc, char *argv[])
{
    FILE *fp, *ft;
    char word[MAXLEN];

    if (argc != 3)
    {
        puts("Error : check your command!");
        return 1;
    }

    if ((fp = fopen("filein.txt", "r")) == NULL)
    {
        puts("Error: check your file!");
        return 1;
    }
    ft = fopen("fileout.txt", "w+");

    while (fscanf(fp, "%s", word) != EOF)
    {
        if (!strncmp(word, argv[1], MAXLEN))
            fprintf(ft, "%s ", argv[2]);
        else
            fprintf(ft, "%s ", word);
    }

    fclose(fp);
    fclose(ft);
    return 0;
}
