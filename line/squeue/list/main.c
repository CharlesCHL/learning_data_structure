

#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

#define NAMESIZE	32

struct score_st
{
	int id;
	char name[NAMESIZE];
	int score;
};

static void print_s(struct score_st* tmp)
{
	printf("%d\t%s\t%d\n", tmp->id, tmp->name, tmp->score);
}

int main()
{
	QUEUE* qu;
	int i, ret;

	struct score_st tmp;
	qu = queue_create(sizeof(struct score_st));
	if(qu == NULL)
		exit(1);
	
	for(i = 0; i < 7; i++)
	{
		tmp.id = i;
		snprintf(tmp.name, NAMESIZE, "STU%d", i);
		tmp.score = rand() % 100;
		if(queue_en(qu, &tmp) != 0)
			break;
	}
	

	while(1)
	{
		ret = queue_de(qu, &tmp);	

		if(ret != 0)
			break;	
		print_s(&tmp);
	}

	queue_destroy(qu);

	exit(0);


}





