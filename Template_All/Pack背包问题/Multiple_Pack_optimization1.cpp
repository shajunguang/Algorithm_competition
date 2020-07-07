//多重背包的单调队列优化
#include <bits/stdc++.h>
using namespace std;

int n, m;
int f[20002], q[20002], g[20002];
int main() {
    cin >> n >> m;
    for (int i = 0; i <= n; ++i) {
        int v, w, s;
        cin >> v >> w >> s;
        memcpy(g, f, sizeof(f));
        for (int j = 0; j < v; ++j) {
            /*
            hh为队首位置
            tt为队尾位置
            数值越大，表示位置越后面
            队首在队尾后面队列为空，即hh>tt时队列为空
            */
            int hh = 0, tt = -1;
            /*
            q[]为单调队列
            存储前个s(物品数量)中的最大值
            数组从头(hh)到尾(tt)单调递减
            */
            for (int k = j; k <= m; k += v) {

                // f[k] = g[k]; //这一行我没理解有什么用，去掉后也能ac？我认为前面使用过了memcpy,这里应该一定是相等的

                //k代表假设当前背包容量为k
                //q[hh]为队首元素（最大值的下标）
                //g[]为dp[i-1][]
                //f[]为dp[i][]

                /*
                维护一个大小为k的区间
                使最大值为前k个元素中最大
                (k - q[hh]) / v 表示拿取物品的数量（相当于最原始的多重背包dp的k）
                */
                if (hh <= tt && (k - q[hh]) / v > s) {
                    hh++;
                }

                /*
                若队内有值，该值就是前k个元素的最大值
                (k - q[hh]) / v 表示拿取物品的数量（相当于最原始的多重背包dp的k）
                q[hh]为队首元素（g[]中前k个数中最大值的下标），g[]为dp[i-1][]
                所以 g[q[hh]]为只考虑前i-1个物品时，拿前q[hh]个物品的最大价值
                */
                if (hh <= tt) {
                    f[k] = max(f[k], g[q[hh]] + (k - q[hh]) / v * w);
                }

                /*
                若队尾元素小于当前元素，则队尾元素出队；
                若队内一个元素比当前元素小，则该元素一定不会被用到（单调队列思想）
                g[q[tt]] + (k - q[tt]) / v * w
                与
                g[k] - (k - j) / v * w
                分别表示队尾元素的值和当前元素的值
                */
                while (hh <= tt && g[q[tt]] - (q[tt] - j) / v * w <= g[k] - (k - j) / v * w) {
                    tt--;
                }

                //去除了比当前小的元素，保证队列里的元素都比当前元素大，入队
                q[++tt] = k;
            }
        }
    }
    cout << f[m] << endl;
}
/*
 #include <stdio.h>
const int  N  = 20001;
struct node{
    int pos, val;
}q[N];
int dp[N];
int main(){
    int n, m; scanf("%d%d", &n, &m);
    while (n--){
        int v, w, s; scanf("%d%d%d", &v, &w, &s);
        for (int j = 0; j < v; ++j){
            int hh = 0, tt = 0, stop = (m - j) / v;
            //[hh, tt)
            for (int k = 0; k <= stop; ++k){
                int val = dp[k * v + j] - k * w;
                while (hh < tt && val >= q[tt-1].val) --tt;
                q[tt].pos = k, q[tt++].val = val;
                if (q[hh].pos < k - s) ++hh;
                dp[v * k + j] = q[hh].val + k * w;
            }
        }
    }
    printf("%d\n", dp[m]);
}
 */