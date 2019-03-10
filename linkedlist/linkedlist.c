#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

struct list *create_head_pointer(void){
    struct list *phead = (struct list*)malloc(sizeof(struct list));
    phead->next = NULL;
    return phead;
}

void create_linked_list(struct list *phead){
    struct list *prev = phead, *rear;
    
    for (char c = 'A'; c <= 'Z'; ++c){
        rear = (struct list*)malloc(sizeof(struct list));
        rear->next = NULL;
        rear->ch = c;
        prev->next = rear;
        prev = rear;
    }
}
void print_list(struct list *phead){
    struct list *rear = phead->next;

    while (rear){
        printf("%c ", rear->ch);
        rear = rear->next;
    }
    putchar('\n');
}
