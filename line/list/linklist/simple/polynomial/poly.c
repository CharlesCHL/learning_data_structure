#include <stdio.h>
#include <stdlib.h>

struct node_st
{
	int coef;
	int exp;
	struct node_st* next;
};

struct node_st* poly_create(int[][2], int);
void poly_show(struct node_st*);
void poly_union(struct node_st*, struct node_st*);


int main()

{

	int arr1[][2] = {{5, 0}, {2, 1}, {8, 8}, {3, 16}};
	int arr2[][2] = {{6, 1}, {16, 6}, {-8, 8}};
	struct node_st *p1, *p2;

	p1 = poly_create(arr1, 4);
	if(p1 == NULL)
		exit(1);
	p2 = poly_create(arr2, 3);
	if(p2 == NULL)
		exit(2);
	
	poly_show(p1);
	poly_show(p2);

	poly_union(p1, p2);
	poly_show(p1);

	exit(0);

}


struct node_st* poly_create(int arr[][2], int n)
{
	int i;
	struct node_st* me;
	struct node_st* newnode;
	struct node_st* p;

	me = malloc(sizeof(*me));
	if(me == NULL)
		return NULL;
	me -> next = NULL;
	p = me;

	for(i = 0; i < n; i++)
	{
		newnode = malloc(sizeof(*newnode));
		if(newnode == NULL)
			return NULL;
		newnode -> coef = *(*(arr + i));
		newnode -> exp = arr[i][1];
		newnode -> next = NULL;
		p -> next = newnode;
		p = p -> next;

	}	
	return me;
}


void poly_show(struct node_st* me)
{
	struct node_st* cur;
	for(cur = me -> next; cur != NULL; cur = cur -> next)
	{
		printf("(%d\t%d)\n", cur -> coef, cur -> exp);
	}
	printf("\n");
}


void poly_union(struct node_st* list1, struct node_st* list2)
{
	struct node_st *p1, *p2, *q;
	p1 = list1 -> next;
	p2 = list2 -> next;
	q = list1;
	
	while(p1 != NULL && p2 != NULL)
	{
		if(p1 -> exp < p2 -> exp)
		{
			q -> next = p1;
			q = q -> next;
			p1 = p1 -> next;
		}
		else if(p1 -> exp > p2 -> exp)
		{
			q -> next = p2;
			q = q -> next;
			p2 = p2 -> next;
		}
		else
		{
			p1 -> coef += p2 -> coef;
			if(p1 -> coef != 0)
			{
				q -> next = p1;
				q = q -> next;
			}
			p1 = p1 -> next;
			p2 = p2 -> next;
		}
	}

	if(p1 == NULL)
		q -> next = p2;
	else
		q -> next = p1;
	
}







