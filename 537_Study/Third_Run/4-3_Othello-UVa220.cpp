//
// Created by liu on 19-10-11.
//

//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<algorithm>
//#include<string>
//#include<sstream>
//#include<set>
//#include<vector>
//#include<stack>
//#include<map>
//#include<queue>
//#include<deque>
//#include<cstdlib>
//#include<cstdio>
//#include<cstring>
//#include<cmath>
//#include<ctime>
//#include<functional>
//using namespace std;
//
//typedef pair<int, int> P;
//#define N 8
//char g[N][N];
//vector<P>pos;
//char player;//当前玩家，设为全局变量，便于后续讨论
//int dx[] = { -1, 1, 0, 0, -1, 1, -1, 1 };//利用向量数组，方便处理各种情况
//int dy[] = { 0, 0, -1, 1, -1, 1, 1, -1 };
//bool inside(int x, int y)
//{
//    if (x<0 || x>7 || y<0 || y>7)return false;
//    return true;
//}
//bool find(int d,int x,int y, char c)//沿着路径dx[d],dy[d]寻找目标棋子
//{
//    int w = dx[d], v = dy[d], i = x, j = y;
//    while (inside(i, j) && g[i][j] == 'W' + 'B' - c){ i += w; j += v; }
//    if (inside(i, j) && g[i][j] == c)return true;
//    return false;
//}
//bool is_valid(char c, int x, int y)//判断该位置是否为合法放置位置
//{
//    if (c == 'W')
//    {
//        for (int d = 0; d < 8; d++)
//            if (inside(x + dx[d], y + dy[d]) && g[x + dx[d]][y + dy[d]]=='B')
//            {
//                int i = x + dx[d], j = y + dy[d];
//                if (find(d, i, j, 'W'))return true;
//            }
//        return false;
//    }
//    else
//    {
//        for (int d = 0; d < 8; d++)
//            if (inside(x + dx[d], y + dy[d]) && g[x + dx[d]][y + dy[d]] == 'W')
//            {
//                int i = x + dx[d], j = y + dy[d];
//                if (find(d, i, j, 'B'))return true;
//            }
//        return false;
//    }
//}
//bool find_pos()//寻找合法放置位置
//{
//    pos.clear();
//    for (int i = 0; i < 8; i++)
//        for (int j = 0; j < 8; j++)
//            if (g[i][j] == '-'&&is_valid(player, i, j))//枚举每一个位置
//                pos.push_back(P(i + 1, j + 1));
//    int len = pos.size();
//    if (len>0)return true;
//    else return false;
//}
//void place(int x, int y)//放置棋子
//{
//    if (player == 'W')
//    {
//        g[x][y] = 'W';
//        for (int d = 0; d < 8;d++)
//            if (inside(x + dx[d], y + dy[d]) && g[x + dx[d]][y + dy[d]] == 'B')
//            {
//                int i = x + dx[d], j = y + dy[d];
//                if (find(d, i, j, 'W'))
//                {
//                    int w = dx[d], v = dy[d];
//                    while (g[i][j] != 'W'){ g[i][j] = 'W'; i += w; j += v; }
//                }
//            }
//    }
//    else
//    {
//        g[x][y] = 'B';
//        for (int d = 0; d < 8; d++)
//            if (inside(x + dx[d], y + dy[d]) && g[x + dx[d]][y + dy[d]] == 'W')
//            {
//                int i = x + dx[d], j = y + dy[d];
//                if (find(d, i, j, 'B'))
//                {
//                    int w = dx[d], v = dy[d];
//                    while (g[i][j] != 'B'){ g[i][j] = 'B'; i += w; j += v; }
//                }
//            }
//    }
//}
//void print_num()//打印黑白棋的个数
//{
//    int n1, n2;
//    n1 = n2 = 0;
//    for (int i = 0; i < 8;i++)
//        for (int j = 0; j < 8;j++)
//            if (g[i][j] == 'W')n1++;
//            else if (g[i][j]=='B')n2++;
//    printf("Black - %2d White - %2d\n", n2, n1);
//}
//void print_board()//打印当前棋盘
//{
//    for (int i = 0; i < 8; i++)
//        for (int j = 0; j < 8; j++)
//            printf("%c%s", g[i][j], j == 7 ? "\n":"");
//}
//int main()
//{
//    //freopen("t.txt", "r", stdin);
//    int T;
//    cin >> T;
//    int rnd = 0;
//    while (T--)
//    {
//        memset(g, '\0', sizeof(g));
//        for (int i = 0; i < 8; i++)
//            scanf("%s", g[i]);
//        cin >> player;
//        char cmd;
//        if (rnd++)cout << endl;
//        while (cin >> cmd)
//        {
//            if (cmd == 'L')
//            {
//                if (find_pos())
//                {
//                    int len = pos.size();
//                    for (int i = 0; i < len; i++)
//                        printf("(%d,%d)%c", pos[i].first, pos[i].second, i == len - 1 ? '\n' : ' ');
//                }
//                else puts("No legal move.");
//            }
//            if (cmd == 'M')
//            {
//                char str[10];
//                scanf("%s", str);
//                int r, c;
//                r = str[0] - '0' - 1, c = str[1] - '0' - 1;
//                if (g[r][c]=='-'&&!is_valid(player, r, c)){ player = 'W' + 'B' - player;  }
//                place(r, c);
//                print_num();
//                player = 'W' + 'B' - player;
//            }
//            if (cmd == 'Q')
//            {
//                print_board();
//                break;
//            }
//        }
//    }
//    return 0;
//}