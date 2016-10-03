#include <iostream>
#include <string>
#include <ctime>

using namespace std;

long fibonacci1(unsigned int n)
{
    if(n == 0 || n == 1)
        return n;
    else
        return fibonacci1(n-1) + fibonacci1(n-2);
}

long fibonacci2(unsigned int n)
{
    if(n == 0 || n == 1)
        return n;

    long firstItem = 0, secondItem = 1, fib = 0;
    while(--n > 0)
    {
        fib = firstItem + secondItem;
        firstItem = secondItem;
        secondItem = fib;
    }
    return fib;
}

class Matrix2by2
{
    public:
        Matrix2by2(
                long m_00=1,
                long m_01=1,
                long m_10=1,
                long m_11=0
                ):
            m00(m_00),
            m01(m_01),
            m10(m_10),
            m11(m_11)
    {}
        Matrix2by2 MatrixMultiply(const Matrix2by2& matrix1, const Matrix2by2& matrix2);
        Matrix2by2 MatrixPower(unsigned int n);
        long getM00(void)
        {
            return m00;
        }

    private:
        long m00;
        long m01;
        long m10;
        long m11;
};

Matrix2by2 Matrix2by2::MatrixMultiply(const Matrix2by2& matrix1, const Matrix2by2& matrix2)
{
    Matrix2by2 matrix12(1,1,1,0);

    matrix12.m00 = matrix1.m00 * matrix2.m00 + matrix1.m01 * matrix2.m10;
    matrix12.m10 = matrix1.m10 * matrix2.m00 + matrix1.m11 * matrix2.m10;
    matrix12.m11 = matrix1.m10 * matrix2.m01 + matrix1.m11 * matrix2.m11;
    matrix12.m01 = matrix1.m00 * matrix2.m01 + matrix1.m01 * matrix2.m11;

    return matrix12;
}

Matrix2by2 Matrix2by2::MatrixPower(unsigned int n)
{
    Matrix2by2 matrix(1,1,1,0);
    if(n == 1)
        return matrix;
    else if(n % 2 == 0)
    {
        matrix = MatrixPower(n/2);
        matrix = MatrixMultiply(matrix,matrix);
    }
    else if(n % 2 == 1)
    {
        matrix = MatrixPower((n-1) / 2);
        matrix = MatrixMultiply(matrix,matrix);
        matrix = MatrixMultiply(matrix,Matrix2by2(1,1,1,0));
    }
    return matrix;
}

long fibonacci3(unsigned int n)
{
    if(n == 0 || n == 1)
        return n;

    Matrix2by2 fibMatrix;
    return (fibMatrix.MatrixPower(n-1)).getM00();
}

int main()
{
    unsigned int n;
    int a, b;
    cout << "Enter a number:" << endl;
    cin >> n;
    while(n != 0)
    {
        a = clock();
        cout << fibonacci1(n) << endl;
        b = clock();
        cout << "fibo1:" << b-a << endl;
        a = clock();
        cout << fibonacci2(n) << endl;
        b = clock();
        cout << "fibo2:" << b-a << endl;
        a = clock();
        cout << fibonacci3(n) << endl;
        b = clock();
        cout << "fibo3:" << b-a << endl;
        cout << "Enter a number:" << endl;
        cin >> n;
    }
    return 0;
}
