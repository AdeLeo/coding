#include <iostream>
#include <stdio.h>
using namespace std;

/*
 解析：
 两个知识点：
 一、类型转换问题：
 unsigned char b = ~a>>4+1,计算这个表达式的时候，编译器会先把a和4的值转换为int类型（即所谓的整数提升）后在进行计算，当计算结果出来之后，再把结果转换成unsigned char赋值给b。
 二、运算符的优先级问题：
 因为"~"的优先级比">>"和"+"高
 结果应该是2，为什么运行结果是250呢？
 在调试过程中进入汇编指令，发现高级语句转换成汇编代码之后，是先执行取反在移位的。我们看到eax使16位寄存器，于是在机器中0xA5的寄存中表达是0000 0000 1010 0101，取反是1111 1111 0101 1010，那么右移5位是0000 0111 1111 1010，由于是unsigned char型只能表示低八位的数值，即250
 */

int main()
{
    unsigned char a = 0xA5;
    unsigned char b = ~a>>4+1;
    printf("b=%d\n",b);//b=250
    return 0;
}
