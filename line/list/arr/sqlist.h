#ifndef SQLIST_H__
#define SQLIST_h__

#define DATASIZE	1024 

typedef int datatype;

typedef struct node_st 
{
		datatype data[DATASIZE];
		int last;
} sqlist;

sqlist* sqlist_create_1();

void sqlist_create_2(sqlist**);

int sqlist_insert(sqlist*, int i, datatype*);

int sqlist_add(sqlist* me, datatype* data);

int sqlist_delete(sqlist*, int i);

int sqlist_find(sqlist*, datatype*);

datatype* sqlist_getvalue(sqlist* me, int i);

int sqlist_isfull(sqlist* me);

int sqlist_isempty(sqlist*);

int sqlist_setempty(sqlist*);

int sqlist_getnum(sqlist*);

int sqlist_union(sqlist*, sqlist*);

void sqlist_display(sqlist*);

int sqlist_destroy(sqlist*);



#endif




