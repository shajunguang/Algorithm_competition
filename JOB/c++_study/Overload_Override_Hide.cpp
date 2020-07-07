/*
 重载、覆盖、隐藏的区别
 成员函数被重载的特征：
（1）相同的范围（在同一个类）；
（2）函数名字相同；
（3）参数不同。
（4）virtual关键字可有可无。
覆盖值派生类函数覆盖基类函数，特征：
（1）不同的范围（分别位于派生类与基类）；
（2）函数名字相同；
（3）参数相同；
（4）基类函数必须有virtual关键字。
“隐藏”是指派生类的函数屏蔽了与其同名的基类函数，规则如下：
（1）如果派生类的函数与基类函数同名，但参数不同。此时不论有无关键字virtual，基类的函数将被隐藏（注意别与重载混淆）。
（2）如果派生类的函数与基类的函数同名，并且参数也相同，但是基类函数没有virtual关键字。此时，基类的函数被隐藏（注意别与覆盖混淆）。

3种情况怎么执行：
1.重载：看参数
2.隐藏：用什么就调用什么
3.覆盖：调用派生类。
 */
#include<bits/stdc++.h>
using namespace std;
class Base{
public:
    virtual void f(float x){ cout<<"Base::f(float)"<<x<<endl; }
    void g(float x){ cout<<"Base::g(float)"<<x<<endl; }
    void h(float x){ cout<<"Base::h(float)"<<x<<endl; }
};
class Derived: public Base{
public:
    virtual void f(float x){ cout<<"Derived::f(float)"<<x<<endl;}
    void g(int x){ cout<<"Derived::g(int)"<<x<<endl;}
    void h(float x){ cout<<"Derived::h(float)"<<x<<endl;}
};
//f是覆盖（virtual），g是隐藏，不是重载（同类），h是隐藏不是覆盖（关键字）。
int main()
{
    Derived d;
    Base *pb=&d;
    Derived *pd=&d;
    pb->f(3.14f);
    pd->f(3.14f);
    pb->g(3.14f); //后面几种决定于指针类别
    pd->g(3.14f);
    pb->h(3.14f);
    pd->h(3.14f);
    return 0;
}