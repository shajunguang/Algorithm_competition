#include<bits/stdc++.h>
using namespace std;

struct Tree{
    int val;
    Tree *left;
    Tree *right;
    Tree(int x):val(x),left(NULL),right(NULL){} //构造函数
};
void change(Tree *&l,Tree *&r){
    if(l==NULL && r==NULL) return;
    swap(l,r);
    if(l!=NULL) change(l->left,l->right);
    if(r!=NULL) change(r->left,r->right);
}

Tree* Invert_Tree(Tree *head){
    if(head==NULL) return head;
    change(head->left,head->right);
    return head;
}
Tree* Invert_Tree1(Tree *head){
    if(head==NULL) return head;
    Tree* temp=head->left;
    head->left=Invert_Tree(head->right);//左子树等于反转后的右子树
    head->right=Invert_Tree(temp);//右子树等于反转后的左子树，注意这里temp
    return head;
}
int main()
{
    Tree *head=new Tree(4);
    head->left=new Tree(2);head->left->left=new Tree(1);//head->left->right=new Tree(3);
    head->right=new Tree(7);head->right->left=new Tree(6);head->right->right=new Tree(9);
    head=Invert_Tree1(head);
    return 0;
}