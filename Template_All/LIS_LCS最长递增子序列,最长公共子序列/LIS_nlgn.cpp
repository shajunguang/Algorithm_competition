//最长递增子序列
#include<bits/stdc++.h>
using namespace std;
const int MAX_N=100;
int L[MAX_N], L_id[MAX_N], P[MAX_N];    //输入参数 MAX_N 代表总共有多少个数据
void reconstruct_print(int end, int a[], int p[]);
int main(){
    int n = 11, A[] = {-7, 10, 9, 2, 3, 8, 8, 1, 2, 3, 4};    //A为输入数列  n为输入的长度

    int lis = 0, lis_end = 0;
    for (int i = 0; i < n; ++i) {
        int pos = lower_bound(L, L + lis, A[i]) - L;    //注意这里当询问的是 严格单调递增 这里需要替换为 uppperbound
        L[pos] = A[i]; //这里换下更小的数，保证序列能扩展更长,而且这个性质无后效性
        L_id[pos] = i;
        P[i] = pos ? L_id[pos - 1] : -1;	//P是一个链表.
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

/**
 //更好理解版本 贪心+二分
 #include <bits/stdc++.h>
using namespace std;
const int MAXX=100000+5;
const int INF=INT_MAX;

int a[MAXX],dp[MAXX]; // a数组为数据，dp[i]表示长度为i+1的LIS结尾元素的最小值

int main()
{
    int n;
    while(cin>>n)
    {
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            dp[i]=INF; // 初始化为无限大
        }
        int pos=0;    // 记录dp当前最后一位的下标
        dp[0]=a[0];   // dp[0]值显然为a[0]
        for(int i=1; i<n; i++)
        {
            if(a[i]>dp[pos])    // 若a[i]大于dp数组最大值，则直接添加
                dp[++pos] = a[i];
            else    // 否则找到dp中第一个大于等于a[i]的位置，用a[i]替换之。
                dp[lower_bound(dp,dp+pos+1,a[i])-dp]=a[i];  // 二分查找
        }
        cout<<pos+1<<endl;
    }
    return 0;
}
 */