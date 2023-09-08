#include <stdio.h>
#include <stdlib.h>
#include "sqlist.h"


int main() 
{

		datatype arr[] = {12, 23, 34, 45, 56, 67, 78, 89, 910, 1011, 1112, 1213};
		datatype arr1[] = {12, 76, 87, 45, 24, 16};

		int i, err;

		sqlist* list = NULL;
		sqlist* list1 = NULL;

//		list = sqlist_create_1();
		sqlist_create_2(&list);
		list1 = sqlist_create_1(list1);


		if(list == NULL)
		{
				fprintf(stderr, "sqlist_create_2() failed!");
				exit(1);
		}

		if(list1 == NULL)
		{
				fprintf(stderr, "sqlist_create_1() failed!");
				exit(2);
		}
//		printf("%d\n", sqlist_isempty(list));

		for(i = 0; i < sizeof(arr)/sizeof(*arr); i++)
		{
				if((err = sqlist_insert(list, i, arr + i)) != 0)
				{
						if(err = -1)
								fprintf(stderr, "The arr is full!\n");
						else if(err = -2)
								fprintf(stderr, "The pos is too large!\n");
						else
								fprintf(stderr, "ERROR!\n");
						exit(1);
				}
		}

		for(i = 0; i < sizeof(arr1)/sizeof(*arr1); i++)
		{
				if((err = sqlist_insert(list1, i, arr1 + i)) != 0)
				{
						if(err = -1)
								fprintf(stderr, "The arr is full!\n");
						else if(err = -2)
								fprintf(stderr, "The pos is too large!\n");
						else
								fprintf(stderr, "ERROR!\n");
						exit(1);
				}
		}
		
		sqlist_display(list);
		
		sqlist_display(list1);

//		sqlist_delete(list, 3);	
		
//		sqlist_display(list);

//		sqlist_setempty(list);

//		printf("%d\n", sqlist_isempty(list));


		sqlist_union(list, list1);

		sqlist_display(list);


		sqlist_destroy(list);
		sqlist_destroy(list1);

		exit(0);

}





