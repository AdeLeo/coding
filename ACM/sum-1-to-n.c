#include <stdio.h>

unsigned long sum(int n)
{
    if(n <= 0)
        return 0;

    int i = 0;
    unsigned long result = 0;

    while(i++ < n)
    {
        result += i;
    }

    return result;
}

int main()
{
    int n = 0;
    while(scanf("%d", &n) != EOF)
    {
        printf("%lu\n", sum(n));
    }

    return 0;
}
