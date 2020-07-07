#include<bits/stdc++.h>
using namespace std;
int nums[31][31];

int main()
{
    int n;
    cin>>n;
    memset(nums,0,sizeof nums);
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            if(j==0 || j==i){
                printf("%5d",1);
                nums[i][j]=1;
            }else if(j>0 && i>1){
                nums[i][j]=nums[i-1][j-1]+nums[i-1][j];
                printf("%5d",nums[i][j]); //右对齐,左补空格,%-5d相反,而%05d左补0
            }
        }
        printf("\n");
    }
    return 0;
}