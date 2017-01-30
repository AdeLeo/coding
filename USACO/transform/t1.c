#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int rotate_90(char dest_arr[][15], char src_arr[][15], int len);

int main()
{
    char a1[][15] = {
        "@-@",
        "---",
        "@@-",
    };

    char a2[][15] = {
        "@-@",
        "@--",
        "--@",
    };

    char tmp[3][15] = {""};

    rotate_90(tmp, a1, 3);

    int i;
    for(i = 0; i < 3; i++)
        printf("[DEBUG]:%s\n", tmp[i]);

    // printf("cmp:%d\n", cmp_arr(a1, a2, 3));
    // printf("%d\n", sizeof(a1));

    return 0;
}

int cmp_arr(const char arr1[][15], const char arr2[][15], int len)
{
    int i = 0;
    for(i = 0; i < len; i++)
    {
        if(strcmp(arr1[i], arr2[i]) != 0)
            break;
    }

    return i==len?1:0;
}

int rotate_90(char dest_arr[][15], char src_arr[][15], int len)
{
    bzero(dest_arr, 15*sizeof(char)*len);
    int i = 0, j = 0;

    for(i = 0; i < len; i++)
    {
        for(j = 0; j < len; j++)
        {
            printf("[DEBUG]:%d %d, %d %d\n", j, len-1-i, i, j);
            dest_arr[len-1-i][j] = src_arr[i][j];
        }
    }
    return 0;
}
