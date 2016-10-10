#include <stdio.h>

int max = 0;

int get_area(int arr[], int len)
{
    int l, r;

    for(l = 0, r = len - 1; l < r; )
    {
        if(arr[l] < arr[r])
        {
            if(arr[l] * (r - l - 1) > max)
                max = arr[l] * (r - l - 1);
            ++l;
        }

        else
        {
            if(arr[r] * (r - l - 1) > max)
                max = arr[r] * (r - l - 1);
            --r;
        }
    }

    return max;
}

int main()
{
    int arr[] = {3,5,7,2,9,2};
    get_area(arr, sizeof(arr) / sizeof(arr[0]));
    printf("max:%d\n", max);
    return 0;
}
