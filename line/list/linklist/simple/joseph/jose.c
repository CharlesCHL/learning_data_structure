#include <stdio.h>
#include <stdlib.h>

#define JOSE_NR		8

struct node_st
{
	int data;
	struct node_st* next;
};

struct node_st* jose_create(int);
void jose_show(struct node_st*);
void jose_kill(struct node_st**, int);

int main()
{
	int n, m;
	n = 3;
	m = 1;

	struct node_st* list;
	list = jose_create(JOSE_NR);
	if(list == NULL)
		exit(1);

	jose_show(list);

	jose_kill(&list, n);

	jose_show(list);

	exit(0);

}



struct node_st* jose_create(int n)
{
	struct node_st *me, *newnode, *p;
	int i = 1;
	me = malloc(sizeof(*me));
	if(me == NULL)
		return NULL;
	me -> data = i++;
	me -> next = me;
	p = me;

	for(i; i <= n; i++)
	{
		newnode = malloc(sizeof(*newnode));
		if(newnode == NULL)
			return NULL;
		newnode -> data = i;
		newnode -> next = me;
		p -> next = newnode;
		p = p -> next;
	}

	return me;
}

void jose_show(struct node_st* me)
{
	struct node_st* list = me;
	do {
		printf("%d  ", list -> data);
		list = list -> next;
	} while(list != me);
	printf("\n");
}

void jose_kill(struct node_st** me, int n)
{
	struct node_st* p = *me;
	struct node_st* q;
	int i = 1;
	while(p != p -> next)
	{
		if(i == n)
		{
			q -> next = p -> next;
			printf("%d  ", p -> data);
			free(p);
			p = q -> next;
			i = 1;
		}
		else
		{
			i++;
			q = p;
			p = p -> next;
		}	
	}
	printf("\n");
	*me = p;
}



