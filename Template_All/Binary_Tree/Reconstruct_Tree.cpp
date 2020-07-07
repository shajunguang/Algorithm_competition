//使用先序遍历和中序遍历构造二叉树
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
    TreeNode *head = NULL;
     if(!pre.empty())   head=new TreeNode(pre[0]);
    if(pre.empty() && vin.empty()) return head;
    vector<int> p1;vector<int>p2;vector<int> in1;vector<int>in2;
    int i;
    for(i=0;i<(int)vin.size();i++) if(vin[i]==pre[0]) break;
    for(int j=1;j<=i;j++) p1.push_back(pre[j]);for(int j=i+1;j<(int)pre.size();j++) p2.push_back(pre[j]);
    for(int j=0;j<i;j++) in1.push_back(vin[j]);for(int j=i+1;j<(int)vin.size();j++) in2.push_back(vin[j]);
    head->left=reConstructBinaryTree(p1,in1);
    head->right=reConstructBinaryTree(p2,in2);
    return head;
}
int main()
{
    vector<int> pre={1,2,4,7,3,5,6,8};
    vector<int> vin={4,7,2,1,5,3,8,6};
    auto head=reConstructBinaryTree(pre,vin);
    return 0;
}