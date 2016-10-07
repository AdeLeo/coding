#include <stdio.h>
#include <string.h>
/*
int c[20][20];

int lcs(const char *s1, const char *s2, int l1, int l2)
{
    int i = 1;
    int j = 1;

    for(i = 1; i <= l1; i++)
    {
        for(j = 1; j <= l2; j++)
        {
            if(s1[i] == s2[j])
                c[i][j] = lcs(s1, s2, i-1, j-1) + 1;
            else if(c[i-1][j] <= c[i][j-1])
                c[i][j] = c[i][j-1];
            else
                c[i][j] = c[i-1][j];
        }
    }

    return c[l1][l2];
}
*/
int max(int a, int b)
{
    return a > b ? a : b;
}

/*
 1)输入字符串“AGGTAB”和"GXTXAYB"。最后一个字符匹配的字符串。这样的LCS的长度可以写出：
 L("AGGTAB", "GXTXAYB") = 1 + L("AGGTA", "GXTXAY");
 2)输入字符串"ABCDGH"和"AEDFHR"。最后字符不为字符匹配。这样的LCS的长度可以写出：
 L("ABCDGH", "AEDFHR") = MAX(L("ABCDG", "AEDFHR"), L("
 ABCDGH", "AEDFH"))

 递归实现时间复杂度为2^n
 */
/*
int lcs(char *x, char *y, int m, int n)
{
    if(m == 0 || n == 0)
        return 0;
    if(x[m-1] == y[n-1])
        return 1 + lcs(x, y, m-1, n-1);
    else
        return max(lcs(x, y, m, n-1), lcs(x, y, m-1, n));
}
*/
/*
 用动态规划实现LCS问题
 */
int lcs(char *x, char *y, int m, int n)
{
    int l[m+1][n+1];
    int i, j;

    for(i = 0; i <= m; i++)
    {
        for(j = 0; j <= n; j++)
        {
            if(i == 0 || j == 0)
                l[i][j] = 0;

            else if(x[i-1] == y[j-1])
                l[i][j] = l[i-1][j-1] + 1;

            else
                l[i][j] = max(l[i-1][j], l[i][j-1]);
        }
    }

    return l[m][n];
}

int main()
{
    printf("%d\n", lcs("e", "abcdfkb", strlen("e"), strlen(" acdfkb")));

    return 0;
}
