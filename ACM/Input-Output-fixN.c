#include <stdio.h>

int main()
{
    int n = 0, i = 0;
    int a = 0, b = 0;

    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%d %d", &a, &b);
        printf("%d\n", a+b);
    }

    return 0;
}
