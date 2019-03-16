#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char ch;
    int len, tail, *arr;  
    // create a stack
    do
    {
        puts("Please enter the length of stack:");
        scanf("%d", &len);
        if (len <= 0)
        {
            puts("Error: please enter a positive number!");
        }
    } while (len <= 0);
    arr = (int*)malloc(sizeof(int) * len);

    // input data
    tail = 0;
    while (1)
    {
        printf("Please enter data:   ");
        scanf("%d", arr + tail);
        tail++;
        if (tail == len)
        {
            puts("Stack is full!");
            break;
        }
        printf("Continue? (y/n)");
        getchar(), scanf("%c", &ch);
        if (ch == 'n' || ch == 'N')
            break;
    }

    // print data
    puts("There are data in the stack:");
    tail--;
    while (tail >= 0)
    {
        printf("%d ", arr[tail]);
        tail--;
    }

    // destroy stack
    free(arr);

    return 0;
}
