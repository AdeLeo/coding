#include <stdio.h>
#include <string.h>
#include <assert.h>

#define ARR_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))
#define ISUPPER(c) (c >= 'A' && c <= 'Z')

char table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void deciper(char *str);

int main()
{
    char str[100];
    
    while(fgets(str, 100, stdin) && (strncmp(str, "ENDOFINPUT", strlen("ENDOFINPUT")) != 0))
    {
        fgets(str, 100, stdin);
        deciper(str);
        printf("%s", str);
        fgets(str, 100, stdin);
    }

    return 0;
}

static int findPos(int ch)
{
    int i = 0;
    
    for(i = 0; i < ARR_SIZE(table); i++)
    {
        if(table[i] == ch)
            return i;
    }

    return -1;
}

void deciper(char *str)
{
    assert(str);
    while(*str != '\0')
    {
        if(ISUPPER(*str))
        {
            *str = table[(findPos(*str) + strlen(table) - 5) % strlen(table)]; 
        }
        
        ++str;
    }
}
