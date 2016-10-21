#include <stdio.h>

void insert(int *arr, int len)
{
    int tmp = 0;
    int i = 0;

    tmp = arr[len-1];
    for(i = len-1; i > 0 && tmp < arr[i-1]; i--)
    {
        arr[i] = arr[i-1];
    }

    arr[i] = tmp;
}

void insert_sort(int *arr, int len)
{
    int i = 0;

    for(i = 1; i < len; i++)
    {
        if(arr[i] < arr[i - 1])
        {
            insert(arr, i+1);
        }
    }
}

void print_arr(int *arr, int len)
{
    int i = 0;
    for(i = 0; i < len; i++)
    {
        printf("%d\n", arr[i]);
    }
}

#define arr_size(arr) (sizeof(arr) / sizeof(arr[0]))

int main()
{
    int arr[] = {2, 7, 9, 2, 7, 3, 0, 4};

    printf("BEFORE SORT\n");

    print_arr(arr, arr_size(arr));

    insert_sort(arr, arr_size(arr));

    printf("AFTER SORT\n");

    print_arr(arr, arr_size(arr));

    return 0;
}
