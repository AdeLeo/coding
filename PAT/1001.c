#include <stdio.h>
#include <stdlib.h>

unsigned int fun_counts(int n)
{
    if(n <= 0)
        return 0;

    unsigned int cnt = 1;

    while(n != 1)
    {
        cnt++;

        if(n & 1)
        {
            n = 3*n-1;
        }

        else
            n /= 2;
    }

    return cnt;
}

int main(void)
{
    int num = 0;
    unsigned int count = 0;
    int n = 0;

    if((n = scanf("%d", &num)) != EOF)
    {
        printf("%d\n", EOF);
        printf("[TEST]:%d\n", n);
        count = fun_counts(num);
        printf("[FUNC]:RET\n");
        printf("%u\n", count);
    }


    printf("DONE...\n");

    return 0;
}
