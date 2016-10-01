#include <stdio.h>
#include <math.h>

/*
    stirling formula:
        n! = sqrt(2 * PI * n) * pow(n / E, n);

    求一个数的位数：
        log10(n) + 1;
 */

#define PI 3.1415926
#define E 2.71828

extern double log10(double);

int l(int n)
{
    int s = 1;
    if(n > 3)
        s = log10(2*PI*n)/2+n*log10(n/E)+1;
    return s;
}

unsigned long long stirling(int n)
{
    return sqrt(2 * PI * n) * pow((n / E), n);
}

unsigned long long fact(int n)
{
    int i = 1;
    unsigned long long res = 1;

    for(i = 1; i <= n; i++)
    {
        res *= i;
    }

    return res;
}


int numCount1(unsigned long long num)
{
    int count = 0;
    while(num != 0)
    {
        ++count;
        num /= 10;
    }
    return count;
}

int numCount(unsigned long long num)
{
    /*
    int count = 0;
    while(num != 0)
    {
        ++count;
        num /= 10;
    }
    return count;
*/
    return (int)log10(num) + 1;
}

int main()
{
    int n = 0, i = 0, a = 0;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a);
        int ret = fact(a);
        printf("fact:%llu\n", fact(a));
        printf("stirling:%llu\n", stirling(a));
        printf("%d\n", l(a));
        printf("%d\n", numCount1(ret));
        printf("%d\n", numCount(ret));
    }

    return 0;
}
