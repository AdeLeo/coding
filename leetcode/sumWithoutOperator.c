#include <stdio.h>

/*
    题目描述：
        写一个函数，求两个整数之和，要求在函数体内不得使用“+，-，*，/”四则运算

    样例输入：
        3 4
        7 9

    样例输出：
        7
        16
 */

/*
    位运算
        用异或可以模拟不带进位的加法运算，因为异或相同为0，不同为1，正好与不带进位的加法结果相同

    怎么判断进位
        进位的产生主要是1+1=10，我们看到与操作可以判断两个位是不是需要进位，可见用与运算可以模拟出每一位是否有进位

    怎么表示进位
        进位无非是进到上一位去，因此我们直接与的结果左移移位即得进位

    由此我们得到了两个数，
        一个是异或运算得出的不带进位的结果
        一个是两个相加的所有进位

    当我们反复的将两个数进行加法操作时，直到没有进位的时候，那么结果就是我们想要的

    过程如下：
    
    5 + 7 = 12

    5==> 101
    7==> 111

    1、相加各位的值，不算进位，得到010，二进制每位相加就相当于各位做异或操作，101^111=010
    2、计算进位的值，得到1010，相当于各位做与操作得到101，在向左移动一位得到1010
    3、重复上述两步，各位相加010^1010=1000,进位值为100
    4、继续重复上述两步：1000^100=1100, 进位值为0，跳出循环
 */

int add(int left, int right)
{
    int tmp = 0;

    while(right != 0)
    {
        tmp = left ^ right;
        right = (left & right) << 1;
        left = tmp;
    }

    return tmp;
}

int addWithRecur(int left, int right)
{
    return right == 0 ? left : addWithRecur(left ^ right, (left & right) << 1);
}

int main()
{
    int a = 0, b = 0;

    while(scanf("%d %d", &a, &b) != EOF)
        printf("%d+%d=%d\n", a, b, addWithRecur(a, b));

    return 0;
}

