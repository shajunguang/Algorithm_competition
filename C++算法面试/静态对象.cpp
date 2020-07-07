#include<bits/stdc++.h>
using namespace std;
class A{
public:
    static int obj;
    A(double a,double b,double c){
        cout<<"Constructot called."<<endl;
        this->l=a;
        this->h=b;
        this->w=c;
        obj++;
    }
    double Volume(){
        return l*h*w;
    }
    static int getObj(){
        return obj;
    }

private:
    double l;
    double h;
    double w;
};
int A::obj=0; //初始化静态成员
int i=3;
int main()
{
    int i=0;
    cout<<i<<" "<<::i<<endl;
    cout<<"Init obj: "<<A::getObj()<<endl;
    A a1(3.3,2.3,1.2);
    A a2(1.2,1.4,1.5);
    //共享静态成员
    cout<<"Total obj: "<<a1.obj<<" "<<a2.obj<<" "<<A::obj<<endl;
    return 0;
}