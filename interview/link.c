#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node, *LinkList;

int count = 0;

int DeleteList(LinkList L, int minK, int maxK)
{
    int flag = 0;
    Node *p = NULL;
    Node *q = NULL;
    
    for(p = L, q = p->next; q != NULL; )
    {
        if(q->data > minK && q->data < maxK)
        {
            flag = 1;
            p->next = q->next;
            free(q);
            count++;
            q = NULL;
            q = p->next;
            continue;
        }

        else
        {
            p = q;
            q = p->next;
        }
    }
    
    return flag == 0 ? -1 : 0;
}

void print(LinkList L)
{
    printf("PRINT LIST START\n");

    Node *p = L->next;
    while(p != NULL)
    {
        printf("%d\n", p->data);
        p = p->next;
    }

    printf("PRINT LIST OVER\n");
}

void deleteLink(LinkList L)
{
    printf("START DELETE\n");
    Node *p = L->next;
    Node *q;
    //int count = 0;
    while(p != NULL)
    {
        count++;
        q = p->next;
        free(p);
        p = NULL;
        p = q;
    }
    L->next = NULL;
    printf("delete linklist total %d!\n", count);
}


int main()
{
    LinkList L;
    int cnt = 0;
    L->next = (Node *)malloc(sizeof(Node));
    (L->next)->data = 12;
    (L->next)->next = NULL;
    Node *p = L->next;
    cnt++;
    p->next = (Node *)malloc(sizeof(Node));
    (p->next)->data = 18;
    (p->next)->next = NULL;
    p = p->next;
    cnt++;
    p->next = (Node *)malloc(sizeof(Node));
    (p->next)->data = 25;
    (p->next)->next = NULL;
    p = p->next;
    cnt++;
    p->next = (Node *)malloc(sizeof(Node));
    (p->next)->data = 34;
    (p->next)->next = NULL;
    p = p->next;
    cnt++;
    p->next = (Node *)malloc(sizeof(Node));
    (p->next)->data = 48;
    (p->next)->next = NULL;
    p = p->next;
    cnt++;
    p->next = (Node *)malloc(sizeof(Node));
    (p->next)->data = 62;
    (p->next)->next = NULL;
    cnt++;

    print(L);

    DeleteList(L, 20, 50);

    print(L);

    deleteLink(L);

    return 0;
}
