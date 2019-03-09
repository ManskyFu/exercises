//Delete some character from certain file.
//
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        puts("Please enter the right command.");
        return 1;
    }

    FILE *fp, *ftp;
    char ch, tch;

    if ((fp = fopen(argv[1], "r+")) == NULL)
    {
        puts("Please check the file you want to change.");
        return 1;
    }
    ftp = fopen("tmp", "w+");

    printf("Please enter the character you want to delete:\n");
    scanf(" %c", &tch);
    while ((ch = fgetc(fp)) != EOF)
    {
        if (ch != tch)
            fputc(ch, ftp);
    }
    fclose(fp);
    fclose(ftp);
    remove(argv[1]);
    rename("tmp", argv[1]);


    return 0;
}
