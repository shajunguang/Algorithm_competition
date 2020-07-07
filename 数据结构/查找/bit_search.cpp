//按比例查找实用余数据均匀,数量大
//二分查找
#include<bits/stdc++.h>
using namespace std;

int bit_search(int q[],int l,int r,int key){
    if(l>r) return -1;

    int i=l,j=r;
    while(i<j){
        //int mid=l+r>>1; //二分
        int mid=i+(key-q[i])/(q[j]-q[i])*(j-i);
        if(q[mid]<key) i=mid+1;
        else if(q[mid]==key) return mid;
        else j=mid-1;
    }
    return -1;
}

int main()
{
    int n,key;
    cin>>n>>key;
    int q[100];
    for(int i=0;i<n;i++)cin>>q[i];
    cout<<bit_search(q,0,n-1,key);
    return 0;
}