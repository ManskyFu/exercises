#include "linkedlist.h"
#include <stdio.h>

int main(void){
    struct list *p = create_head_pointer();
    create_linked_list(p);
    print_list(p);

    return 0;
}
