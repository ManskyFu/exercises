// The program is to count how many times every character appears
// in a file or input.
#include <stdio.h>
#include <malloc.h>
#include "count.h"

int main(int argc, char *argv[])
{
    int exe_condition = SUCCESS;
    char_num *arr = init_char();

    switch (get_cmd(argc, argv))
    {
    case 0:
        help();
        free(arr);
        return 0;
    case 1:
        exe_condition = file(arr, argv[2]);
        break;
    case 2:
        exe_condition = input(arr);
        break;
    default:
        help();
        exe_condition = FAILURE;
    }
    if (exe_condition == FAILURE)
    {
        puts("Error: check your command or file!");
        free(arr);
        return 1;
    }
    else
        print_arr(arr);

    free(arr);
    return 0;
}
