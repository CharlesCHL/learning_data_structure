#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "llist.h"

#define NAMESIZE	32

struct score_st
{
	int id;
	char name[NAMESIZE];
	int score;
};

static void print_s(const void* record)
{
	const struct score_st* r = record;

	printf("%d  %s  %d\n", r -> id, r -> name, r -> score);
}

static int id_cmp(const void* key, const void* record)
{
	const int* k = key;
	const struct score_st* r = record;
	
	return (*k - r -> id);	
}

static int name_cmp(const void* key, const void* record)
{
	const char* k = key;
	const struct score_st* r = record;
	
	return strcmp(k, r -> name);
}

int main()
{
	int i, ret;
	LLIST* handler;
	struct score_st tmp;

	handler = llist_create(sizeof(struct score_st));
	if(handler == NULL)
		exit(1);

	for(i = 0; i < 7; i++)
	{
		tmp.id = i;
		snprintf(tmp.name, NAMESIZE, "std%d", i);
		tmp.score = rand() % 100;
		ret = llist_insert(handler, &tmp, LLIST_BACKWARD);
		if(ret != 0)
			exit(2); 
	}
	
	llist_travel(handler, print_s);
	printf("\n\n");

	char *del_name = "std3";
	ret = llist_fetch(handler, del_name, name_cmp, &tmp);
	if(ret != 0)
		printf("delete failed!\n");
	llist_travel(handler, print_s);

#if 0	
	int id = 30;
	struct score_st* data;
	data = llist_find(handler, &id, id_cmp);	
	if(data == NULL)
		printf("Can't find!\n");
	else 
		print_s(data);

#endif

	llist_destroy(handler);

	exit(0);

}





