#include<bits/stdc++.h>
using namespace std;
class C
{
public:
    C(int i):m_Count(i){}
    int incr() const
    {
        return ++m_Count;
    }
    int decr() const {
        return --m_Count;
    }
private:
    mutable int m_Count;
};

int main()
{
    C c1(0),c2(10);
    for(int i=0,tmp;i<10;i++){
        tmp=c1.incr();
        cout<<setw(tmp)<<setfill(' ')<<tmp<<endl;
        tmp=c2.decr();
        cout<<setw(tmp)<<setfill(' ')<<tmp<<endl;
    }
    char *p; //64位系统,指针长度是8字节,8*8
    cout<<sizeof(p)<<endl;
    return 0;
}