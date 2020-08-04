#include<bits/stdc++.h>
using namespace std;
class A{
public:
    int id;
    A():id(0) {cout<<"default ctor.this="<<this<<" id="<<id<<endl;}
    explicit  A(int i):id(i) {cout<<"ctor.this="<<this<<" id="<<id<<endl;}
    ~A()  {cout<<"dtor.this="<<this<<" id="<<id<<endl;}
};

int main()
{
    int size=3;
    A* buf=new A[size]; //数组调用 new[]
    A* tmp = buf;
    cout<<"bnf="<<buf<<" tmp="<<tmp<<endl;

    for(int i=0;i<size;i++) new(tmp++)A(i); //placement new用法，不能通过指针直接调用构造函数的
    //palcement new 允许我们将object建构在已分配的内存中
    cout<<"buf="<<buf<<" tmp="<<tmp<<endl;

    delete [] buf; //次序逆反，buf[2] buf[1] buf[0]

    return 0;
}