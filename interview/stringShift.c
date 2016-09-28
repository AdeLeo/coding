#include <stdio.h>

/*************************
    暴力移位法
 *************************/
void leftShiftOne(char *s, int n)
{
    char t = s[0];
    int i = 0;

    for(i = 0; i < n; i++)
    {
        s[i - 1] = s[i];
    }

    s[i - 1] = t;
}

void leftShift(char *s, int n, int m)
{
    while(m--)
    {
        leftShiftOne(s, n);
    }
}



