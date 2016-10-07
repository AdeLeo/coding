#include <iostream>
using namespace std;

int fib[100];

int fibonacci(int n)
{
    static int cnt = 2;

    int i = 0;
    fib[0] = 1;
    fib[1] = 1;

    for(i = cnt; i <= n; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    if(cnt < n)
        cnt = n;

    return fib[n];
}

int main()
{
    int n;

    while(cin >> n)
    {
        cout << "fibo(" << n << ")" << fibonacci(n) << endl;
    }

    return 0;
}
