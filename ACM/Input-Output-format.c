#include <stdio.h>

int main()
{
    int n, a, i, res;

    while(scanf("%d", &n) && (n != 0))
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
