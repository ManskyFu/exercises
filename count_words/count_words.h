#ifndef COUNT_WORDS_H
#define COUNT_WORDS_H

#include <stdio.h>
struct cwords {
    char word[50];
    int times;
    struct cwords *next;
};

char* get_new_file(char*);
struct cwords *save_words(char *);
void count_times(struct cwords*);
void sort_words(struct cwords*);
void print_result(struct cwords*);

#endif
