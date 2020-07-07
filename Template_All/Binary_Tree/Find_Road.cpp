#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void sort(vector<vector<int>>a){
    for(int i=1;i<a.size();i++){
        int key=a[i].size();
        int j=i-1;
        while(j>=0 && a[j].size()<key){
            swap(a[j+1],a[j]);
            j--;
        }
    }
}
int t=0;
vector<int> tmp;
vector<vector<int> > res;
void dfs(TreeNode* root,int e){
    if(root->left==NULL && root->right==NULL) {
        t+=root->val;tmp.push_back(root->val);
        if (t == e){
            res.push_back(tmp);
            return;
        }
        return;
    }
    if(t>e) return;
    if(t<e && root!=NULL) {tmp.push_back(root->val);t+=root->val;}
    if(root->left!=NULL) dfs(root->left,e);
    if(root->left!=NULL) {tmp.pop_back();t-=root->left->val;} //回溯过程
    if(root->right!=NULL)  dfs(root->right,e);
    if(root->right!=NULL) {tmp.pop_back();t-=root->right->val;} //回溯过程
}
vector<vector<int> > FindPath(TreeNode* root,int e){
    if(root==NULL) return{};
    dfs(root,e);
    sort(res);
    return res;
}
int main()
{
    TreeNode* root=new TreeNode(10);
    root->left=new TreeNode(5);root->right=new TreeNode(12);
    auto tmp1=root->left;
    tmp1->left=new TreeNode(7);tmp1->right=new TreeNode(4);
    FindPath(root,22);
    return 0;
}