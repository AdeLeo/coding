#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*
 库函数qsort的使用demo
 */

int cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int findKndNum(int *arr, int len, int k)
{
    assert(arr && len > 0 && k > 0 && k <= len);
//    int (*pfun)(const void *, const void *) = cmp;
    qsort(arr, len, sizeof(arr[0]), cmp);
    return arr[len - k];
}

int main()
{
    int i = 1;
    int arr[] = {1,0,5,3,2,4};
    for(i = 1; i < sizeof(arr) / sizeof(arr[0]); i++)
        printf("k:%d, %d\n", i, findKndNum(arr, sizeof(arr) / sizeof(arr[0]), i));
    return 0;
}
