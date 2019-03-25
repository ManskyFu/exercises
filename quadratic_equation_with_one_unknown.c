// This is a command line version.
#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        puts("Error : check your command!");
        return 1;
    }

    double a, b, c, delta, x1, x2;

    sscanf(argv[1], "%lf", &a);
    sscanf(argv[2], "%lf", &b);
    sscanf(argv[3], "%lf", &c);

    if (!a)
    {
        puts("Error : check the coefficient of square term!");
        return 1;
    }

    delta = b * b - 4 * a * c;

    if (delta < 0)
    {
        puts("Its solutions are not real number!");
        return 0;
    }
    x1 = (-b + sqrt(delta)) / (2 * a);
    x2 = (-b - sqrt(delta)) / (2 * a);
    if (!delta)
        printf("It has two equal solutions, and they are %lf .\n", x1);
    else
        printf("It has two different solutions, and they are %lf and %lf .\n", x1, x2);

    return 0;
}
