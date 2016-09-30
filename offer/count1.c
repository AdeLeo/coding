#include <stdio.h>
/*
 问题描述：
    给定一个十进制整数N，求出从1到N的所有整数中出现"1"的个数

输入样例：
    N=2时，1,2出现了一个"1"
    N=12时，1,2,3,4,5,6,7,8,9,10,11,12。出现了5个"1"
 */

//方法1：暴力法：
//复杂度：O(N * lgN)
int countOnes(long n)
{
    long i = 0, j = 1;
    long count = 0;
    for(i = 1; i <= n; i++)
    {
        j = i;
        while(j != 0)
        {
            if(j % 10 == 1)
                count++;
            j /= 10;
        }
    }
    return count;
}

//方法二：
/*
 1位数的情况：
    大于等于1的时候，有一个，小于1就没有
 2位数的情况：
    N=13，个位数出现的1的次数为2，分别为1和11，十位数出现1的次数为4，分别为10,11,12,13，所有f(N)
 */
long countOne2(long n)
{
    long count = 0;
    long i = 1;
    long current = 0, after = 0, before = 0;
    while((n / i) != 0)
    {
        current = ((m / i) != 0)
        before = (n / i) % 10;
        after = n - (n / i) * i;

        if(current > 1)
            count = count + (before + 1) * i;
        else if(current == 0)
            count = count + before * i;
        else if(current == 1)
            count = count + before * i + after + 1;

        i = i * 10;
    }

    return count;
}
