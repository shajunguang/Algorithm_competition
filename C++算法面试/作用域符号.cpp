//::可解决命名冲突的问题
#include<bits/stdc++.h>
void dosomthing(){
    std::cout<<"Global function called!"<<std::endl;
}
namespace myspace{
    void dosomthing(){
        std::cout<<"My space function called!"<<std::endl;
    }
    class myclass{
    public:
        void dosomthing(){
            std::cout<<"My class function called!"<<std::endl;
        }
        void doother(){
            dosomthing(); //调用最近的类中的
            myspace::dosomthing(); //调用命名空间的
            ::dosomthing(); //调用全局范围内的
        }
    };
}
int main()
{
    myspace::myclass res;
    res.doother();
    return 0;
}