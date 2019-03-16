#include <stdio.h>
#include <stdlib.h>

typedef struct Stack{
    int data;
    struct Stack *next;
} stack;

int main(void)
{
    char ch;
    
    // create stack
    stack *phead = (stack*)malloc(sizeof(stack));
    phead->next = NULL;
    stack *prev, *rear;

    while (1)
    {
        prev = phead;
        rear = (stack*)malloc(sizeof(stack));
        if (rear == NULL)
        {
            puts("Error: no more memory!");
            return 1;
        }

        // input data 
        printf("Please enter data:   ");
        scanf("%d", &rear->data);
        printf("Continue! (y/n):  ");
        getchar(), scanf("%c", &ch);
        
        rear->next = prev->next;
        prev->next = rear;

        if (ch == 'n' || ch == 'N')
            break;
    }

    // print data 
    rear = phead->next;
    while (rear)
    {
        printf("%d ", rear->data);
        rear = rear->next;
    }

    // free stack 
    prev = phead;
    rear = phead->next;
    while (rear)
    {
        free(prev);
        prev = rear;
        rear = rear->next;
    }

    return 0;
}
