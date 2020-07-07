//考察内存偏移   
#include<bits/stdc++.h>
using namespace std;
class A{
public:
    A(){m_a=1;m_b=2;}
    ~A(){};
    void fun(){printf("%d%d",m_a,m_b);}

private:
    int m_a;
    int m_b;

};
class B{
public:
    B(){m_c=3;}
    ~B(){};
    void fun(){printf("%d%c",m_c);}

private:
    int m_c;

};
int main()
{
    A a;
    B *pb=(B*)(&a);
    pb->fun();
    return 0;
}
