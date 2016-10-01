#include <stdio.h>

int gcd(int a, int b)
{
    if(b > a)
        return gcd(b, a);

    int c;

    while(b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }

    return a;
}

/*
    lcm = (a * b) / gcd(a, b);
 */
int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

int main()
{
    int a, b;

    while(scanf("%d %d", &a, &b) != EOF)
    {
        printf("%d\n", lcm(a, b));
    }

    return 0;
}
