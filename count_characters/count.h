#ifndef _COUNT_H
#define _COUNT_H

#define SUCCESS  666
#define FAILURE  555
#define WRONGCMD -1
#define ARRLEN   52

typedef struct comand_line {
    char cmd_name[3];
    int  cmd_num;
} cmd;

typedef struct characters {
    char c;
    int  num;
} char_num;

int get_cmd(int, char **);
void help(void);
int file(char_num *, char *);
int input(char_num*);
char_num *init_char(void);
void print_arr(char_num *);

#endif
