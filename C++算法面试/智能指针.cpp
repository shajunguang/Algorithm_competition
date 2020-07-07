//内存泄露，申请空间并没有释放，一般new delete成对出现
//另外一点，对于指针，释放后，记得把指针值赋位nullptr否则成为悬挂指针
#include<bits/stdc++.h>
using namespace std;

//shared_ptr的简单实现
//辅助类，记录基础对象，和引用计数
template<typename SmartPtr,typename Type>
class helper{
    friend  SmartPtr;//定义智能指针类为友元，因为智能指针类需要直接操纵辅助类
    helper(Type* _p):p(_p),use(1){}
    ~helper(){delete p;}
    Type* p; //基础对象
    size_t use;
};
template <typename Type>
class SmartPtr{
public:
    SmartPtr(Type* p):ptrCnt(new helper<SmartPtr,Type>(p)){};
    //拷贝构造函数
    SmartPtr(const SmartPtr& orig):ptrCnt(orig.ptrCnt){
        ++ptrCnt->use;
    }
    SmartPtr&operator=(const SmartPtr& rhs){
        ++rhs.ptrCnt->use;
        if(--ptrCnt->use==0)
            delete ptrCnt;
        ptrCnt=rhs.ptrCnt;
        return *this;
    }
    ~SmartPtr(){
        if(--ptrCnt->use==0)
            delete ptrCnt;
    }
private:
    helper<SmartPtr, Type> *ptrCnt;
};


void GetMemory(char**p,int num){
    *p=(char*)malloc(sizeof(char)* num);
}
int fun(int a,int b){
    if(a>b) return(a);
    else return(b);
}
int func(int a){
    int b=1;
    static int c=2;
    return --a + ++b + c++;
}
int main(){
    cout<<func(3);
    cout<<func(3);
    cout<<func(3)<<endl;
    unsigned int time=0x80402008;
    printf("%x, %x, %x",(char)time,*((char*)&time+1),*((char*)&time+2));
    char* str=NULL;
    int r=fun(15,8);
    cout<<r<<endl;
    GetMemory(&str,100);
    strcpy(str,"hello");
    cout<<str<<endl;
    char *st[]={"Welcome","to","Zhejiang","DAHUA"};
    char **p=st+1;
    st[0]=(*p++)+2; //st[0]="/0";
    cout<<st[0]<<endl;
    st[1]=*(p+1); //st[1]="DAHUA";
    cout<<st[1]<<endl;
    st[2]=p[1]+3;// st[2]="UA";
    cout<<st[2]<<endl;
    st[3]=p[0]-(st[2]-st[1]); //指针变量相减，结果数组间隔多少个元素
    cout<<p[0]<<st[3]<<endl;
    int a[3]={1,2,3};
    int *p1=a;int *p2=a+2;
    cout<<p2-p1<<endl;

    return 0;
}