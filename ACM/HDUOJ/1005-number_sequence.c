#include <stdio.h>

int f(int a, int b, int n)
{
    int i;
    int s[50];
    s[0] = s[1] = 1;
    for(i = 2; i < 50; i++)
    {
        s[i] = (a * s[i-1] + b * s[i - 2]) % 7;
        if(s[i] == 1 && s[i - 1] == 1)
            break;
    }
    n = n % (i-1);
    if(n == 0)
        return s[i - 2];
    else
        return s[n - 1];
}
/*
int f(int a, int b, int n)
{
    if(n == 1 || n == 2)
        return 1;

    n -= 2;
    int curr = 0;
    int first = 1;
    int second = 1;

    while(n--)
    {
        curr = (a * first + b * second) % 7;
        second = first;
        first = curr;
    }

    return curr;
}*/
/*
int f(int a, int b, int n)
{
    if(n == 1 || n == 2)
        return 1;

    return (a * f(a, b, n - 1) + b * f(a, b, n - 2)) % 7;
}
*/
int main()
{
    int a;
    int b;
    int n;

    while(scanf("%d %d %d", &a, &b, &n) && !(a == 0 && b == 0 && n == 0))
    {
        printf("%d\n", f(a, b, n));
    }

    return 0;
}
