#include <stdio.h>
#include <stdlib.h>

#include "sqstack.h"

sqstack* st_create(void)
{
	sqstack* st;

	st = malloc(sizeof(*malloc));
	if(st == NULL)
		return 0;
	
	st->top = -1;	
	return st;	
}

int st_isempty(sqstack* st)
{
	return (st->top == -1);
}

int st_push(sqstack* st, datatype* data)
{
	if(st->top == (MAXSIZE - 1))
		return -1;
	st->data[++st->top] = *data;
	return 0; 
}

int st_pop(sqstack* st, datatype* data)
{
	if(st_isempty(st))
		return -1;
	*data = *(st->data + (st->top--));
	return 0;
}

int st_top(sqstack* st, datatype* data)
{
	if(st_isempty(st))
		return -1;
	*data = *(st->data + st->top);
	return 0;
}

void st_travel(sqstack* st)
{
	if(st_isempty(st))
		return ;
	int i;
	for(i = 0; i <= st->top; i++)
	{
		printf("%d  ", *(st->data + i));
	}
	printf("\n");
}

void st_destroy(sqstack* st)
{
	free(st);
}





