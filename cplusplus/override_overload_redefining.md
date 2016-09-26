#重载（overload）, 重写（override,也称覆盖），重定义（redefine，也称隐藏）
##重载
###指函数名相同，但是它的参数列表个数或顺序，类型不同。但是不能靠返回值类型判断。
	1、 相同的范围（在同一个作用域中）；
	2、 函数名字相同；
	3、 参数不同；
	4、 virtual关键字可有可无
	5、 返回值可以不同；

##重写（也称为覆盖override）
###是指派生类重新定义基类的虚函数，特征是：
	1、 不在同一个作用域（分别位于派生类与基类）；
	2、 函数名字相同；
	3、 参数相同；
	4、 基类必须有virtual关键字，不能有static。
	5、 返回值相同（或是协变），否则报错；
	6、 重写函数的访问修饰符可以不同。尽管virtual是private的，派生类中重写改写成pubic，protected也是可以的

##重定义（也称为隐藏）
	1、 不在同一个作用域（分别位于派生类与基类）
	2、 函数名字相同
	3、 返回值可以不同
	4、 参数不同。此时不论有无virtual关键字，基类的函数将被隐藏（注意区别覆盖）

***
***
#C++重载、重写、重定义区别
##一、重载（overload）
###概念：
函数有同样的名称，但是参数列表不相同的情形，这样的同名不同参数的函数之间，互相称为重载函数
###基本条件：
* 函数名必须相同
* 函数参数必须不相同，可以是参数类型或者参数顺序不同或者参数个数不同
* 函数返回值可以相同，也可以不相同

###注意：
* 只能通过不同的参数样式进行重载，例如：不同的参数类型，不同的参数个数，不同的参数顺序
* 不能通过访问权限、返回类型、抛出的异常进行重载
* 重载的函数应该在相同的作用域下

***
##二、重写（override）
###概念：
也称为覆盖，子类重新定义父类中有相同名称和参数的虚函数，主要在继承关系中出现。
###基本条件：
* 重写的函数和被重写的函数必须为virtual函数，分别位于基类和派生类中
* 重写的函数和被重写的函数函数名和函数参数必须一致
* 重写的函数和被重写的函数返回值相同，或者都返回指针或引用，并且派生类虚函数所返回的指针或引用的类型是基类中被替换的虚函数所返回的
* 指针或引用的类型的子类型

###注意：
* 重写的函数所抛出的异常必须和被重写的函数所抛出的异常一致，或者是其子类
* 重写的函数的访问修饰符可以不同于被重写的函数，如基类的virtual函数的修饰符为private，派生类改为public或protected也是可以的
* 静态方法不能被重写，也就是static和virtual不能同时使用
* 重写的函数可以带virtual关键字，也可以不带

###验证程序：
```cpp
class A {
};

class B : public A {
};

class C {
 public:
  virtual void Func1() {
    std::cout << "class C: func 1" << std::endl;
  }

  virtual A* Func2() {
    std::cout << "class C: func 2" << std::endl;
    return new A;
  }

  // ERROR:静态函数不能被声明为virtual，也就没办法被重写。
  // static virtual void FuncStatic() {}

  //由于Func3被声明为private，所以需要通过public函数来调用
  void ShowFunc3() {
    Func3();
  }

  virtual void Func4() {
    std::cout << "class C: func 4" << std::endl;
  }

 private:
  virtual void Func3() {
    std::cout << "class C: func 3" << std::endl;
  }
};

class D : public C {
 public:
  // OK: 重写C类Func1，可以不带virtual关键字
  void Func1() {
    std::cout << "class D: func 1" << std::endl;
  }

  // OK: 当返回值为指针或者引用时，返回值可以是父类返回值类型的子类
  virtual B* Func2() {
    std::cout << "class D: func 2" << std::endl;
    return new B;
  }

  // ERROR: 除上面的情况，返回值类型要和父类一直
  /*virtual bool Func2() {
  }*/

  // OK: 重写的函数的访问修饰符可以不同于被重写的函数
  virtual void Func3() {
    std::cout << "class D: func 3" << std::endl;
  }

 private:
  // OK: 重写的函数的访问修饰符可以不同于被重写的函数
  virtual void Func4() {
    std::cout << "class D: func 4" << std::endl;
  }
};

int _tmain(int argc, _TCHAR* argv[])
{
  C* c = new D;
  c->Func1();
  c->Func2();
  c->ShowFunc3();
  c->Func4();
  return 0;
}
```
###输出：
```
class D: func 1
class D: func 2
class D: func 3
class D: func 4
```

##三、重定义（redefining）
###概念：
也叫隐藏，子类重新定义父类中的非虚函数，屏蔽了父类的同名函数
###基本条件：
* 被隐藏的函数之间作用域不相同

###注意：
* 子类和父类的函数名称相同，但参数不同，此时不管父类函数是不是virtual函数，都将被隐藏
* 子类和父类的函数名称相同，参数也相同，但是父类函数不是virtual函数，父类的函数将被隐藏

###验证程序：
```
class A {
public:
  void Func1(int a) {
      std::cout << "class A: Func1" << std::endl;
  }

  virtual void Func2(int a) {
      std::cout << "class A: Func2" << std::endl;
  }
};

class B : public A {
public:
  // 将会重定义父类的方法
  void Func1(int a) {
      std::cout << "class B: Func1" << std::endl;
  }

  // 将会重写(override)父类方法
  void Func2(int a) {
    std::cout << "class B: Func2-1" << std::endl;
  }

  // 将会重定义父类的方法
  void Func2(int a, int b) {
    std::cout << "class B: Func2-2" << std::endl;
  }
};

int _tmain(int argc, _TCHAR* argv[])
{
  B* b = new B;
  b->Func1(1);
  b->Func2(1);
  b->Func2(1, 1);
  return 0;
}
```

###输出：
```
class B: Func1
class B: Func2-1
class B: Func2-2
```
***
引用：[GLGJing's BLOG](http://glgjing.github.io/)

