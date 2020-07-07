/*
马的遍历
*/

#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;

class Pos
{
public:
    int x;
    int y;
    Pos(int x, int y):x(x),y(y){}
};
vector<Pos> store;	   //用于存储路径

//棋盘数据：
const int WIDTH = 8;       //棋盘宽和高
const int HEIGHT = 8;
int board[WIDTH+1][HEIGHT+1];  //棋盘数组保存数据为每个位置对应马的路线的第几步

//dir为马的八个方向
const int dir[8][2] = {{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2}};

//求(i,j)位置的出口,并返回所有出口和对应的出口个数
int exitn(int i,int j,int s,int a[])
{
    int k,i1,j1;
    int count;  //计数出口的个数
    for (count=k=0; k<8; k++)
    {
        i1 = i + dir[(s+k)%8][0];  //八方向横坐标和纵坐标，(s+k)%8让索引保持在八方向上
        j1 = j + dir[(s+k)%8][1];
        if(i1>=0 && i1<HEIGHT && j1>=0 && j1<WIDTH && board[i1][j1]==0) //在棋盘的范围内并且没有走过
            a[count++]=(s+k)%8;
    }
    return count;
}
//将(i,j)节点以s开始的下一个节点序列中，节点数最小的一个返回
int next(int i,int j,int s)
{
    int m,k,go,min,a[8],b[8],temp;
    m = exitn(i, j, s, a);  //当前位置有出口数
    if(m==0)                //没有
        return -1;
    for(min=8,k=0; k<m; k++)       //搜寻出口最少的位置
    {
        temp = exitn(i+dir[a[k]][0], j+dir[a[k]][1], s, b);
        if(temp < min)             //保存最小出口
        {
            min = temp;
            go = a[k];             //保存方向索引
        }
    }
    return go;             //返回最少出口位置的方向索引
}

int main(int argc, char* argv[])
{
    cout << "    ----------------中国象棋中马的遍历----------------- \n"<< endl;
    int istartX(0), istartY(0);     //表示当前起始位置
    while (1)
    {
        cout << "请输入马的起始位置行号(0~9)：";
        cin >> istartX;
        if (istartX >= 0 && istartX <= 9) break;
    }

    while (1)
    {
        cout << "请输入马的起始位置列号(0~8)：";
        cin >> istartY;
        if (istartY >= 0 && istartY <= 8) break;
    }

    int step, flag, start=1;    //step表示第几步,flag标记下一步的方向，start表示方向索引的初始值
    memset(board,0,sizeof(int)*WIDTH*HEIGHT);  //初始化棋盘，0表示没有走过
    board[istartX][istartY]=1;                 //起始位置的第一步，1表示第一步，N表示第N步
    Pos v(istartX, istartY);
    store.push_back(v);

    cout << "\n棋盘中的轨迹：（数字表示第几步，所在位置为棋盘位置）" << endl;
    for(step=2; step <= WIDTH*HEIGHT; step++)  //从第二步开始，直到走满整个棋盘
    {
        if ((flag = next(istartX, istartY, start)) == -1)      //返回-1，没有找到出口
            break;
        istartX += dir[flag][0];                 //下一步的起始坐标
        istartY += dir[flag][1];
        board[istartX][istartY] = step;                    //保存当前步到棋盘作为标记
        Pos v(istartX,istartY);
        store.push_back(v);                     //将位置坐标存储
    }
    int i, j;
    for(i=0; i<HEIGHT; i++)                    //输出棋盘保存的路径
    {
        for(j=0; j<WIDTH; j++)
            printf("%5d", board[i][j]);        //5格对齐
        cout << endl;
    }

    int count = 0;
    cout << "马遍历的路径为：" << endl;
    for(vector<Pos>::iterator it = store.begin(); it != store.end(); ++it)
    {
        cout << "第" << ++count << "步: (" << (*it).x << "," << (*it).y << ")" << endl;
    }

    return 0;
}