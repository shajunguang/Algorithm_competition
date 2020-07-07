//对同一块内存进行两次删除，这是因为vector是进行浅复制，加上复制拷贝函数即可
#include<bits/stdc++.h>
using namespace std;
class CDemo{
public:
    CDemo():str(NULL){};
    CDemo(const CDemo &cd){
        this->str=new char[strlen(cd.str)+1]; //再申请一块内存，深度拷贝
        strcpy(str,cd.str);
    }
    ~CDemo(){
        if(str) {
            static int i=0;
            cout<<"&CDemo"<<i++<<"="<<(int*)this<<",   str="<<(int*)str<<endl;
            delete[]str;
        }
    }
    char* str;
};
int main()
{
    CDemo dl;
    dl.str=new char[32];//申请空间
    strcpy(dl.str,"trend micro");
    vector<CDemo>*a1 = new vector<CDemo>();
    a1->push_back(dl);
    delete a1; //同时元素也要释放，也就是dl也要释放

    return 0;
}