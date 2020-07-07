//
// Created by liu on 19-10-15.
//

//#include <bits/stdc++.h>
//using namespace std;
//
//const int MAXN=35;
//int f[MAXN][MAXN],root[MAXN][MAXN],flag=1;
//typedef long long ll;
//
////计算l-r形成的子树的最大分值
//ll search(int l,int r)
//{
//    ll now;
//    if(l>r) return 1;
//    if(f[l][r]==-1)
//        for(int k=l;k<=r;k++){
//            now = search(l,k-1)*search(k+1,r)+f[k][k];
//            if(now > f[l][r])
//            {
//                f[l][r]=now;
//                root[l][r]=k;
//            }
//        }
//    return f[l][r];
//}
//
////前序遍历
//void preorder(int  l,int r)
//{
//    if(l>r) return;
//    if(flag)    flag=0;
//    else    cout<<" ";
//    cout<<root[l][r];
//    preorder(l,root[l][r]-1); //前序遍历左子树
//    preorder(root[l][r]+1,r); //前序遍历右子树
//}
//
//int main()
//{
//    int n;
//    cin>>n;
//    for(int i=1;i<=n;i++)
//        for(int j=1;j<=n;j++)
//            f[i][j] = -1;
//    for(int i=1;i<=n;i++)
//    {
//        cin>>f[i][i];
//        root[i][i]=i;
//    }
//    cout<<search(1,n)<<endl;
//    preorder(1,n);
//    return 0;
//}