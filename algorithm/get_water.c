#include <stdio.h>

/*
 存水问题：
 例如：
 arr[] = {3,1,2,3,1,2,1};
 能存的水量为：
 |     |
 |   | |   |
 | | | | | | |
 0+2+1+0+1+0+0 = 4
 */

/*
 对于每个位置的i，均计算左右两边的最大值，取两边最大值的最小值和0比较的最大值即：
 max(0, min(lmax(i), rmax(i)))
 */

static int min(int a, int b)
{
    return a < b ? a : b;
}

static int max(int a, int b)
{
    return a > b ? a : b;
}

int get_water1(int arr[], int len)
{
    int lmax = 0, rmax = 0;
    int l = 0, r = len - 1;
    int sum = 0;
    int i, j;

    for(i = 0; i < len - 1; i++)
    {
        lmax = arr[0];
        rmax = arr[len - 1];

        for(l = 0; l < i; l++)
        {
            if(arr[l] > lmax)
                lmax = arr[l];
        }

        for(r = len - 1; r > i; r--)
        {
            if(arr[r] > rmax)
                rmax = arr[r];
        }

        sum += max(0, min(lmax, rmax) - arr[i]);
    }

    return sum;
}

/*
 提前将i位置左右两边的最大值记录在两张表里
 要用的时候直接提取最大值即可
 */

int get_water2(int arr[], int len)
{
    int l[len];
    int r[len];

    int i, j;
    int lmax = 0, rmax = 0;
    int sum = 0;

    l[0] = arr[0];
    r[len - 1] = arr[len - 1];

    for(i = 1, lmax = arr[0]; i < len; i++)
    {
        if(lmax < arr[i])
        {
            lmax = arr[i];
        }

        l[i] = lmax;
    }

    for(i = 0; i < len; i++)
        printf("l[%d]=%d\n", i, l[i]);

    for(i = len - 2, rmax = arr[len - 1]; i >= 0; i--)
    {
        if(rmax < arr[i])
        {
            rmax = arr[i];
        }

        r[i] = rmax;
    }

    for(i = 0; i < len; i++)
        printf("r[%d]=%d\n", i, r[i]);

    for(i = 0; i < len; i++)
    {
        sum += max(0, min(l[i], r[i]) - arr[i]);
    }

    return sum;
}

/*
 同方法2，只是做了去掉一个记录左边最大值的优化，
 因为读取数据从左边开始遍历，完全可以只用一个变量记录左边到当前的最大值，
 然后跟r[len]中的数据比较大小，并累计
 */

int get_water3(int arr[], int len)
{
    int r[len];
    int i = 0;
    int lmax, rmax;
    int sum = 0;

    r[len - 1] = arr[len - 1];

    for(i = len - 2, rmax = arr[len - 1]; i >= 0; i--)
    {
        if(rmax < arr[i])
            rmax = arr[i];
        
        r[i] = rmax;
    }

    for(i = 1, lmax = arr[0]; i < len; i++)
    {
        if(lmax < arr[i])
            lmax = arr[i];

        sum += max(0, min(lmax, r[i]) - arr[i]);
    }

    return sum;
}

/*
 方法4：
 从两端开始，记录两端各自的最大值，较小的一方是瓶颈，
 即可以计算出较小一方的索引所在位置的水量值
 */

int get_water4(int arr[], int len)
{
    int sum = 0;
    int i, j, lmax,rmax;

    for(i = 0, j = len - 1, lmax = arr[0], rmax = arr[len - 1]; i <= j; )
    {
        if(lmax < rmax)
        {
            sum += max(0, lmax - arr[i++]);
            if(lmax < arr[i])
                lmax = arr[i];
        }

        else
        {
            sum += max(0, rmax - arr[j--]);
            if(rmax < arr[j])
                rmax = arr[j];
        }
    }

    return sum;
}

#define arr_size(arr) (sizeof(arr)/sizeof(arr[0]))

int main()
{
    int arr[] = {5,1,4,7,4,5,6};
    int arr1[] = {3,1,2,3,1,2,1};

    int value = get_water1(arr, arr_size(arr));
    printf("water:%d\n", value);
    
    value = get_water4(arr1, arr_size(arr1));
    printf("water:%d\n", value);

    return 0;
}
