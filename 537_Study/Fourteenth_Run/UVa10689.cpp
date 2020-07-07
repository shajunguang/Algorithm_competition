//由于n=1e9,O(n)TLE,可使用O(lgn)矩阵乘法[f(2),f(1);f(1),f(0)]^(n-1),使用快速幂策略
#include<bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> mat;
int M;
//定义矩阵相乘
mat mul(mat &A, mat &B){
    mat C(A.size(), vector<int>(B[0].size()));
    for(int i=0;i<A.size();i++)
        for(int k=0;k<B.size();k++)
            for(int j=0;j<B[0].size();j++){
                C[i][j]=(C[i][j]+A[i][k]*B[k][j])%M;
            }
    return C;
}
//快速幂，迭代写法
mat Pow(mat A,int n){
    mat B(A.size(), vector<int>(A.size()));
    for(int i=0;i<A.size();i++) B[i][i]=1;
    while(n>0){
        if(n&1) B=mul(B,A);
        A=mul(A,A);
        n>>=1;
    }
    return B;
}
int main()
{
    freopen("in.txt","r",stdin);
    int T,a,b,m,n;
    cin>>T;
    while(T--){
        mat A(2,vector<int>(2));
        mat B(2,vector<int>(2));
        cin>>a>>b>>n>>m;
        M=1;
        while(m) M*=10,m--;
        A[0][0]=1,A[0][1]=A[1][0]=1,A[1][1]=0;
        A = Pow(A, n-2);
        B[0][0]=(a+b)%M,B[0][1]=B[1][0]=b%M,B[1][1]=a%M;
        B = mul(B,A);
        if(n>=2) cout<<B[0][0]<<endl;
        else if(n==1) cout<<B[0][1]<<endl;
        else cout<<B[1][1]<<endl; //n=0特判
    }
    return 0;
}