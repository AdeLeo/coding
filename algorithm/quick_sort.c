#include <stdio.h>

int partition(int *arr, int begin, int end)
{
    int pivot = arr[begin];
    while(begin < end)
    {
        while(begin < end && pivot <= arr[--end]);
        arr[begin] = arr[end];

        while(begin < end && pivot >= arr[++begin]);
        arr[end] = arr[begin];
    }

    arr[begin] = pivot;
    return begin;
}

void quick_sort(int *arr, int begin, int end)
{
    if(begin >= end)
        return ;

    int pos = partition(arr, begin, end);
    quick_sort(arr, begin, pos);
    quick_sort(arr, pos+1, end);
}

int main()
{
    int arr[] = {5,3,6,2,7,1,0,4};
    int i = 0;
    for(i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        printf("%d\n", arr[i]);
    }
    quick_sort(arr, 0, sizeof(arr)/sizeof(arr[0]));
    for(i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        printf("%d\n", arr[i]);
    }
    return 0;
}
