#include "book.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char get_cmd(char *cmd)
{
    char c, ch;

    sscanf(cmd, "%c%c", &c, &ch);

    if (c != '-')
    {
        puts("Error: check your command!");
        return WRONGCMD;
    }
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
int write_booklist(char *listname)
{
    char listname2[30];
    FILE *fp = fopen("booklist", "r");

    if (fp == NULL)
        return FAILURE;

    while (fscanf(fp, "%30s", listname2) != EOF)
        if (strncmp(listname, listname2, 30))
            return WRONGCMD;
    fclose(fp);
    fp = fopen("booklist", "w");
    fprintf(fp, "%s ", listname);

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
            fprintf(ft, "%s %s ", pb->name, pb->number);

    fclose(ft);
    fclose(fp);
    remove(book_name);
    rename("tmp", book_name);

    return SUCCESS;
}
int add_people(char *book_name, pbook *pb)
{
    char tmpname[30], tmpnum[15];

    FILE *fp = fopen(book_name, "a");
    if (fp == NULL)
        return FAILURE;

    while (fscanf(fp, "%30s %15s", tmpname, tmpnum) != EOF)
        if (strncmp(pb->name, tmpname, 30) || strncmp(pb->number, tmpnum, 15))
            fprintf(fp, "%s %s ", tmpname, tmpnum);
        else
        {
            fclose(fp);
            return FAILURE;
        }

    fclose(fp);
    return SUCCESS;
}
int add_book(char *book_name)
{
    FILE *fp = fopen(book_name, "r");
    FILE *ft = fopen("booklist", "r");

    if (fp != NULL)
    {
        fclose(fp);
        return FAILURE;
    }
    fclose(fp);
    fp = fopen(book_name, "w+");
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

    return SUCCESS;
}
int get_bookmember(char *book_name)
{
    FILE *fp = fopen(book_name, "r");
    pbook tmp;
    tmp.next = NULL;

    if (fp == NULL)
        return FAILURE;

    while (fscanf(fp, "%30s %15s", tmp.name, tmp.number) != EOF)
        printf("%s  %s\n", tmp.name, tmp.number);

    return SUCCESS;
}
