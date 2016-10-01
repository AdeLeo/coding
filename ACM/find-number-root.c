#include <stdio.h>

int findRoot(int n)
{
    int root = 0;
    for(root = 0; !(root > 0 && root < 10); n = root)
    {
        root = 0;
        while(n != 0)
        {
            root += (n % 10);
            n /= 10;
        }
    }
    return root;
}

int main()
{
    int n = 0, a = 0;
    
    while(scanf("%d", &n) && n != 0)
    {
        printf("%d\n", findRoot(n));
    }
    
    return 0;
}
