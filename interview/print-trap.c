#include <stdio.h>
 
/*
 解析：
 printf()计算参数时是从右往左压栈的
 */

int main()
{
    int arr[] = {6,7,8};
    int *ptr = arr;
    ptr++;
    printf("%d %d\n", *ptr, *(++ptr));
}
