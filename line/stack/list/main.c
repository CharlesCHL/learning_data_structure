#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

#define NAMESIZE	32

struct score_st
{
	int id;
	char name[NAMESIZE];
	int score;
};

static void print_s(void* record)
{
	struct score_st* r = record;
	printf("%d\t%s\t%d\n", r->id, r->name, r->score);
}

int main()
{

	STACK* st;
	struct score_st tmp;
	int i, ret;

	st = stack_create(sizeof(struct score_st));	
	if(st == NULL)
		exit(1);

	for(i = 0; i < 7; i++)
	{
		tmp.id = i;
		snprintf(tmp.name, NAMESIZE, "stu%d", i);
		tmp.score = rand() % 100;
		
		if(stack_push(st, &tmp))
			exit(2);
	}

	while(1)
	{
		ret = stack_pop(st, &tmp);
		if(ret != 0)
			break;
		print_s(&tmp);
	}

	stack_destroy(st);

	exit(0);
}



