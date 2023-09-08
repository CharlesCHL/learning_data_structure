#include <stdio.h>
#include <stdlib.h>

#include "sqstack.h"

int main()
{
	datatype arr[] = {1, 12, 32, -3, 9};
	sqstack* st;
	int i;

	st = st_create();
	if(st == NULL)
		exit(1);
	for(i = 0; i < sizeof(arr) / sizeof(*arr); i++)
	{
		st_push(st, arr + i);

	}
		
	st_travel(st);

/**	
	int ret;
	datatype tmp = -1;
	ret = st_push(st, &tmp);
	if(ret != 0)
		printf("Push failed!\n");
	else
		st_travel(st);
*/

	datatype tmp;
	while(st_pop(st, &tmp) == 0)
	{
		printf("POP:%d\n", tmp);
	}

	st_destroy(st);	
	exit(0);

}




