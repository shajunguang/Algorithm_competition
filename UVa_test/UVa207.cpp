//
// Created by liu on 19-8-19.
//

//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//#include <cassert>
//using namespace std;
//#define REP(i, n) for (int i = 0; i < (n); i++)
////#define debug
//const int maxn = 144;
//const int n_cut = 70;
//
//struct Player
//{
//    char name[50];
//    int amateur;
//    int sco[4];
//    int all2, all4, dq;
//    int rnds;
//} player[maxn];
//
//int n;
//double mon_all, p[n_cut];
//
//bool cmp1(const Player &a, const Player &b)
//{
//    if (a.all2 < 0 && b.all2 < 0) return false;
//    if (a.all2 < 0) return false;
//    if (b.all2 < 0) return true;
//    return a.all2 < b.all2;
//}
//
//bool cmp2 (const Player &a, const Player &b)
//{
//    if (a.dq && b.dq) //两选手都违规
//    {
//        if (a.rnds != b.rnds) return b.rnds < a.rnds;
//        if (a.all4 != b.all4) return a.all4 < b.all4;
//        return strcmp(a.name, b.name) < 0;
//    }
//    if (a.dq) return false;
//    if (b.dq) return true;  //一人违规
//    if (a.all4 != b.all4) return a.all4 < b.all4;
//    return strcmp(a.name, b.name) < 0;
//    //两人都没违规，先比较总分，再将名字按字典序排列
//}
//
//void solve()
//{
//    printf("Player Name          Place     RD1  RD2  RD3  RD4  TOTAL     Money Won\n");
//    printf("-----------------------------------------------------------------------\n");
//
//    int i = 0, pos = 0;
//    while (i < n)
//    {
//        if (player[i].dq)
//        {
//            printf("%s           ",player[i].name);
//            REP(j,player[i].rnds) printf("%-5d", player[i].sco[j]);
//            REP(j,4-player[i].rnds) printf("     ");
//            printf("DQ\n");
//            i++;
//            continue;
//        }
//
//        int j = i;
//        int m = 0; //等级相同的专业选手数
//        bool is_divide = false;
//        double tot = 0.0; //平均百分比
//
//        while (j < n && player[j].all4  == player[i].all4)
//        {
//            if (!player[j].amateur)
//            {
//                m++;
//                if (pos < n_cut)
//                {
//                    is_divide = true;
//                    tot += p[pos++];
//                }
//            }
//            j++;
//        }
//
//        int rank = i + 1;
//        double amount = mon_all * tot / m;
//
//        while (i < j)
//        {
//            printf("%s ", player[i].name);
//            char t[5];
//            sprintf(t, "%d%c", rank, m > 1 && is_divide && !player[i].amateur? 'T' : ' '); //并且只有专业选手参与平分奖金，业余选手仅排名不拿奖
//            printf("%-10s", t);
//            REP(e, 4) printf("%-5d", player[i].sco[e]);
//
//            if (!player[i].amateur && is_divide)
//            {
//                printf("%-10d", player[i].all4);
//                printf("$%9.2lf\n", amount / 100.0);
//            }
//            else
//                printf("%d\n", player[i].all4);
//            i++;
//        }
//    }
//}
//
//int main()
//{
//    int T;
//    char s[40];
//
//    scanf("%d",&T);
//
//    while (T--)
//    {
//        scanf("%lf", &mon_all);
//
//        //奖金比例
//        REP(i, n_cut) scanf("%lf", &p[i]);
//
//        scanf("%d", &n);
//        assert(n <= 144);
//        getchar();  //吃掉空白行，enter
//
//        REP(k, n)
//        {
//            fgets(player[k].name, 21, stdin);
//            player[k].amateur = 0;
//
//            if (strchr(player[k].name, '*')) player[k].amateur = 1;
//
//            player[k].all2 = player[k].all4 = player[k].dq = 0;
//            memset(player[k].sco, -1, sizeof(player[k].sco));
//
//            REP(i, 4)
//            {
//                if (!scanf("%d", &player[k].sco[i]))
//                {
//                    player[k].rnds = i;
//                    player[k].dq = -1;
//                    if (i < 2) player[k].all2 = -1;
//                    break;
//                }
//                else
//                {
//                    player[k].all4 += player[k].sco[i];
//                    if (i < 2)
//                        player[k].all2 += player[k].sco[i];
//                }
//            }
//            char temp[15];
//            fgets(temp, 10, stdin);
//        }
//
//        sort(player, player+n, cmp1);
//        assert(player[n_cut - 1].all2 >= 0);
//
//        for (int i = n_cut - 1; i < n; i++)
//            if (player[i].all2 != player[i + 1].all2)
//            {
//                n = i + 1;
//                break;
//            }
//
//        sort(player, player+n, cmp2);
//
//        solve();
//
//        if (T) printf("\n");
//
//    }
//    return 0;
//}
