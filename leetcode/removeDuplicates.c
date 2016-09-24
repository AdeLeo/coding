#include <stdio.h>

/*
	删除数组中重复的元素
*/

int removeDuplicates(int *arr, int len)
{
	if(len < 2)
		return len;

	int i = 1;
	int id = 1;

	for(i = 1; i < len; i++)
	{
		if(arr[i] != arr[i-1])
		{
			arr[id++] = arr[i];
		}
	}

	return id;
}

