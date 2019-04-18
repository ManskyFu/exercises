#include <stdio.h>

int main(int argc, char *argv[]){
    if (argc != 2)
        return 1;

    char ch;
    sscanf(argv[1], "%c", &ch);
    for (int c = ch; c >= 'A'; c--){
        for (int m = c; m >= 'A'; m--)
            putchar(c);
        putchar('\n');
    }

    return 0;
}
