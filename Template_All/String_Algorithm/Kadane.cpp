#include<bits/stdc++.h>
using namespace std;
//O(n)算法，针对序列有正有负才有意义
int Kadane(int A[],int n){
    int ans=0,sum=0;
    for(int i=0;i<n;i++){
        sum+=A[i]; //最长递增子串结束位置
        ans=max(ans,sum);
        if(sum<0) sum=0; //如果小于0的话，就截断前面的
    }
    return ans;
}
int main()
{
    int A[7]={-2,1,-2,4,1,-5,4};
    cout<<Kadane(A,7);
    return 0;
}