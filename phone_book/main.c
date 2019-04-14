#include "book.h"
#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int exe_status;
    pbook tmp;
    tmp.next = NULL;

    char ch = get_cmd(argv[1]);
    if (ch == WRONGCMD)
        return 1;

    switch (ch)
    {
    case 'N':                   // add a new book
        if (argc != 3)
        {
            puts("Error: check your command!");
            return 1;
        }
        exe_status = add_book(argv[2]);
        break;
    case 'n':                   // add a new people 
        if (argc != 5)
        {
            puts("Error: check your command!");
            return 1;
        }
        strncpy(tmp.name, argv[3], 30);
        strncpy(tmp.number, argv[4], 15);
        exe_status = add_people(argv[2], &tmp); // program cmd book_name people number
        break;
    case 'D':                   // delete a book
        if (argc != 3)     // porgram cmd book_name 
        {
            puts("Error: check your command!");
            return 1;
        }
        exe_status = del_book(argv[2]);
        break;
    case 'd':                   // delete a people
        if (argc != 5)           // program cmd book_name people number 
        {
            puts("Error: check your command!");
            return 1;
        }
        strncpy(tmp.name, argv[3], 30);
        strncpy(tmp.number, argv[4], 15);
        exe_status = del_people(argv[2], &tmp);
        break;
    case 'F':                   // find people according to number
        if (argc != 4)          // program cmd book_name number
        {
            puts("Error: check your command!");
            return 1;
        }
        exe_status = find_number(argv[2], argv[3]);
        break;
    case 'f':                   // find a number according to people
        if (argc != 4)
        {
            puts("Error: check your command!");
            return 1;
        }
        exe_status = find_people(argv[2], argv[3]);
        break;
    case 'l':
        if (argc != 2)
        {
            puts("Error: check your command!");
            return 1;
        }
        exe_status = get_booklist();
        break;
    case 'L':
        if (argc != 3)
        {
            puts("Error: check your command!");
            return 1;
        }
        exe_status = get_bookmember(argv[2]);
        break;
    case 'h':
        exe_status = SUCCESS;
        help_info();
        return 0;
    }
    if (exe_status == FAILURE)
        return 1;

    return 0;
}
