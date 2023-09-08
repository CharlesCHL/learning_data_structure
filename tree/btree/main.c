



#include <stdio.h>
#include <stdlib.h>

#include "queue.h"


#define NAMESIZE	10
#define datatype	SCORE

typedef struct score_st
{
	int id;
	char name[NAMESIZE];	
	int score;
} SCORE;

struct node_st
{
	datatype data;
	struct node_st *l, *r;
};	

static void print_s(SCORE* p)
{
	printf("%d  %s  %d\n", p->id, p->name, p->score);
}

int get_num(struct node_st*);

int insert(struct node_st**, datatype*);

datatype* find(struct node_st*, int);

void draw(struct node_st*);

static struct node_st* find_l(struct node_st* root)
{
	if(root->l == NULL)
		return root;

	find_l(root->l);
}

static struct node_st* find_r(struct node_st* root)
{
	if(root->r == NULL)
		return root;

	find_r(root->r);
}

static void turn_left(struct node_st** root)
{
	struct node_st* cur = *root;
	*root = cur->l;
	cur->l = NULL;
	
	find_r(*root)->r = cur;
	
}

static void turn_right(struct node_st** root)
{
	struct node_st* cur = *root;
	*root = cur->r;
	cur->r = NULL;

	find_l(*root)->l = cur;
}

void balance(struct node_st**);

void delete(struct node_st**, int);

void travel_1(struct node_st*);

void travel_2(struct node_st*);

int main()
{
	int arr[] = {1, 2, 3, 7, 6, 5, 9, 8, 4};
	struct node_st* tree = NULL;
	int i;
	SCORE tmp, *datap;
	
	for(i = 0; i < sizeof(arr) / sizeof(*arr); i++)
	{
		tmp.id = arr[i];
		snprintf(tmp.name, NAMESIZE, "STU%d", arr[i]);
		tmp.score = rand() % 100;	

		insert(&tree, &tmp);
	}
	
	draw(tree);
	printf("\n----\n");

	balance(&tree);

	draw(tree);
	printf("\n----\n");

	travel_2(tree);

#if 0
	int tmpid = 5;
	delete(&tree, tmpid);
	draw(tree);
	printf("\n----\n");
#endif


#if 0	
	int tmpid = 12;
	datap = find(tree, tmpid);
	if(datap == NULL)
		printf("Find id %d failed!\n", tmpid);
	else
		print_s(datap);
#endif

	exit(0);

}


int insert(struct node_st** root, datatype* data)
{
	struct node_st* node;

	if(*root == NULL)
	{
		node = malloc(sizeof(*node));
		if(node == NULL)
			return -1;
		node->data = *data;
		node->l = NULL;
		node->r = NULL;
		
		*root = node;
		return 0;
	}

	if(data->id <= (*root)->data.id)
		return insert(&((*root)->l), data);
	else
		return insert(&((*root)->r), data);

}

datatype* find(struct node_st* root, int id)
{
	if(root == NULL)
		return NULL;
	if(id == root->data.id)
		return &(root->data);
	if(id < root->data.id)
		return find(root->l, id);
	else
		return find(root->r, id);
}

void draw_(struct node_st* root, int level)
{
	if(root == NULL)
		return ;
	int i;

	draw_(root->r, level + 1);
	for(i = 0;i < level; i++)
		printf("    ");
	print_s(&(root->data));

	draw_(root->l, level + 1);
}

void draw(struct node_st* root)
{
	draw_(root, 0);			
}

int get_num(struct node_st* root)
{
	if(root == NULL)
		return 0;
	return get_num(root->l) + 1 + get_num(root->r);
}

void balance(struct node_st** root)
{
	if(*root == NULL)
		return ;

	int sub;

	while(1)
	{
		sub = get_num((*root)->l) - get_num((*root)->r);
		
		if(sub < -1)
			turn_right(root);
		else if(sub > 1)
			turn_left(root);
		else
			break;
	}

	balance(&((*root)->l));
	balance(&((*root)->r));

}

void delete(struct node_st** root, int id)
{
	struct node_st** node = root;
	struct node_st* cur = NULL;
	while(1)
	{
		if(*node == NULL)
			return ;

		if(id < (*node)->data.id)
			node = &((*node)->l);
		else if(id > (*node)->data.id)
			node = &((*node)->r);
		else
			break;
	}
		
	cur = *node; 
	
	if(cur->l == NULL)
		*node = cur->r;
	else
	{
		*node = cur->l;
		(find_r(cur->l))->r = cur->r;		
	}
	free(cur);
	return ;
}

void travel_1(struct node_st* root)
{
	if(root == NULL)
		return ;

	travel_1(root->l);
	print_s(&(root->data));
	travel_1(root->r);
}


void travel_2(struct node_st* root)
{
	QUEUE* qu;
	struct node_st* cur;

	qu = queue_create(sizeof(struct node_st*));
	if(qu == NULL)
		return ;

	queue_en(qu, &root);
	int ret;
	while(1)
	{
		ret = queue_de(qu, &cur);
		if(ret == -1)
			break;
		print_s(&(cur->data));
		if(cur->l != NULL)
			queue_en(qu, &(cur->l));
		if(cur->r != NULL)
			queue_en(qu, &(cur->r));
	}
	queue_destroy(qu);
	return ;
}





