#ifndef SYSTEM_H
#define SYSTEM_H

#define RIGHT_INFOR 0
#define WRONG_INFOR 1

typedef struct student {
    char name[20];
    float score;
    struct student *next;
} st;

st *get_data(void);       // get data from "data.txt"
int log_in(void);       // judge if it's user 
int print_menu(void);     // menu to choose 
void del_data(st *);      // delete one student's information
void add_data(st *);      // add one student's information
void search_data(st *);   // search one student's information
void sort_data(st *);     // sort information according to grades
void print_data(st *);    // print students'information
void save_data(st *);     // save information
void del_list(st *);

#endif
