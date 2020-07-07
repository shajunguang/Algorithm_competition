//
// Created by liu on 19-9-21.
//

//#include <bits/stdc++.h>
//using namespace std;
//const int MAXN = 25, MAXM = 1000;
//int nums[MAXN][MAXM],A[MAXN],B[MAXN];
//
//void insertion_sort(int n){
//    int key,keya,i,j;
//    for(j=1;j<n;j++){
//        key=nums[j][0];
//        keya=A[j];
//        i=j-1;
//        while(i>=0 && nums[i][0]<=key){
//            if(nums[i][0]==key){
//                for(int k=1;k<MAXN;k++)
//                    if(nums[i][k]<nums[j][k]){
//                        A[i+1]=A[i];
//                        i=i-1;
//                        break;
//                    }
//                    else if(nums[i][k]==nums[j][k]) continue;
//                    else    break;
//            }
//            else{
//                nums[i+1][0]=nums[i][0];
//                A[i+1]=A[i];
//                i=i-1;
//            }
//        }
//        nums[i+1][0]=key;
//        A[i+1]=keya;
//    }
//}
//
//int main()
//{
//    int n,t;
//    cin>>n;
//    memset(B,0, sizeof B);
//    for(int i=0;i<n;i++)
//    {
//        cin>>A[i];
//        t=A[i];
//        while(t)
//            { t=t/10; B[i]++;}
//    }
//    for(int i=0;i<n;i++)
//        for(int j=0;j<MAXM;j++)
//        {
//            nums[i][j]=A[i]/pow(10,B[i]-1);
//        }
//    insertion_sort(n);
//    for(int i=0;i<n;i++)
//        cout<<A[i];
//    return 0;
//}

//插入排序
//#include <bits/stdc++.h>
//using namespace std;
//string a[25];
//
//int main()
//{
//    int n;
//    cin>>n;
//    for(int i=0;i<n;i++)  cin>>a[i];
//    for(int i=0;i<n;i++)
//        for(int j=i+1;j<n;j++)
//            if(a[j]+a[i]>a[i]+a[j])
//                swap(a[j],a[i]);
//    for(int i=0;i<n;i++)    cout<<a[i];
//    return 0;
//}