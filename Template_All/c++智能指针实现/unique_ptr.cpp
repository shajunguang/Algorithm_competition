#include<iostream>
template<typename T>
class MyUniquePtr
{
public:
    explicit MyUniquePtr(T* ptr= nullptr):mPtr(ptr){}
    ~MyUniquePtr(){
        if(mPtr) delete mPtr;
    }
    MyUniquePtr(MyUniquePtr &&p) noexcept; //移动构造函数而非拷贝构造函数
    MyUniquePtr& operator=(MyUniquePtr &&p) noexcept ;//移动复制运算符 noexcept提示编译器不会产生异常

    MyUniquePtr(const MyUniquePtr&p)= delete; //这里也可以把其设置为私有成员
    MyUniquePtr& operator=(const MyUniquePtr &p)= delete;

    T*operator*()const noexcept {return *mPtr;}
    T&operator->()const noexcept {return mPtr;}
    explicit operator bool()const noexcept {return mPtr};

    void reset(T* q= nullptr) noexcept{
        if(q!=mPtr){
            if(mPtr) delete mPtr;
            mPtr = q;
        }
    }
    T* release()noexcept {
        T* res=mPtr;
        mPtr= nullptr;
        return res;
    }
    T* get()const noexcept {return mPtr};
    void swap(MyUniquePtr &p)noexcept{
        using std::swap;
        swap(mPtr,p.mPtr);
    }

private:
    T* mPtr;
};
template <typename T>
MyUniquePtr<T>& MyUniquePtr<T>::operator=(MyUniquePtr &&p) noexcept {
    swap(*this,p);
    return *this;
}
template <typename T>
MyUniquePtr<T>::MyUniquePtr(MyUniquePtr &&p)noexcept :mPtr(p.mPtr){
    p.mPtr= nullptr; //移动后原来的置为空
}
