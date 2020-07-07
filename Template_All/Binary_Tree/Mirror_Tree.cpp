//镜像树
#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void change(TreeNode* &lt, TreeNode* &rt){ //这里注意加&,可以修改形参
    if(lt==NULL && rt==NULL) return;
    swap(lt,rt);
    if((lt!=NULL && rt!=NULL) || (lt!=NULL && rt==NULL)) change(lt->left,lt->right);
    if((lt!=NULL && rt!=NULL) || (lt==NULL && rt!=NULL)) change(rt->right,rt->left);
}
void Mirror(TreeNode *root) {
    if(root==NULL)return;
    change(root->left,root->right);
}
void Mirror1(TreeNode *root){
    if(root==NULL)return;
    swap(root->left,root->right);
    Mirror1(root->left);
    Mirror1(root->right);
}
int main()
{
    TreeNode *root=new TreeNode(8),*lt,*rt;
    root->left=new TreeNode(6);root->right=new TreeNode(10);
    lt=root->left;rt=root->right;
    lt->left=new TreeNode(5);
    rt->left=new TreeNode(9);rt->right=new TreeNode(11);
    Mirror1(root);
    return 0;
}