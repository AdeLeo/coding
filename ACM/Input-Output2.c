#include <stdio.h>

int main()
{
    int n = 0, a = 0, i = 0, res = 0;
    while(scanf("%d", &n) != EOF)
    {
        for(i = 0, res = 0; i < n; i++)
        {
            scanf("%d", &a);
            res += a;
        }

        printf("%d\n", res);
    }

    return 0;
}
