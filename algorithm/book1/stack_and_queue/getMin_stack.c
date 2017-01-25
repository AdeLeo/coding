#include <stdio.h>

int Stack[10];
int top = -1;

int pop(int *elem)
{
    if(top < 0)
    {
        return -1;
    }

    *elem = Stack[top--];
    return 0;
}

int push(int elem)
{
    if(top > 9)
        return -1;

    Stack[++top] = elem;
    return 0;
}


