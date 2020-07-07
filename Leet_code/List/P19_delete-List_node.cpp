//
// Created by liu on 19-9-25.
//

//#include <bits/stdc++.h>
//using namespace std;
//
//struct Node{
//    int data;
//    Node* next;
//    Node(int x): data(x),next(NULL){}
//};
//    //创建具有n个元素的线性链表
//    void createList(Node* head,int n) {                 //尾插法（正序）创建具有n个元素的线性表
//        Node *p, *s;  //设置工作指针，p指向尾结点
//        p = head;
//        cout << "请依次输入" << n << "个元素值" << endl;
//        cin>>head->data;
//        for (int i = 1; i < n; i++) {
//            s = new Node(0);   //新建元素结点
//            cin >> s->data;      //输入新建数据元素值
//            s->next = p->next; //新结点链入表尾
//            p->next = s;
//            p = s;             //p是工作指针
//        }
//    }
//    void listDisplay(Node* head)
//    {
//        Node *p;
//        p = head;
//        //int i = 1;
//        while(p)
//        {
//            //cout<<i<<"\t"; //输出节点下标
//            cout<<p->data<<" ";
//            p = p->next;
//            //i++;
//        }
//        cout<<endl;
//    }
//    Node* removeNthFromEnd(Node* head, int n) {
//        auto dummy = new Node(-1);
//        dummy->next = head;
//        auto first = dummy, second = dummy;
//        while(n--)  first = first->next;
//        while(first->next){
//            first = first->next;
//            second = second->next;
//        }
//        second->next = second->next->next;
//        return dummy->next;
//    }
//
//Node* reverseList(Node* head) {
//    // 迭代版本
//    // if(!head)   return NULL;
//    // auto a=head, b=head->next;
//    // head->next=NULL;
//    // while(b){
//    //     auto c = b->next;
//    //     b->next=a;
//    //     a=b;b=c;
//    // }
//    // return a;
//    Node* prev = NULL; //这个表示node指针指向NULL，
//    //若不加*号就表示结构体元素，存在val，*next两个属性
//    auto curr = head;
//    while (curr) {
//        auto nextTemp = curr->next;
//        curr->next = prev;
//        prev = curr;
//        curr = nextTemp;
//    }
//    return prev;
//    // 递归版本
//    // if(!head || !head->next)    return head;
//    // auto p = reverseList(head->next);
//    // head->next->next=head;
//    // head->next=NULL;
//    // return p;
//}
//
//int main()
//{
//    Node* head = new Node(0);
//    head->next=NULL;
//    createList(head,5);
//    printf("初始链表元素：\n");
//    listDisplay(head);
//    head = removeNthFromEnd(head,2);
//    //head = reverseList(head);
//    printf("变化后的链表元素：\n");
//    listDisplay(head);
//}