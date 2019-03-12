#include <stdio.h>
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        puts("Error: check your command!");
        return 1;
    }
    FILE *fp, *ft;
    if ((fp = fopen(argv[1], "r+")) == NULL)
    {
        puts("Error: check your file!");
        return 1;
    }
    ft = fopen("tmp", "w+");
    char ch, str[50];
    int m = 0;

    while ((ch = fgetc(fp)) != EOF)
    {
        if (ch >= 'a' && ch <= 'z')
            fputc(ch, ft);
        else if (ch >= 'A' && ch <= 'Z')
            fputc(ch+32, ft);
        else
            fputc(' ', ft);
    }
    fclose(fp);
    fclose(ft);

    ft = fopen("tmp", "r+");
    while (fscanf(ft, "%s", str) != EOF)
    {
        printf("%s ", str);
    }
    fclose(ft);
    remove("tmp");

    return 0;
}
