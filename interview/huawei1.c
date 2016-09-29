#include <stdio.h>

/*
    问题描述：
        返回输入正整数第一个是1的比特位的位置(若输入0或负数返回-1)

    样例输入：
        12
        0

    样例输出：
        2
        -1
 */

int indexFind(long long int num)
{
    if(num <= 0)
        return -1;

    int index = 0;

    while(((num >> index) & 1) == 0)
    {
        ++index;
    }

    return index;
}

int main()
{
    long long int n = 0;

    while(scanf("%lld", &n) != EOF)
    {
        printf("%d\n", indexFind(n));
    }

    return 0;
}
