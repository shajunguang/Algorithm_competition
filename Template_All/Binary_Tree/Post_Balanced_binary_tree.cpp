//根据后序遍历，判断是否是平衡二叉树
#include<bits/stdc++.h>
using namespace std;
bool judge(vector<int>& a, int l, int r){
    if(l >= r) return true;
    int i = r;
    while(i > l && a[i - 1] > a[r]) --i;
    for(int j = i - 1; j >= l; --j) if(a[j] > a[r]) return false;
    return judge(a, l, i - 1) && (judge(a, i, r - 1));
}
bool VerifySquenceOfBST(vector<int> a) {
    if(!(int)a.size()) return false;
    return judge(a, 0, a.size() - 1);
}
bool VerifySquenceOfBST1(vector<int> s){
    if(s.empty())return false;
    vector<int> lt;vector<int> rt; //左右子树递归判断
    int i=0,n=s.size();
    while(i<n-1 && s[i]<s[n-1]) lt.push_back(s[i++]);
    while(i<n-1 && s[i]>s[n-1]) rt.push_back(s[i++]);
    if(i!=n-1)return false; //特判,提前结束说明不对
    if(VerifySquenceOfBST(lt) && VerifySquenceOfBST(rt)) return true;
}
int main()
{
    vector<int> s={4,8,7,11,14,13,10};
    if(VerifySquenceOfBST(s)) cout<<"True";
    else cout<<"False";
}