#include <stdio.h>
#include <assert.h>
#include <string.h>

void reverse(char *str)
{
    assert(str != NULL);

    int len = strlen(str);
    char tmp[len + 1];

    int i = len;
    char *s = tmp;

    for(i = len; i > 0; i--)
    {
        if(str[i] == ' ')
        {
            strcpy(s, str+i+1);
            s += strlen(str+i);
            str[i] = '\0';
        }
    }

    strcpy(s, str);

    for(i = 0; i < len; i++)
    {
        if(tmp[i] == '\0')
        {
            tmp[i] = ' ';
        }
    }

    strcpy(str, tmp);
}

int main()
{
    char str[] = "I am a student";

    printf("BEFORE REVERSE:\n%s\n", str);

    reverse(str);

    printf("AFTER REVERSE:\n%s\n", str);

    return 0;
}
