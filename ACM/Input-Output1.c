#include <stdio.h>

int main()
{
    int n = 0, m = 0, i = 0, j = 0, a = 0, res = 0;

    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &m);
        for(j = 0, res = 0; j < m; j++)
        {
            scanf("%d", &a);
            res += a;
        }
        printf("%d\n", res);
    }
    return 0;
}
