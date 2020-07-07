#ifndef ALGORITHM_COMPETITION_BITREE_H
#define ALGORITHM_COMPETITION_BITREE_H
#include<bits/stdc++.h>
using namespace std;
typedef char ElemType;

typedef struct BiTNode{
    ElemType val;
    BiTNode* left;
    BiTNode* right;
    BiTNode(int x):val(x),left(NULL),right(NULL){}
}BiTNode,*BiTree;
//构建一个树,前序遍历
void CreateBiTree(BiTree *root){
    char c;

    scanf("%c",&c);
    if('#'==c) *root=NULL;
    else {
        *root=new BiTNode(c);
        CreateBiTree(&(*root)->left);
        CreateBiTree(&(*root)->right);
    }
}
//前序遍历
void PreOrderTraverse(BiTree root,int level){
    if(root==NULL) return;

    cout<<level<<":"<<root->val<<" ";

    PreOrderTraverse(root->left,level+1);
    PreOrderTraverse(root->right,level+1);
}
//中序遍历
void InOrderTraverse(BiTree root,int level){
    if(root==NULL)return;
    InOrderTraverse(root->left,level+1);
    cout<<level<<":"<<root->val<<" ";
    InOrderTraverse(root->right,level+1);
}
//后序遍历
void BackOrderTraverse(BiTree root,int level){
    if(root==NULL)return;
    BackOrderTraverse(root->left,level+1);
    BackOrderTraverse(root->right,level+1);
    cout<<level<<":"<<root->val<<" ";
}

//层次遍历
vector<vector<int>> levelOrder(BiTree root) {
    vector<vector<int>> ans;
    if(root==NULL) return ans;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int count=q.size();
        vector<int> res;
        while(count>0){
            auto node=q.front();q.pop();
            res.push_back(node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
            count--;
        }
        ans.push_back(res);
    }
    return ans;
}
#endif //ALGORITHM_COMPETITION_BITREE_H
