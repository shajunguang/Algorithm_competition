#include<bits/stdc++.h>
using namespace std;

class A{
public:
    void foo()
    {
        printf("1\n");
    }
    virtual void fun()
    {
        printf("2\n");
    }
};
class B:public A{
public:
    void foo()
    {
        printf("3\n");
    }
    void fun() override
    {
        printf("4\n");
    }
};

int main()
{
    A a;B b;
    A *p=&a;
    p->foo();
    p->fun();
    p=&b;
    p->foo(); //没有虚构的函数，指针属于哪个类，就调用那个类的函数
    p->fun();
    B *ptr=(B*)&a;
    ptr->foo();
    ptr->fun();
    return 0;
}