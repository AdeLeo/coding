#include <stdio.h>
#include <stdlib.h>

typedef struct ev
{
    int begin;
    int end;
}event;

int cmp(const void *a, const void *b)
{
    event *ea = (event *)a;
    event *eb = (event *)b;

    if(ea->end <= eb->end)
        return -1;
    else 
        return 1;
}

int main()
{
    event e[] = {
        {1,2},
        {3,5},
        {4,6},
        {2,3}
    };

    qsort(e, sizeof(e)/sizeof(e[0]), sizeof(e[0]), cmp);

    int i = 0;
    int count = 1;

    for(i = 0; i < sizeof(e) / sizeof(e[0]); i++)
    {
        printf("(%d, %d)\n", e[i].begin, e[i].end);
    }

    printf("\n");

    printf("(%d, %d)\n", e[0].begin, e[0].end);

    for(i = 1; i < sizeof(e) / sizeof(e[0]); i++)
    {
        if(e[i].begin >= e[i - 1].end)
        {
            printf("(%d, %d)\n", e[i].begin, e[i].end);
            count++;
        }
    }

    printf("cnt:%d\n", count);

    return 0;
}
