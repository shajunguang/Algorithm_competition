//利用斐波那契数列的黄金分割比例查找
//F[k]-1分成mid为界限的F[k-1]-1和F[k-2]-1;
#include<bits/stdc++.h>
using namespace std;
const int MAXN=20;
int F[MAXN],nums[MAXN];

int fbsearch(int n,int key){
    int k=0;
    while(F[k]-1<n){
        k++;
    }
    int  * temp;//将数组a扩展到F[k]-1的长度
    temp=new int [F[k]-1];
    memcpy(temp,nums,n*sizeof(int));
    for(int i=n;i<F[k]-1;++i)
        temp[i]=nums[n-1];

    int i=0,j=n-1;
    while(i<=j){
        int mid=i+F[k-1]-1;
        if(temp[mid]<key) i=mid+1,k-=2;
        else if(temp[mid]==key){
            if(mid<n) return mid;
            else return n-1;
        }
        else j=mid-1,k-=1;
    }
    return -1;
}

int main()
{
    F[0]=0;F[1]=1;
    for(int i=2;i<MAXN;i++) F[i]=F[i-1]+F[i-2];
    int n,key;
    cin>>n>>key;
    for(int i=0;i<n;i++) cin>>nums[i];

    cout<<fbsearch(n,key);
    return 0;
}