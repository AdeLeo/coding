#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node
{
    float coef;
    int index;
};

void sum(struct node *p1, int n1, struct node *p2, int n2)
{
    assert(p1 && p2);

    int n = (p1[0].index > p2[0].index ? p1[0].index : p2[0].index) + 1;

    struct node *p3 = (struct node *)malloc(sizeof(struct node) * (n));
    
    if(p3 == NULL)
        return;
    
    int i = 0, j = 0, k = 0;

    for(i = 0; i < n && j < n1 && k < n2; i++)
    {
        if(p1[j].index == p2[k].index)
        {
            p3[i].index = p2[k].index;
            p3[i].coef = p1[j++].coef + p2[k++].coef;
        }
        else if(p1[j].index > p2[k].index)
        {
            p3[i].index = p1[j].index;
            p3[i].coef = p1[j++].coef;
        }
        else
        {
            p3[i].index = p2[k].index;
            p3[i].coef = p2[k++].coef;
        }
    }

    while(i < n && j < n1)
    {
        p3[i].index = p1[j].index;
        p3[i++].coef = p1[j++].coef;
    }

    while(i < n && k < n2)
    {
        p3[i].index = p2[k].index;
        p3[i++].coef = p2[k++].coef;
    }

    printf("%d ", n);
    for(i = 0; i < n; i++)
    {
        if(i == n - 1)
        {
            printf("%d %2.1f\n", p3[i].index, p3[i].coef);
            break;
        }
        printf("%d %2.1f ", p3[i].index, p3[i].coef);
    }

    free(p3);
    p3 = NULL;
}

int main()
{
    int n1 = 0, n2 = 0, i = 0;

    struct node *p1 = NULL;
    struct node *p2 = NULL;

    scanf("%d", &n1);
    p1 = (struct node *)malloc(sizeof(struct node) * n1);
    
    if(p1 == NULL)
        return -1;
    
    for(i = 0; i < n1; i++)
    {
        scanf("%d %f", &p1[i].index, &p1[i].coef);
    }

    scanf("%d", &n2);
    p2 = (struct node *)malloc(sizeof(struct node) * n2);
    
    if(p2 == NULL)
        return -1;

    for(i = 0; i < n2; i++)
    {
        scanf("%d %f", &p2[i].index, &p2[i].coef);
    }

    sum(p1, n1, p2, n2);

    free(p1);
    p1 = NULL;

    free(p2);
    p2 = NULL;


}
