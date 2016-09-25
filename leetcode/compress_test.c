#include <stdio.h>
/*
 char str[128]中每个元素的值都是0或1，请编程实现将该128个元素保存到char arr[16]中，以节约空间占用，例如将str[0]放到arr[0]的第0位上，str[8]方到arr[1]元素的第0位上
 */

#define ARRAY_SIZE(arr) sizeof(arr)/sizeof(arr[0])
#define N 8

char charPro(char *arr)
{
    int i = 0;
    char ch = 0;
    for(i = 0; i < N; i++)
    {
        ch |= (arr[i] << i);
    }
    return ch;
}

int main()
{
    char str[128] = {0,0,0,1, 0,0,0,0, 1,1,0,0, 0,0,0,0};
    char arr[16] = {0,0};

    int i = 0;
    for(i = 0; i < 128 / 16; i++)
    {
        arr[i] = charPro(str+i*N);
    }

    for(i = 0; i < ARRAY_SIZE(arr); i++)
    {
        printf("%d\n", arr[i]);
    }

    return 0;
}
