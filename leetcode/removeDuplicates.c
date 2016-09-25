#include <stdio.h>

/*
int removeDuplicates(int *arr, int len)
{
    int count = 0;
    int i = 1;
    for(i = 1; i < len; i++)
    {
        if(arr[i] == arr[i - 1])
            count++;
        else
            arr[i-count] = arr[i];
    }
    return len-count;
}
int removeDuplicates(int *arr, int len)
{
    int slow = 0;
    int fast = 0;

    while(fast < len)
    {
        while(fast < len && arr[++fast] == arr[slow]);
        
        if(fast < len)
            arr[++slow] = arr[fast];
    }

    return slow + 1;
}


int removeDuplicates(int *arr, int n)
{
    if(n < 2)
        return n;

    int i = 1;
    int id = 1;

    for(i = 1; i < n; i++)
    {
        if(arr[i] != arr[i - 1])
            arr[id++] = arr[i];
    }

    return id;
}
*/

int removeDuplicates(int *arr, int len)
{
    if(len < 2)
        return len;

    int id = 1;
    int i = 0;
    while(++i < len)
    {
        if(arr[i] != arr[i-1])
            arr[id++] = arr[i];
    }
    return id;
}

int main()
{
    int arr[] = {0, 0, 0, 1, 1, 1};
    int pos = removeDuplicates(arr, sizeof(arr) / sizeof(arr[0]));
    printf("pos:%d\n", pos);
    int i = 0;

    for(i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
        printf("arr[%d]:%d\n", i, arr[i]);
    
    return 0;
}
