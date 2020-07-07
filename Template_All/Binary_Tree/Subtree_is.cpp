#include<bits/stdc++.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
//太经典了递归,判断a树是否是b树的子结构
class Solution {
public:
    bool isSubtree(TreeNode* rt1,TreeNode* rt2){
        if(rt2==NULL) return true;
        if(rt1==NULL) return false;
        if(rt1->val==rt2->val) return isSubtree(rt1->left,rt2->left) && isSubtree(rt1->right,rt2->right);
        return false;
    }
    bool HasSubtree(TreeNode* rt1, TreeNode* rt2)
    {
        if(rt1==NULL || rt2==NULL) return false;
        return isSubtree(rt1,rt2) || HasSubtree(rt1->left,rt2) || HasSubtree(rt1->right,rt2);
    }
};