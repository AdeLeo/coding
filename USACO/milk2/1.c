#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return *(int *)a-*(int *)b;
}

int main()
{
    int a[]={4,2,5,8,1,2,3};
    qsort(a, sizeof(a)/sizeof(a[0]), sizeof(a[0]), cmp);
    int i = 0;
    for(i = 0; i<sizeof(a)/sizeof(a[0]); i++)
        printf("[%d]\n", a[i]);
    return 0;
}
