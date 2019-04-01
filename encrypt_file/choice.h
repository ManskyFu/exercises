#ifndef _CHOICE_H
#define _CHOICE_H

#define SUCCESS 666
#define FAILURE 555
#define NONCMD  -1
typedef struct Command {
    char cmd_name[3];
    int  cmd_num;
} CMD;


int cmd_line(char *, int); // choose command 
int encrypt(char *, char *);   // encrypt files 
int decrypt(char *, char *);   // decrypt files 
void help(void);

#endif
