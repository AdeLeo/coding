#include <iostream>
#include <complex>
using namespace std;

class Base
{
    public:
        void a(int x)
        {
            cout << "Base::a(int)" << endl;
        }

        virtual void a(double x)
        {
            cout << "Base::a(double)" << endl;
        }

        virtual void b(int x)
        {
            cout << "Base::b(int)" << endl;
        }

        void c(int x)
        {
            cout << "Base::c(int)" << endl;
        }
};

class Derived:public Base
{
    public:
        void a(complex<double> x)
        {
            cout << "Derived::a(complex)" << endl;
        }

        void a(double x)
        {
            cout << "Derived::a(double)" << endl;
        }

        void a(int x)
        {
            cout << "Derived::a(int)" << endl;
        }

        void b(int x)
        {
            cout << "Derived::b(int)" << endl;
        }

        void c(int x)
        {
            cout << "Derived::c(int)" << endl;
        }
};

int main()
{
    Base b;
    Derived d;
    Base *pb = new Derived;

    //b.a(1.0);//Base::a(double)
    //d.a(1.0);//Derived::a(complex)
    pb->a(1.0);//Base::a(double)?
    //pb->a(complex<double>(1.0,2.0));

    b.b(10);//Base::b(int)
    d.b(10);//Derived::b(int)
    pb->b(10);//Derived::b(int)

    delete pb;

    return 0;
}
