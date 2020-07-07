////
//// Created by liu on 19-9-26.
////
//
//#include <bits/stdc++.h>
//using namespace std;
//vector<int> ans;
//int res=0;
//const int MAXN=10,MAXM=1024;
//int tree[MAXN][MAXM];
//
//struct TreeNode {
//         int val;
//         TreeNode *left;
//         TreeNode *right;
//       TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
//
//// 根据前序遍历和中序遍历递归创造一颗树
//TreeNode* creatTree(vector<int> &pre, vector<int> &in){
//    if(pre.size()==0 || in.size()==0 || pre.size() != in.size())    return NULL;
//
//    TreeNode* root = new TreeNode(pre[0]);
//    int index = 0;
//    vector<int> left_pre, right_pre,left_in,right_in;
//
//    for(int i=0;i<in.size();i++)
//        if(root->val==in[i])
//            index = i;
//
//    for(int i=0;i<index;i++)
//    {
//        left_pre.push_back(pre[i+1]);
//        left_in.push_back(in[i]);
//    }
//
//    for(int j = index+1;j<pre.size();j++)
//    {
//        right_pre.push_back(pre[j]);
//        right_in.push_back(in[j]);
//    }
//
//    root->left = creatTree(left_pre,left_in);
//    root->right = creatTree(right_pre,right_in);
//    return root;
//}
//
//// 根据前序和中序遍历迭代创造一棵树(有问题）
//TreeNode* buildTree(vector<int> &pre, vector<int> &in){
//    if(!pre.size() || pre.size() != in.size()) return NULL;
//    TreeNode* root = new TreeNode(pre[0]);
//    stack<TreeNode*> stk;
//    stk.push(root);
//    for(int i=1,j=0;i<pre.size();i++){  // i代表前序的序号,j表示中序的序号
//        TreeNode* back = NULL, *cur = new TreeNode(pre[i]); // back表示回溯指针
//        //回溯过程,如果栈顶的元素和中序遍历元素一致,即可确定左右节点
//        while(stk.size() && stk.top()->val == in[j]) back=stk.top(),stk.pop(),j++;
//        if(back)    back->right = cur;
//        else    stk.top()->left = cur;
//        stk.push(cur);
//    }
//    return root;
//}
//
//void inorder(TreeNode* root){  // 递归输出中序遍历
//    if(!root)    return;
//    inorder(root->left);
//    cout<<root->val<<" ";
//    inorder(root->right);
//}
//
//void dfs(TreeNode* root) {  // 递归输出中序遍历
//    if (root) {
//        if (root->left)
//            dfs(root->left);
//        ans.push_back(root->val);
//        if (root->right)
//            dfs(root->right);
//    }
//}
//
//bool dfs_sym(TreeNode* p, TreeNode* q){  // 判断一棵树是否是对称的
//    if(!p && !q)    return true;
//    if(!p || !q)    return false;
//    return (p->val==q->val) && dfs_sym(p->left,q->right) && dfs_sym(p->right,q->left);
//}
//
////画出树
//void drawTree(vector<int> &pre,vector<int> &in){
//    //计算树的高度,表示要画的行数
//    int n = ceil(log(pre.size()+1.0)/log(2.0));
//    int r_i=0;
//    for(int i=0;i<in.size();i++)
//        if(in[i]==pre[0])   r_i=i;
//    for (int i = 0; i < in.size(); ++i) {
//        int index=0;
//        for (int j = 0; j < pre.size(); ++j)
//        {
//            if(j<=r_i && pre[j]==in[i])
//                index=ceil(log(j+1.0)/log(2.0));
//            else if(j>r_i && pre[j]==in[i])
//                index=ceil(log(j-r_i+1.0)/log(2.0));
//        }
//        tree[index][i]=in[i];
//    }
//    for(int i=0;i<n;i++)
//    {
//        for(int j=0;j<in.size();j++){
//            if(tree[i][j]==-1) printf(" ");
//            else printf("%d",tree[i][j]);
//        }
//        cout<<endl;
//    }
//}
//
//// 计算树中最长的路径
//int diameterOfBinaryTree(TreeNode* root){
//    if(!root) return 0;
//    auto left = diameterOfBinaryTree(root->left);
//    auto right = diameterOfBinaryTree(root->right);
//
//    res = max(res, left+right);
//    return max(left+1, right+1);
//}
//
//int main()
//{
//    int n;
//    vector<int> prev,in;
//    cout<<"请输入树的节点数目："<<endl;
//    cin>>n;
//    cout<<"请输入树的前序遍历："<<endl;
//    for(int i=0;i<n;i++)    { int t;cin>>t;prev.push_back(t);}
//    cout<<"请输入树的中序遍历："<<endl;
//    for(int i=0;i<n;i++)    { int t;cin>>t;in.push_back(t);}
//    //画树
////    memset(tree, -1, sizeof tree);
////    drawTree(prev,in);
//     //递归构造树
////    TreeNode* root = creatTree(prev,in);
////     TreeNode* root = creatTree(prev,in);
//     //迭代构造一棵树
//      TreeNode* root = buildTree(prev,in);
//      diameterOfBinaryTree(root);
//      cout<<res;
////    bool f = dfs_sym(root,root);
////    if(f)   cout<<"true"<<endl;
////    else cout<<"false"<<endl;
////    dfs(root);
////    for(auto p=ans.begin();p !=ans.end();p++)
////        cout<<*p<<" ";
////    cout<<"构建的树的中序遍历："<<endl;
////    inorder(root);
////    cout<<endl;
//    return 0;
//}