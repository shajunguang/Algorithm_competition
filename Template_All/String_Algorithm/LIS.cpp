#include<bits/stdc++.h>
using namespace std;
const int MAX_N=10000;
int f[MAX_N]; //f[i]代表以a[i]结尾的LIS的长度 f[i]=max(f[i],f[j]+1)(0<j<i,arr[j]<arr[i])
void reconstruct_print(int,int*,int*);
//O(n^2)
void lis(int A[],int n){
    for(int i=0;i<n;i++) {
        f[i] = 1;
        for (int j = i - 1; j >= 0; j--) { //所有i前面的序列，以j结尾的长度
            if (A[j] < A[i]) f[i] = max(f[i], f[j] + 1); //如果可以接上i，加比较下最大的是
        }
    }
}
/*
int main()
{
    int A[8]={-1,2,5,1,3,6,8,9};
    lis(A,8);
    int ans=0;
    for(int i=0;i<8;i++) ans=max(ans,f[i]);
    cout<<ans;
    return 0;
}
 */
int main() {
    //O(nlgn)二分+贪心
    int n = 11, A[] = {-7, 10, 9, 2, 3, 8, 8, 1, 2, 3, 4};    //A为输入数列  n为输入的长度
    int L[MAX_N], L_id[MAX_N], P[MAX_N];    //输入参数 MAX_N 代表总共有多少个数据

    int lis = 0, lis_end = 0;
    for (int i = 0; i < n; ++i) {
        int pos = lower_bound(L, L + lis, A[i]) - L;    //注意这里当询问的是 严格单调递增 这里需要替换为 uppperbound
        L[pos] = A[i];
        L_id[pos] = i;
        P[i] = pos ? L_id[pos - 1] : -1;    //P是一个链表.
        if (pos + 1 > lis) {
            lis = pos + 1;
            lis_end = i;
        }
    }
    reconstruct_print(lis_end,A,P);
    return 0;
}
//显示需要打印的LIS序列:
//输入：lis_end, A, P
void reconstruct_print(int end, int a[], int p[]) {
  int x = end;
  stack<int> s;
  for (; p[x] >= 0; x = p[x]) s.push(a[x]);
  printf("[%d", a[x]);
  for (; !s.empty(); s.pop()) printf(", %d", s.top());
  printf("]\n");
}