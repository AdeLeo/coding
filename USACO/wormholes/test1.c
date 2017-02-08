#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Node {
    int x;
    int y;
}a[13];

int cmp(const void *a, const void *b)
{
    struct Node *pa = (struct Node *)a;
    struct Node *pb = (struct Node *)b;

    if(pa->y < pb->y)
        return 1;
    else if(pa->y == pb->y)
        if(pa->x < pb->x)
            return 1;
    return 0;
}

int main()
{
    a[1].x = 1;
    a[2].x = 2;
    a[3].x = 3;
    a[4].x = 4;
    a[1].y = 0;
    a[2].y = 0;
    a[3].y = 0;
    a[4].y = 0;

    qsort(a+1, 4, sizeof(a[0]), cmp);
    int i = 1;
    for(i = 1; i < 5; i++)
    {
        printf("a[%d]:x=%d y=%d\n", i, a[i].x, a[i].y);
    }

    return 0;
}
