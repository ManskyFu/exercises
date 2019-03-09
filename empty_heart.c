#include <stdio.h>
#include <stdlib.h>
 
void empty_heart(int **, int , int);
void print(int **, int, int);
void print_heart(int**, int, int);
int **array(int, int);
 
int main(void)
{    
    int **arr = array(14, 14);
    empty_heart(arr, 14, 14);
    print(arr, 14, 14);
    print_heart(arr, 14, 14);
    return 0;
}
int **array(int x, int y)
{
    int **arr = (int**)calloc(x, sizeof(int *));
    for (int k = 0; k < x; ++k)
        arr[k] = (int*)calloc(y, sizeof(int));
    return arr;
}
void empty_heart(int **arr, int x, int y)
{
    int m, n;
    for (m = 3, n = 0; m >=0 && n < 7; ++n)
    {
        if (n < 3)
            arr[m--][n] = 1;
        else if (n >= 3)
            arr[m++][n] = 1;
    }
    for (m = 3, n = 7; m >= 0 && n < 14 && n >= 7; ++n)
    {
        if (n < 10)
            arr[m--][n] = 1;
        else if (n >= 10)
            arr[m++][n] = 1;
    }
    for (m = 4, n = 0; m < 7; ++m)
    {
        arr[m][0] = 1;
        arr[m][13] = 1;
    }
    for (m = 7, n = 0; n < 14; ++n)
    {
        if (n < 7)
            arr[m++][n] = 1;
        else if (n >= 7)
            arr[--m][n] = 1;
    }
}
void print(int **arr, int x, int y)
{
    for (int m = 0; m < x; ++m)
    {
        for (int n = 0; n < y; ++n)
            printf("%d ", arr[m][n]);
        putchar('\n');
     }
    putchar('\n');
}
void print_heart(int **arr, int x, int y)
{
    for (int m = 0; m < x; ++m)
    {
        for (int n = 0; n < y; ++n)
            if (arr[m][n] == 1)
                printf("%d ", arr[m][n]);
            else
                printf("  ");
 
        putchar('\n');
    }
    putchar('\n');
}

