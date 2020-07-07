#include<bits/stdc++.h>
using namespace std;
int nums[21][101];

int main()
{
    int n,k,res=0,pos;
    cin>>n;
    getchar();
    for(int i=0;i<n;i++){
        char c;
        int j=0;
        while((c=getchar())!='\n') nums[i][j]=c-'0',j++;
        if(i){
            if(j>k) res=i,pos=j;
            else if(k==j)
                for(int l=0;l<k;l++){
                    if(nums[i][l]>nums[res][l]) {res=i;break;}
                    else if(nums[i][l]<nums[res][l]) break;
                }
        } else pos=j;
        k=j;
    }
    cout<<res+1<<endl;
    for(int i=0;i<pos;i++) cout<<nums[res][i];
    return 0;
}