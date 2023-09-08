#ifndef	LIST_H__
#define LIST_H__

typedef int datatype;
typedef struct node_st 
{
		datatype data;
		struct node_st* next;
} linknode;


linknode* list_create();

int list_insert_at(linknode*, int, datatype*);

int list_head_insert(linknode*, datatype*);

int list_tail_insert(linknode*, datatype*);

int list_order_insert(linknode*, datatype*);

int list_delete_st(linknode* me, int i, datatype* data);

int list_delete(linknode*, datatype*);

int list_getnum(linknode*);

int list_isempty(linknode*);

void list_display(linknode*);

void list_destroy(linknode*);

#endif


