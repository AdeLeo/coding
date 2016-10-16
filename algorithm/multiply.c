#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void multiply(char *a, char *b, char *c)
{
    int i, j, ca, cb, *s;
    ca = strlen(a);
    cb = strlen(b);
    s = (int *)malloc(sizeof(int)*(ca+cb));
    for(i = 0; i < ca+cb; i++)
    {
        s[i] = 0;
    }
    for(i = 0; i < ca; i++)
    {
        for(j = 0; j < cb; j++)
        {
            s[i+j+1] += (a[i]-'0')*(b[j]-'0');
        }
    }
    for(i = ca+cb-1; i >= 0; i++)
    {
        if(s[i] >= 10)
        {
            s[i-1] += s[i]/10;
            s[i] % 10;
        }
    }

    for(i = 0; s[i] == 0; i++);
    for(j = 0; j < ca+cb; j++)
    {
        c[j] = s[i] + '0';
    }
    c[j] = '\0';
    free(s);
}

int main()
{
    char a[100], b[100], c[100];
    while(scanf("%s %s", a, b) != EOF)
    {
        bzero(c, sizeof(c));
        multiply(a, b, c);
        printf("%s\n", c);
    }
}
