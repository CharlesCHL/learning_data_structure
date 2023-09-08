

#include <stdio.h>
#include <stdlib.h>

#include "queue.h"


int main()
{

	queue* sq;
	datatype arr[] = {1, 34, -7, 12}; 
	int i;

	sq = qu_create();
	if(sq == NULL)
		exit(1);
	for(i = 0; i < sizeof(arr) / sizeof(*arr); i++)
	{
		qu_enqueue(sq, arr + i);
	}

	qu_travel(sq);
	
	datatype tmp;
	qu_dequeue(sq, &tmp);
	printf("%d\n", tmp);
	qu_travel(sq);

	qu_destroy(sq);

	exit(0);

}




