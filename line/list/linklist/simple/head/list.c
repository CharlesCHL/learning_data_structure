#include <stdio.h>
#include <stdlib.h>
#include "list.h"


linknode* list_create()
{
    linknode* me;
    me = malloc(sizeof(*me));
    if(me == NULL)
    {
        return NULL;
    }
    me -> next = NULL;
    return me;
}

int list_insert_at(linknode* me, int i, datatype* data)
{
    if(i < 0)
        return -1;
    int j;
    linknode* p = me;
    for(j = 0; j < i; j++) 
    {
        p = p -> next;
    }
    if(p == NULL)
        return -2;
    linknode* node = malloc(sizeof(*node));
    if(node == NULL)
        return -3;
    node -> data = *data;
    node -> next = p -> next;
    p -> next = node;
    
    return 0;
}

int list_head_insert(linknode* me, datatype* data)
{
    list_insert_at(me, 0, data);
}

int list_tail_insert(linknode* me, datatype* data)
{
    list_insert_at(me, list_getnum(me), data);
}

int list_order_insert(linknode* me, datatype* data)
{
    linknode* p = me;
    linknode* q;

    while(p -> next != NULL && p -> next -> data < *data)
        p = p -> next;
    q = malloc(sizeof(*q));
    if(q == NULL)
        return -1;
    q -> data = *data;
    q -> next = p -> next;
    p -> next = q;
    
    return 0;
}

int list_delete_st(linknode* me, int i, datatype* data)
{
	int j = 0;
	linknode* p = me;
    linknode* q;

    *data = -1;

	if(i < 0)
		return -1;

	while(j < i && p -> next != NULL) {
		p = p -> next;
		j++;
	}

	if(p -> next != NULL)
	{
        q = p -> next;
        p -> next = q -> next;
        *data = q -> data;
        free(q);
	}

	return 0;
}

int list_delete(linknode* me, datatype* data)
{
    linknode* p = me;
    linknode* q;

    while(p -> next != NULL && p -> next -> data != *data)
        p = p -> next;
    if(p -> next == NULL)
        return -1;
    else
    {
        q = p -> next;
        p -> next = q -> next;
        free(q);
        q = NULL;
    }

    return 0;
}

int list_getnum(linknode* me)
{
    int i = 0;
    linknode* p = me;
    while(p -> next != NULL)
    {
        i++;
        p = p -> next;
    }

    return i;
}

int list_isempty(linknode* me)
{
    if(me -> next == NULL)
        return 1;
    return 0;
}

void list_display(linknode* me)
{
    int i = 0;
    linknode* p = me;
    if(list_isempty(me))
        return ;
    while(p -> next != NULL) 
    {
        if(i % 5 == 0) 
            printf("\n");
        printf("%d\t", p -> next -> data);
        i++;
        p = p -> next;
    }
    printf("\n\n");

    return ;
}

void list_destroy(linknode* me)
{
    linknode* p = me;
    linknode* q = me;
    while(p != NULL)
    {
        q = q -> next;
        free(p);
        p = q;
    }

    return ;
}





