#include <stdio.h>
#include <stdlib.h>
#include "system.h"

int main(void)
{
    int choice;
    int login = log_in();
    if (login == WRONG_INFOR)
    {
        puts("Error: wrong username or password!");
        return 1;
    }
    st *p = get_data();
    
    while (1)
    {
        choice = print_menu();
    switch(choice)
    {
    case 1:
        add_data(p);
        break;
    case 2:
        del_data(p);
        break;
    case 3:
        search_data(p);
        break;
    case 4:
        print_data(p);
        getchar(), getchar();
        break;
    case 5:
        save_data(p);
        del_list(p);
        exit(0);
    }
    if (choice != 5)
    {
        sort_data(p);
        save_data(p);
    }
        }
    puts("Thanks for using!");

    return 0;
}
