
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

#define NAMESIZE	32


struct score_st
{
	int id;
	char name[NAMESIZE];
	int score;
	struct list_head node;
}

int main()
{
	int i;
	struct score_st* datap;
	LIST_HEAD(head);
	
	for(i = 0; i < 7; i++)
	{
		datap = malloc(sizeof(*datap));
		if(datap == NULL)
			exit(1);

		datap -> id = i;
		snprintf(datap -> name, NAMESIZE, "stu%d", i);
		datap -> score = rand() % 100;

	}	


	exit(0);

}











