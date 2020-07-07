#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* Convert(TreeNode* root)
{
    if(root==NULL)return root;
    if(root->left==NULL && root->right==NULL) return root;
    auto lt=Convert(root->left);
    auto p=lt;
    while(p!=NULL && p->right!=NULL) p=p->right;
    if(p!=NULL){
        p->right=root;
        root->left=p;
    }
    auto rt=Convert(root->right);
    if(rt!=NULL){
        rt->left=root;
        root->right=rt;
    }
    return lt==NULL?root:lt; //lt还要用，因此前面修改指针的时候，要用替代指针修改，精髓了！
}
int main()
{
    TreeNode* root=new TreeNode(10);
    root->left=new TreeNode(5);root->right=new TreeNode(12);
    auto tmp1=root->left;
    tmp1->left=new TreeNode(4);tmp1->right=new TreeNode(7);
    root=Convert(root);
    return 0;
}