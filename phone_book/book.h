#ifndef BOOK_H
#define BOOK_H

#define WRONGCMD '0'
#define SUCCESS  666
#define FAILURE  555

typedef struct phone_book {
    char name[30];
    char number[15];
    struct phone_book *next;
} pbook;

char get_cmd(char *);
int get_booklist(void);
int find_number(char *, char *);
int find_people(char *, char *);
int del_people(char *, pbook *);
int add_people(char *, pbook *);
int add_book(char *);
int del_book(char *);
int get_bookmember(char *);
void help_info(void);

#endif
