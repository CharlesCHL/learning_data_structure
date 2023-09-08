#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main() 
{

    int arr[] = {3, 65, 34, -1, 87, 63};
    int i, err;
    linknode* head_1;
    head_1 = list_create();

    if(head_1 == NULL)
        exit(1);
    for(i = 0; i < sizeof(arr) / sizeof(*arr); i++)
    {
        if(list_order_insert(head_1, arr + i) != 0)
            exit(2);
    }

    printf("%d\n", list_getnum(head_1));

    list_display(head_1);

    // list_delete(head_1, arr + 2);
    datatype value;
    
    err = list_delete_st(head_1, 2, &value);

    if(err)
        exit(3);
    else
        printf("delete:%d\n", value);

    list_display(head_1);
    
    list_destroy(head_1);

    exit(0);

}









