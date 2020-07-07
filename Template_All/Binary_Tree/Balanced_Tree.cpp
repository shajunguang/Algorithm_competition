//判断是否是平衡二叉树，其实就是左右子树深度不能差1以上
#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int depth(TreeNode* root){
    if(root==NULL)return 0;
    int left=depth(root->left);
    if(left==-1) return -1;//如果不满足平衡二叉树性质，直接返回-1,剪枝部分
    int right=depth(root->right);
    if(right==-1) return -1;
    return abs(left-right)>1?-1:1+max(left,right);
}
bool isBalanced_Tree(TreeNode* root){
    return depth(root)!=-1;
}