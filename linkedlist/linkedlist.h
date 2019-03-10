#ifndef LINKEDLIST_H
#define LINKEDLIST_H 

struct list {
    char ch;
    struct list *next;
};

struct list *create_head_pointer(void);
void create_linked_list(struct list*);
void print_list(struct list*);

#endif
