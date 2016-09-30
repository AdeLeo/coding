#include <iostream>
#include <string>

using namespace std;

#define positiveMod(m, n) ((m) % (n) + (n)) % (n)

/*
    左旋字符串str,m为负数时表示右旋abs(m)个字母
 */


void rotate(string &str, int m)
{
    if(str.length() == 0)
        return;

    int n = str.length();
    //处理大于str长度及m为负数的情况，positiveMod可以取得m为负数时对n取余得到正数
    m = positiveMod(m, n);

    if(m == 0)
        return;

    int p1 = 0, p2 = m;
    int round;
    //p2当前所指和之后的m-1个字母共m个字母，就可以和p2前面的m个字母交换
    while(p2 + m - 1 < n)
    {
        round = m;
        while(round--)
        {
            swap(str[p1], str[p2]);
            p1++;
            p2++;
        }
    }

    //剩下的不足m个字母逐个交换
    int r = n - p2;
    while(r--)
    {
        int i = p2;
        while(i > p2)
        {
            swap(str[i], str[i-1]);
            i--;
        }
        p2++;
        p1++;
    }
}

