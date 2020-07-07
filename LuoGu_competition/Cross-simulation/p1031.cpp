#include<bits/stdc++.h>
using namespace std;
const int MAXN=105;
int nums[MAXN],N;
int Max(){
    int Max=0,j=0;
    for(int i=0;i<N;i++){
        if(nums[i]>Max) Max=nums[i],j=i;
    }
    return j;
}

int main()
{
    cin>>N;
    int sum=0;
    for(int i=0;i<N;i++) cin>>nums[i],sum+=nums[i];
    int x = sum/N;
    int j,res=0,count=0;
    while(count<N){
        j=Max();
        if(j==0) {
            nums[1] +=nums[0]-x;
            if(nums[0]-x) res++;
            nums[0]=x;count++;
        }
        else if(j==N-1){
            nums[N-2] += nums[N-1]-x;
            if(nums[N-1]-x) res++;
            nums[N-1]=x;count++;
        }
        else{
            int s=0;
            for(int i=0;i<j;i++){
                if(nums[i]<x) s += x-nums[i];
                else s -= nums[i]-x;
            }
            nums[j-1] += s;if(s) res++;
            s=0;
            for(int i=j+1;i<N;i++){
                if(nums[i]<x) s += x-nums[i];
                else s -= nums[i]-x;
            }
            nums[j+1] += s;if(s) res++;
            nums[j]=x;count++;
        }
    }
    cout<<res<<endl;
    return 0;
}