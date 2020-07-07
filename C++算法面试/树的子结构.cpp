#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
    bool isSame(TreeNode* root1,TreeNode* root2){
        if(!root1 && !root2) return true;
        if(!root1 || !root2) return false;
        return root1->val==root2->val &&
               isSame(root1->left,root2->left) && isSame(root1->right,root2->right);
    }
    bool HasSubtree(TreeNode* root1, TreeNode* root2)
    {
        if(!root1 || !root2) return false;
        if(root1->val==root2->val)
            return isSame(root1,root2);
        return HasSubtree(root1->left,root2) || HasSubtree(root1->right,root2);
    }
};
int main()
{
    auto root1=new TreeNode(9);
    root1->left=new TreeNode(8);root1->right=new TreeNode(7);
    auto root2=new TreeNode(8);
    Solution res;
    if(res.HasSubtree(root1,root2)) cout<<1<<endl;
    return 0;
}