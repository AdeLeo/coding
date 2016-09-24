#include <stdio.h>

/*
	本程序包含快速排序的实现，以及partition函数的使用
*/

static void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/*
	这种写法遇到比pivot大的数要经过多次交换才能到达指定位置
*/
/*
int partition(int *arr, int begin, int end)
{
	int pivot = arr[begin];
	int pos = begin;
	int i = begin + 1;
	
	for(i = begin + 1; i < end; i++)
	{
		if(arr[i] <= pivot)
		{
			++pos;
			if(i != pos)
				swap(&arr[i], &arr[pos]);
		}
	}
	swap(&arr[pos], &arr[begin]);
	return pos;
}
*/

/*
	比较推荐的partition的写法
	没有调用交换函数，但是实质上实现了交换
*/

int partition(int *arr, int begin, int end)
{
	int pivot = arr[begin];

	while(begin < end)
	{
		while(arr[--end] >= pivot);
		arr[begin] = arr[end];
	
		while(arr[++begin] <= pivot);
		arr[end] = arr[begin];
	}

	arr[begin] = pivot;
	return begin;
}

int three_way_partition(int *arr, int len, int target)
{
	int next_scan_pos = 0, next_less_pos = 0, next_bigger_pos = len - 1;

	while(next_scan_pos <= next_bigger_pos)
	{
		if(arr[next_scan_pos] < target)
		{
			swap(&arr[next_scan_pos++], &arr[next_less_pos++]);
		}

		else if(arr[next_scan_pos] > target)
		{
			swap(&arr[next_scan_pos], &arr[next_bigger_pos]);
		}
		
		else
		{
			++next_scan_pos;
		}
	}
	return next_less_pos;
}

void quick_sort(int *arr, int begin, int end)
{
	if(begin >= end)
		return;
	int pos = partition(arr, begin, end);
	quick_sort(arr, begin, pos);
	quick_sort(arr, pos + 1, end);
}

int main()
{
	int arr[] = {1, 2, 5, 3, 0, 8, 2};
	int arr1[] = {1, 2, 5, 3, 0, 8, 2, 2, 1, 0};
	int i = 0;
	
	quick_sort(arr, 0, sizeof(arr) / sizeof(arr[0]));

	for(i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%d\n", arr[i]);
	}

	for(i = 0; i < sizeof(arr1) / sizeof(arr1[0]); i++)
	{
		printf("%d\n", arr1[i]);
	}

	return 0;
}
