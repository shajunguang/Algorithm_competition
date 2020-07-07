#include<bits/stdc++.h>
using namespace std;
int nums[13],ans[13],fac[13]={1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600};
bool cmp(int a,int b){
    return a>b;
}
int main()
{
    int n,s;
    cin>>n>>s;
    for(int i=1;i<=n;i++) nums[i]=i;
    memset(ans,0,sizeof ans);
    do{
        int out_a=0;
        int num_tmp[13];
        memcpy(num_tmp,nums,sizeof num_tmp);
        int sum=0;
        for(int i=1;i<=n;i++) {
            sum+=fac[n-1]/fac[i-1]/fac[n-i]*nums[i];
            if(sum>s){
                sort(nums+i,nums+n+1,cmp);
                //发现从当前开始的i位开始往后累加都会超过预期，就把它从大到小排一遍，再next的时候就能跳过这一段了
                //因为默认是升序，所以先把后面调成降序，下次会把大的值再往前调，尽可能减少循环次数
                out_a=1;
                break;
            }
        }
        if(out_a)continue;
        if(s==sum){for(int i=1;i<=n;i++) cout<<nums[i]<<" ";break;}
    }while(next_permutation(nums+1,nums+n+1)); //默认升序
    return 0;
}