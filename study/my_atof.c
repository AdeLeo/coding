#include <stdio.h>
#include <assert.h>

int is_space(int ch)
{
    return ch == ' ';
}

int is_digit(int ch)
{
    return ch >= '0' && ch <= '9';
}

double atof(char *s)
{
    double power, value;
    int i, sign;
    assert(s != NULL);
    for(i = 0; is_space(s[i]); i++);

    sign = ((s[i] == '-') ? -1:1);
    if(s[i] == '-' || s[i] == '+')
        i++;

    for(value = 0.0; is_digit(s[i]); i++)
        value = value*10.0 + (s[i] - '0');

    if(s[i] == '.')
        i++;

    for(power = 1.0; is_digit(s[i]); i++)
    {
        value = value *10.0 + (s[i] - '0');
        power *= 10;
    }

    return sign * value / power;
}

int main()
{
    double sum;
    char buf[] = "110.23";
    sum = atof(buf);
    printf("%g\n", sum);
    return 0;
}
