//逆序对
#include<bits/stdc++.h>
using namespace std;
const int MOD=1000000007;
int ans=0;
int tmp[200005];
void merge_sort(vector<int> &q, int l, int r) {
    if (l >= r) return;
    int mid = (l + r) >> 1;
    merge_sort(q, l, mid);
    merge_sort(q, mid + 1, r);
    //合并过程
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (q[i] <= q[j]) tmp[k++] = q[i++]; //借助外界数组，记得外面定义
        else ans += mid - i + 1, ans%=MOD,tmp[k++] = q[j++]; //防止溢出
    }

    while (i <= mid) tmp[k++] = q[i++];
    while (j <= r) tmp[k++] = q[j++];
    for (i = l, j = 0; i <= r; i++, j++) q[i] = tmp[j];
}
int InversePairs(vector<int> data) {
    merge_sort(data,0,(int)data.size()-1);
    return ans;
}
int main()
{
    vector<int> data={5,3,4,2,1};
    cout<<InversePairs(data);
    return 0;
}