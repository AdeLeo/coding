#include <stdio.h>
#include <assert.h>

/*
    算法1： 建立一个与原数组相同大小的临时数组，
            临时数组的元素h(i)的含义是到当前元素为止最长递增子序列的长度
    复杂度：O(n*n)
 */

int maxIncreaseSub(int *arr, int len)
{
    assert(arr != NULL && len > 0);

    int tmp[len];
    int i = 0, j = 0;
    int maxLen = 0;

    tmp[0] = 1;
    for(i = 1; i < len; i++)
    {
        tmp[i] = 0;
    }

    for(i = 1; i < len; i++)
    {
        for(j = 0; j < i; j++)
        {
            if(arr[j] < arr[i] && tmp[j] + 1 > tmp[i])
            {
                tmp[i] = tmp[j] + 1;
            }
        }

        if(tmp[j] == 0)
        {
            tmp[j] = 1;
        }
    }

    for(i = 0; i < len; i++)
    {
        if(tmp[i] > maxLen)
            maxLen = tmp[i];
    }

    return maxLen;
}

static int findFirstGreater(int *arr, int len, int key)
{
    assert(arr != NULL && len > 0);

    int i = 0;
    
    for(i = 0; i < len; i++)
    {
        if(arr[i] >= key)
            break;
    }

    return i;
}
/*
    算法1： 建立一个与原数组相同大小的临时数组，
            临时数组的元素h(i)的含义是有效区遍历到当前时刻为止，长度为i+1的最长子序列最小末尾是多少
    复杂度：O(n*logn)
 */
int maxIncreaseSub1(int *arr, int len)
{
    assert(arr != NULL && len > 0);

    int tmp[len];
    int i = 0, j = 0, validLen = 0, ret = 0;
    
    tmp[0] = arr[0];
    validLen = 1;

    for(i = 1; i < len; i++)
    {
        ret = findFirstGreater(tmp, validLen, arr[i]);
        
        if(ret == validLen)
        {
            ++validLen;
        }

        tmp[ret] = arr[i];
    }

    return validLen;
    
}

int main()
{
    int arr[] = {2,1,6,4,5,2,7,4};

    printf("%d\n", maxIncreaseSub1(arr, sizeof(arr) / sizeof(arr[0])));
    printf("%d\n", maxIncreaseSub(arr, sizeof(arr) / sizeof(arr[0])));

    return 0;
}
