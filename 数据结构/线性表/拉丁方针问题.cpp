//n*n的方针里面存放1-n要求每行每列不存在相同元素，数独，要求用循环链表
// 1 2 3 对应坐标:(0,0)->(1,2)->(2,1) 1的位置
// 2 3 1         (0,1)->(1,0)->(2,2) 2的位置
// 3 1 2         (0,2)->(1,1)->(2,0) 发现规律纵坐标:0->1->2 2->0->1 1->2->0不就是循环链表吗？

//或则循环打印即可
#include<bits/stdc++.h>
using namespace std;
int n;
int matrix[100][100];
struct Node{
    int data;
    Node* next;
};

void createList(Node* &head){
    int i;
    cin>>n;
    Node* rear; //尾指针
    Node* temp;
    for(i=0;i<n;i++){
        if(head==NULL){
            head=(Node*)malloc(sizeof(Node));
            head->data=i;
            head->next=head;
            rear=head;
        }else{
            temp=(Node*)malloc(sizeof(Node));
            temp->data=i;
            rear->next=temp;
            temp->next=head;
            rear=temp;
        }
    }
}

int main()
{
    Node* head=NULL;
    createList(head);
    auto temp=head;
    /*
    int j;
    for(int i=0;i<n;i++)
        for(j=1;j<=n;j++){
            matrix[i][temp->data]=j;
            if(j<n) temp=temp->next;
        }
    for(int i=0;i<n;i++) {
        for (j = 0; j < n; j++)
            cout << matrix[i][j] << " ";
        cout<<endl;
    }
     */
    for(int j=0;j<n;j++) {
        for (int i = 0; i < n; i++) {
            cout << temp->data+1 << " ";
            temp = temp->next;
        }
        cout<<endl;
        temp=temp->next;
    }
    return 0;
}