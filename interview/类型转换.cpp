#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

/*
 浮点数在内存中的存储方式
 */

int main()
{
    float a = 1.0f;
    cout << "(int)a:" << (int)a << endl;//1
    cout << "&a:" << &a << endl;//0x7ffec0000000
    cout << "(int&)a:" << (int&)a << endl;//1065353216
    cout << boolalpha << ((int)a == (int&)a) << endl;//false
    float b = 0.0f;
    cout << "(int)b:" << (int)b << endl;//0
    cout << "&b:" << &b << endl;//0x7ffec1000000
    cout << "(int&)b:" << (int&)b << endl;//0
    cout << boolalpha << ((int)b == (int&)b) << endl;//true
    return 0;
}
