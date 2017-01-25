#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
/*
void merge(int *arr1, int len1, int *arr2, int len2, int *tmp, int len3)
{
	assert(len3 >= len1 + len2);

	int i = 0;
	int j = 0;
	int k = 0;

	for(i = 0, j = 0, k = 0; i < len1 && j < len2 && k < len3;)
	{
		if(arr1[i] > arr2[j])
			tmp[k++] = arr2[j++];
		else
			tmp[k++] = arr1[i++];
	}

	while(i < len1)
		tmp[k++] = arr1[i++];

	while(j < len2)
		tmp[k++] = arr2[j++];
}*/

void merge(int *arr, int low, int mid, int high)
{
	int i = low;
	int j = mid+1;
	int k = 0;
	int tmp[high-low+1];

	for(i = low, j = mid+1, k = 0; i <= mid && j < high; )
	{
		if(arr[i] > arr[j])
			tmp[k++] = arr[j++];
		else
			tmp[k++] = arr[i++];
	}

	while(i <= mid)
		tmp[k++] = arr[i++];

	while(j <= high)
		tmp[k++] = arr[j++];

	for(i = low, k = 0; i < high; i++, k++)
		arr[i] = tmp[k];
}

void merge(int *arr, int l, int m, int r)
{
	int i, j, k;
	int n1 = m-l+1;
	int n2 = r - m;

	int larr[n1], rarr[n2];

	for(i = 0; i < n1; i++)
		larr[i] = arr[l + i];
	for(j = 0; j <= n2; j++)
		rarr[j] = arr[m + 1+j];

	i = 0, j = 0, k = l;

	while(i < n1 && j < n2)
	{
		if(larr[i] <= rarr[j])
	}
}

void merge_sort(int *arr, int begin, int end)
{
	if(begin >= end)
		return;

	int mid = (end + begin) / 2;

	merge_sort(arr, begin, mid);
	merge_sort(arr, mid+1, end);
	merge(arr, begin, mid, end);
}

int main()
{
	int arr[] = {4,5,2,6,7,8,9,1,3,0};
	int arr1[] = {6,7,8,9,1,3,5};
	merge(arr1, 0, 3, 7);
	int i = 0;
/*
	printf("BEFORE SORT:\n");
	for(i = 0; i < 10; i++)
		printf("%d\n", arr[i]);

	merge_sort(arr, 0, 10);

	printf("AFTER SORT:\n");
	for(i = 0;i < 10; i++)
		printf("%d\n", arr[i]);
*/
	printf("AFTER SORT:\n");
	for(i = 0;i < 7; i++)
		printf("%d\n", arr1[i]);
	return 0;
}
