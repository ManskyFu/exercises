#include "count_words.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        puts("Error: check your command!");
        return 1;
    }
    FILE *fp;
    if ((fp = fopen(argv[1], "r+")) == NULL)
    {
        puts("Error: check your file!");
        return 1;
    }
    fclose(fp);

    char *str = get_new_file(argv[1]);
    struct cwords *p = save_words(str);
    count_times(p);
    sort_words(p);
    print_result(p);
    remove(str);

    return 0;
}
