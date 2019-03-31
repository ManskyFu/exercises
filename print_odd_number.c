/*
 * print odd numbers between two number.
 */ 
#include <stdio.h>

int main(int argc, char *argv[])
{
    int min, max;

    if (argc != 3)
    {
        puts("Error : check your command!");
        return 1;
    }
    sscanf(argv[1], "%d", &min);
    sscanf(argv[2], "%d", &max);

    if (min < 0 || max < 0 || min >= max)
    {
        puts("Error: check your data!");
        return 1;
    }

    for (int cnt = 0, m = min; m <= max; ++m)
    {
        if (m % 2 != 0)
        {
            printf("%d ", m);
            cnt++;
        }
        if (cnt % 10 == 0)
            putchar('\n');
    }

    return 0;
}
