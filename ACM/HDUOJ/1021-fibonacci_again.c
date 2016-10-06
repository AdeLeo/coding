#include <stdio.h>

int fibonacci(int n)
{
    if(n == 0)
        return 7;
    else if(n == 1)
        return 11;

    n--;
    int curr = 0;
    int first = 7;
    int second = 11;

    while(n--)
    {
        curr = first + second;
        first = second;
        second = curr;
    }
    return curr;
}

int main()
{
    int arr[] = {1,2,0,2,2,1,0,1};
    int i = 0;
    int n;
    int len = sizeof(arr) / sizeof(arr[0]);
    while(scanf("%d", &n) != EOF)
    {
        printf("fibo:%d\n", fibonacci(n));

        if(!arr[n%len])
        {
            printf("yes\n");
        }
        else
            printf("no\n");
    }

    return 0;
}
