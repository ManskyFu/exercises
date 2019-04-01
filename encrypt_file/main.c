/*
 * Simple program to encrypt and decrypt files wrriten in English.
 */
#include <stdio.h>
#include "choice.h"
#include <string.h>

int main(int argc, char *argv[])
{
    int exe_condition;

    if (argc != 4)
    {
        if (argc == 2 && strncmp(argv[1], "-h", 3)== 0)
        {
            help();
            return 0;
        }
        puts("Error: check your command!");
        return 1;
    }

    switch (cmd_line(argv[1], 3))
    {
    case 1:
        exe_condition = encrypt(argv[2], argv[3]);
        break;
    case 2:
        exe_condition = decrypt(argv[2], argv[3]);
        break;
    case 3:
        exe_condition = SUCCESS;
        help();
        break;
    default:
        help();
        return 1;
    }

    if (exe_condition == FAILURE)
    {
        puts("Error occurred!");
        return 1;
    }


    return 0;
}
