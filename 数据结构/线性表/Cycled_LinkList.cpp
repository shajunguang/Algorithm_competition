#include "LinkList.h"

//构建循环链表
void createCycleLinkList(LinkList &rear){
    int i;
    Node* head=new Node(0);
    LinkList target=head;
    printf("请输入初始化元素,0结束：\n");
    while(1){
        cin>>i;
        if(!i) break;
        Node* temp=(LinkList)malloc(sizeof(Node));
        temp->data=i;
        target->next=temp;
        target=temp;
    }
    target->next=head;
    rear=target;
}
void ds_init(Node **pNode){
    int item;
    Node *temp;
    Node *target;

    printf("输入节点的值，0结束：\n");

    while(1){
        scanf("%d",&item);
        fflush(stdin);

        if(item==0) return;

        if((*pNode)==NULL){ //循环表只有一个节点
            *pNode = (Node*)malloc(sizeof(Node));
            if(!(*pNode)) exit(0);
            (*pNode)->data=item;
            (*pNode)->next=*pNode;
        }else{
            //找到尾结点
            for(target=(*pNode);target->next!=(*pNode);target=target->next);

            temp=(LinkList)malloc(sizeof(Node));
            if(!temp) exit(0);

            temp->data=item;
            temp->next=(*pNode);
            target->next=temp;
        }
    }
}
//插入元素
void Insert_List(Node **pNode, int i){
    int item;
    Node* temp;
    Node* target;
    int j=1;

    printf("输入要插入的元素：");
    scanf("%d",&item);

    if(i==1){
        temp=(LinkList)malloc(sizeof(Node));

        if(!temp)exit(0);

        temp->data=item;
        //寻找尾结点
        for(target=(*pNode);target!=(*pNode);target=target->next);
        temp->next=(*pNode);
        target->next=temp;
        *pNode=temp;
    }else{
        target=*pNode;
        while(j<i-1) target=target->next,j++;

        temp=(LinkList)malloc(sizeof(Node));

        if(!temp)exit(0);

        temp->data=item;
        temp->next=target->next;
        target->next=temp;
    }
}
//删除元素
void List_Delete(Node **pNode,int i){
    Node* target;
    Node* temp;
    int j=1;
    if(i==1){
        for(target=(*pNode);target->next!=(*pNode);target=target->next);

        temp=*pNode;//释放被删除元素
        *pNode=(*pNode)->next;
        target->next=*pNode;
        free(temp);
    }else{
        target=*pNode;
        while(j<i-1) target=target->next,j++;

        temp=target->next;
        target->next=temp->next;
        free(temp);
    }
}
//返回结点所在位置
int ds_search(Node *pNode,int elem){
    Node* target;
    int i=1;
    for(target=pNode;target->data!=elem && target->next!=pNode;i++)target->next=target;
    if(target->next==pNode) return -1; //不存在元素
    return i;
}
//约瑟夫问题，圆圈报数，m循环出去
void Print_Order(LinkList pNode,int m){
    LinkList temp=pNode;
    int i;
    while(temp){
        i=1;
        for(;i<m-1;i++) temp=temp->next;
        auto p=temp->next;temp->next=p->next;
        cout<<p->data<<" ";
        if(temp==p) return;
        temp=p->next;
        free(p);
    }
}
//递归写法约瑟夫
void Print_order(LinkList pNode,int m){
    LinkList temp=pNode;
    if(temp==temp->next){
        cout<<temp->data;
        return;
    }
    int i=1;
    while(i<m-1) temp=temp->next,i++;
    auto p=temp->next;temp->next=p->next;
    cout<<p->data<<" ";
    free(p);
    Print_order(temp->next,m);
}
int main()
{
    Node* rear=NULL;
    //createCycleLinkList(rear);
    ds_init(&rear);
    //Insert_List(&rear,2);
    //List_Delete(&rear,2);
    //cout<<ds_search(rear,5)<<endl;
    Print_order(rear,3);
    return 0;
}