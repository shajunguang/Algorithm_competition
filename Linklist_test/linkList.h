//
// Created by liu on 19-9-2.
//

#include <iostream>
using namespace std;

template<class T>
struct Node
{
    T data;     //数据域，存放表元素
    Node *next; //指针域。指向下一个结点
};

template<class T>
class linkList
{
private:

    Node<T> *Head; //链表头指针

public:
    //构造函数、创建空链表
    linkList(void)
    {
        Head = new Node<T>;
        Head->next = NULL;
    }

    //析构函数、删除空链表
    ~linkList(void)
    {
        Node<T> *p;
        while(Head)
        {
            p = Head;//从头节点开始，依次释放结点
            Head = Head->next;
            delete p;
        }
        Head = NULL;//头结点指向空
    }

    //创建具有n个元素的线性链表
    void createList(int n)
    {                 //尾插法（正序）创建具有n个元素的线性表
        Node<T> *p,*s;  //设置工作指针，p指向尾结点
        p=Head;
        cout<<"请依次输入"<<n<<"个元素值"<<endl;
        for(int i=1;i<=n;i++)
        {
            s = new Node<T>;   //新建元素结点
            cin>>s->data;      //输入新建数据元素值
            s->next = p->next; //新结点链入表尾
            p->next = s;
            p = s;             //p是工作指针
        }
    }

    //在表中第i个位置插入元素
    void Insert(int i,T e)
    {
        int j = 0;
        Node<T> *p;
        p = Head;         //工作指针p指向头结点
        while(p && j<i-1) //查找第i-1个结点
        {
            p = p->next;
            j++;
        }
        if(!p || j>i-1)throw"位置异常";
        else
        {
            Node<T> *s;
            s = new Node<T>;  //创建新节点
            s->data = e;
            s->next = p->next;//结点s链到p结点之后
            p->next = s;
        }
    }

    T Delete(int i)//删除表中第i个元素
    {
        T x;
        Node<T> *p,*q;
        p = Head;  //从头结点开始查找
        int j = 0; //计数器初始化
        while(p->next && j<i-1)//p定位到删除结点的前驱
        {
            p = p->next;
            j++;
        }
        if(!p->next || j>i-1)throw"位置异常";//删除位置不合理
        else                                 //删除位置合理
        {
            q = p->next;      //暂存删除结点位置
            p->next = q->next;//从链表中摘除删除结点
            x = q->data;      //取删除数据元素的值
            delete q;         //释放删除点
            return x;         //返回删除元素的值
        }
    }

    //获取第i个元素的值
    T getElem(int i)
    {
        Node<T> *p;     //设置工作指针
        p = Head->next; //从首结点开始
        int j = 1;      //计数器初始化
        while(p && j<i) //定位到第i个元素结点
        {
            p = p->next;
            j++;
        }
        if(!p || j>i)
        {
            throw "位置异常";
        }
        else   //位置合理
        {
            return p->data;
        }
    }

    //在链表中查找值为e的元素
    int Locate(T e)
    {
        int j = 1;
        Node<T> *p;
        p = Head->next;
        while(p && p->data != e)
        {
            p = p->next;
            j++;
        }
        if(!p )//未找到，范围0
        {
            return 0;
        }
        else  //找到，返回位序
        {
            return j;
        }
    }

    //返回元素e的前驱
    T prior(T e)
    {
        Node<T> *p,*q;
        p = Head;
        q = p->next;
        while(q && q->data != e)
        {
            p = q;
            q = q->next;
        }
        if(p == Head)
        {
            throw "首元素，无前驱";
        }
        else if(!q)
        {
            throw "元素不存在";
        }
        else
        {
            return p->data;
        }
    }

    //测表空
    int Empty()
    {
        if(Head->next == NULL)
            return 1; //空表返回1
        else
            return 0; //非空表，返回0
    }

    //测表长
    int Length()
    {
        int len = 0; //计数器初始化
        Node<T> *p;  //设置头指针
        p=Head;      //指向头指针
        while(p->next)
        {
            len++;
            p = p->next;
        }
        return len;  //返回表长
    }

    //输出表元素
    void listDisplay()
    {
        Node<T> *p;
        p = Head->next;
        int i = 1;
        while(p)
        {
            cout<<i<<"\t";
            cout<<p->data<<endl;
            p = p->next;
            i++;
        }
    }
};