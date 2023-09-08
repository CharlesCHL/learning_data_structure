#include <stdio.h>
#include <stdlib.h>

#define NAMESIZE    32

struct score_st
{
    int id;
    char name[NAMESIZE];
    int math;
    int chinese;
};

struct node_st
{
	struct score_st data;
	struct node_st* next;
}

int list_insert(struct node_st*, struct score_st*);
void list_show(struct node_st*);
//list_delete();
//list_find();


int main()
{
	int i;
	
	for(i = 0; i < 7; i++)
	{
		list_insert();

	list_show();
	
	

    exit(0);
}




int list_insert(struct node_st*, struct score_st* data)
{
}

void list_show(struct node_st*)
{
}
/**
list_delete()
{
}

list_find()
{
}

*/





