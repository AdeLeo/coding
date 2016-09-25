#include <stdio.h>
#include <assert.h>

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void three_way_partition(int *arr, int begin, int end, int target)
{
    int next_scan_pos = 0, next_less_pos = 0, next_bigger_pos = end - 1;
    
    while(next_scan_pos <= next_bigger_pos)
    {
        if(arr[next_scan_pos] < target)
        {
            swap(&arr[next_scan_pos++], &arr[next_less_pos++]);
        }
        else if(arr[next_scan_pos] > target)
        {
            swap(&arr[next_scan_pos], &arr[next_bigger_pos--]);
        }
        else
        {
            next_scan_pos++;
        }
    }
}


int partition(int *arr, int begin, int end)
{
    int pivot = arr[begin];
    while(begin < end)
    {
        while(begin < end && arr[--end] >= pivot);
        arr[begin] = arr[end];
        while(begin < end && arr[++begin] <= pivot);
        arr[end] = arr[begin];
    }
    arr[begin] = pivot;
    return begin;
}


/*
每个小于pivot的值基本上（除非到现在为止还没有遇见大于pivot的值）都需要一次交换，大于pivot的值有可能需要被交换多次才能到达最终的位置
 */
/*
int partition(int *arr, int begin, int end)
{
    int pivot = arr[begin];
    int pos = begin;//记录小于轴枢元素的下标
    int i = 0;

    for(i = begin + 1; i < end; i++)
    {
        if(arr[i] <= pivot)
        {
            ++pos;
            if(i != pos)
            {
                swap(&arr[i], &arr[pos]);
            }
        }
    }

    swap(&arr[begin], &arr[pos]);

    return pos;
}
*/

/*
    保持头尾两个指针往中间扫描，每次在头部找到大于pivot的值，同时在尾
    部找到小于pivot的值，然后将它们做一个交换，就可以把这两个数字放到
    最终的位置。
int partition(int *arr, int begin, int end)
{
    int pivot = arr[begin];
    while(begin < end)
    {
        while(begin < end && arr[--end] >= pivot);
        arr[begin] = arr[end];
        while(begin < end && arr[begin++] <= pivot);
        arr[end] = arr[begin];
    }

    arr[begin] = pivot;
    return begin;
}

 */

void quick_sort(int *arr, int begin, int end)
{
    if(begin >= end)
        return;

    int pos = partition(arr, begin, end);
    quick_sort(arr, begin, pos);
    quick_sort(arr, pos + 1, end);
}

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
            {
                swap(&arr[pos], &arr[i]);
            }
        }
    }

    swap(&arr[begin], &arr[pos]);

    return pos;
}

int quick_sort(int *arr, int begin, int end)
{
    if(begin >= end - 1)
        return ;

    int pos = partition(arr, begin, end);

    quick_sort(arr, begin, pos);
    quick_sort(arr, pos + 1, end);
}
*/

int main()
{
    int arr[] = {3, 5, 2, 0, 1, 8};
    int arr1[] = {3, 5, 2, 0, 1, 8, 3, 3, 3, 5};

    quick_sort(arr, 0, sizeof(arr) / sizeof(arr[0]));
    three_way_partition(arr1, 0, sizeof(arr1) / sizeof(arr1[0]), 3);

    int i = 0;
    for(i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        printf("%d\n", arr[i]);
    }

    printf("\nDutch national flag\n");
    for(i = 0; i < sizeof(arr1) / sizeof(arr1[0]); i++)
    {
        printf("%d\n", arr1[i]);
    }
    return 0;
}
