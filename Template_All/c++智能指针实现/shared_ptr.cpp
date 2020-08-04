//shared_ptr的简单实现
//辅助类，记录基础对象，和引用计数
#include<iostream>
template<typename SmartPtr,typename Type>
class helper{
    friend   class SmartPtr;//定义智能指针类为友元，因为智能指针类需要直接操纵辅助类
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