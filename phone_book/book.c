#include "book.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char get_cmd(char *cmd)
{
    char c, ch;

    sscanf(cmd, "%c%c", &c, &ch);

    if (c != '-')
        return WRONGCMD;

    switch (ch)
    {
    case 'N':                   // add a new book 
    case 'n':                   // add a new people 
    case 'D':                   // delete a book
    case 'd':                   // delete a people 
    case 'F':                   // find a book 
    case 'f':                   // find a people
    case 'l':                   // look list
    case 'L':                   // look members in one book
    case 'h':                   // help infomation 
        return ch;
    }
    return WRONGCMD;
}
int get_booklist(void)
{
    FILE *fp = fopen("booklist", "r");
    char listname[30];

    if (fp == NULL)
        return FAILURE;

    while (fscanf(fp, "%30s", listname) != EOF)
        puts(listname);

    return SUCCESS;
}
int find_number(char *listname, char *number)
{
    char tmpname[30], tmpnum[15];
    pbook t;
    FILE *fp = fopen(listname, "r");
    if (fp == NULL)
        return FAILURE;

    while (fscanf(fp, "%30s %15s", tmpname, tmpnum) != EOF)
        if (!strncmp(tmpnum, number, 15))
        {
            strncpy(t.name, tmpname, 30);
            strncpy(t.number, tmpnum, 15);
            t.next = NULL;
            break;
        }
    printf("People: %s\n", t.name);
    fclose(fp);
    return SUCCESS;
}
int find_people(char *listname, char *people)
{
    char tmpname[30], tmpnum[15];
    pbook t;
    FILE *fp = fopen(listname, "r");
    if (fp == NULL)
        return FAILURE;

    while (fscanf(fp, "%30s %15s", tmpname, tmpnum) != EOF)
        if (!strncmp(tmpname, people, 15))
        {
            strncpy(t.name, tmpname, 30);
            strncpy(t.number, tmpnum, 15);
            t.next = NULL;
            break;
        }
    printf("Number: %s\n", t.number);
    fclose(fp);
    return SUCCESS;
}
int del_people(char *book_name, pbook *pb)
{
    char tmpname[30], tmpnum[15];

    FILE *fp = fopen(book_name, "r");
    FILE *ft = fopen("tmp", "w+");

    if (fp == NULL || ft == NULL)
        return FAILURE;

    while (fscanf(fp, "%30s %15s", tmpname, tmpnum) != EOF)
        if (strncmp(tmpname, pb->name, 30) || strncmp(tmpnum, pb->number, 15))
            fprintf(ft, "%s %s ", tmpname, tmpnum);

    fclose(ft);
    fclose(fp);
    remove(book_name);
    rename("tmp", book_name);

    return SUCCESS;
}
int add_people(char *book_name, pbook *pb)
{
    FILE *fp = fopen(book_name, "a");
    if (fp == NULL)
        return FAILURE;

    fprintf(fp, "%s %s ", pb->name, pb->number);

    fclose(fp);
    return SUCCESS;
}
int add_book(char *book_name)
{
    FILE *fp = fopen(book_name, "w+");
    FILE *ft = fopen("booklist", "a");

    fprintf(ft, "%s ", book_name);

    fclose(ft);
    fclose(fp);

    return SUCCESS;
}
int del_book(char *book_name)
{
    char tmp[30];
    FILE *fp = fopen("booklist", "r");
    FILE *ft = fopen("tbook", "w+");

    if (fp == NULL)
        return FAILURE;

    while (fscanf(fp, "%30s", tmp) != EOF)
        if (strncmp(book_name, tmp, 30))
            fprintf(ft, "%s ", tmp);

    fclose(ft);
    fclose(fp);
    remove("booklist");
    rename("tbook", "booklist");
    remove(book_name);

    return SUCCESS;
}
int get_bookmember(char *book_name)
{
    FILE *fp = fopen(book_name, "r");
    pbook tmp;
    tmp.next = NULL;

    if (fp == NULL)
        return FAILURE;

    printf("%30s\t%15s\n\n", "People", "Phone Number");
    while (fscanf(fp, "%30s %15s", tmp.name, tmp.number) != EOF)
        printf("%30s \t%15s\n", tmp.name, tmp.number);

    return SUCCESS;
}
void help_info(void)
{
    puts("      Command                     Operations");
    puts("  -h                          help information");
    puts("  -N book_name                add a new book");
    puts("  -n book_name people number  add a new people");
    puts("  -D book_name                delete a book");
    puts("  -d book_name people number  delete a people");
    puts("  -F book_name number         find a person");
    puts("  -f book_name people         find a number");
    puts("  -l                          get all book names");
    puts("  -L book_name                get all members in one book");
}
