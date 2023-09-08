#include <stdio.h>
#include <stdlib.h>
#include "sqlist.h"

sqlist* sqlist_create_1()
{
		sqlist* me;
		me = malloc(sizeof(*me));	
		if(me == NULL)
				return NULL;
		me -> last = -1;
		return me;
}

void sqlist_create_2(sqlist** ptr)
{
		*ptr = malloc(sizeof(**ptr));
		if(*ptr == NULL)
				return ;
		(*ptr) -> last = -1;
		return ;
}

int sqlist_insert(sqlist* me, int i, datatype* data)
{
		int j;
		if(me -> last == DATASIZE - 1)
				return -1;
		if(i < 0 || i > (me -> last + 1))
				return -2;

		for(j = me -> last; j >= i; j--) 
		{
				*((me -> data) + j + 1) = *((me -> data) + j);
		}
		*((me -> data) + i) = *data;
		(me -> last)++;

		return 0;
}

int sqlist_add(sqlist* me, datatype* data)
{
		if(sqlist_isfull(me) == 1)
		{
				printf("Your list is full!\n");
				return -1;
		}
		sqlist_insert(me, (me -> last) + 1, data);
		
		return 0;
}

int sqlist_delete(sqlist* me, int i)
{
		int j;

		if(i < 0 || i > (me -> last))
				return -1;

		for(j = i; j < (me -> last); j++) 
		{
				*((me -> data) + j) = *((me -> data) + j + 1);
		}
		*((me -> data) + (me -> last)) = 0;

		(me -> last)--;

		return 0;
}

int sqlist_find(sqlist* me, datatype* data)
{
		int j;

		if(sqlist_isempty(me) == 1)
				return -1;

		for(j = 0; j <= (me -> last); j++) 
				if(*((me -> data) + j) == *data) 
						return j;
		
		return -2;
}

datatype* sqlist_getvalue(sqlist* me, int i)
{
		if(i > (me -> last) || i < 0)
				return NULL;
		return (me -> data) + i;
}

int sqlist_isfull(sqlist* me) 
{
		if((me -> last) == DATASIZE - 1)
				return 1;
		return 0;
}

int sqlist_isempty(sqlist* me)
{
		if((me -> last) == -1)
				return 1;
		return 0;
}

int sqlist_setempty(sqlist* me)
{
		me -> last = -1;
		return 0;
}

int sqlist_getnum(sqlist* me)
{
		return ((me -> last) + 1);
}

int sqlist_union(sqlist* list1, sqlist* list2)
{
		int i;
		for(i = 0; i <= list2 -> last; i++) 
		{
				if(sqlist_find(list1, (list2 -> data) + i) < 0)
				{
						sqlist_add(list1, (list2 -> data) + i); 
				}
		}
		return 1;
}

void sqlist_display(sqlist*me)
{
		int j;
		for(j = 0; j <= me -> last; j++) 
		{
				printf("%d\t", *((me -> data) + j));
				if ((j + 1) % 5 == 0)
						printf("\n");
		}
		printf("\n");

		return ;
}

int sqlist_destroy(sqlist* me)
{
		free(me);
		return 0;
}





