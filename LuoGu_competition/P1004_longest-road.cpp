//
// Created by liu on 19-9-11.
//

//#include <iostream>
//#include <cstring>
//#include <climits>
//
//using namespace std;
//
//int A[10][10],arc[100][100],dist[100],visit[100],path[100][20];
//
//
//void Dijkstra(int N){
//    //初始化dist数组,表示距离
//    for(int k=0;k<N*N;k++){
//        dist[k]=arc[0][k];
//        for(int l=0;l<k%N;l++)
//            path[k][l]=l+1;
//        for(int l1=k%N;l1<k%N+k/N;l1++)
//            path[k][l1]=l1+N;
//    }
//    dist[0]=0;
//    visit[0]=1;
//    int count=1;
//    while(count != N*N){
//        //temp记录当前dist最大的那个下标
//        //max记录当前最大值
//        int temp=0;
//        int min=INT_MAX;
//        for(int k=0;k<N*N;k++)
//        {
//            if(!visit[k] && dist[k]<min)
//            {
//                min=dist[k];
//                temp=k;
//            }
//        }
//        for(int k=0;k<N*N;k++)
//            cout<<dist[k]<<" ";
//        cout<<endl;
//        cout<<temp<<endl;
//        visit[temp]=1;
//        count++;
//        for(int k=0;k<N*N;k++)
//        {
//            if(!visit[k] && arc[temp][k]!=INT_MAX && dist[temp]+arc[temp][k]<dist[k]){
//                dist[k]=dist[temp]+arc[temp][k];
//                for(int l=0;l<2*N;l++)
//                    path[k][l]=path[temp][l];
//                path[k][k%N+k/N-1]=k;
//
//            }
//
//        }
//    }
//}
//
//int main()
//{
//    int N,i, j,n,ans=0,B[10];
//    memset(A,0,sizeof(A));
//    memset(dist,0, sizeof(dist));
//    memset(visit,0,sizeof(visit));
//    memset(path,0,sizeof(path));
//    cin>>N;
//    for(int k=0;k<N;k++){
//        cin>>i>>j>>n;
//        A[i-1][j-1]=-n;
//    }
////    for(int i=0;i<N;i++)
////    {
////        for(int j=0;j<N;j++)
////            cout<<A[i][j]<<" ";
////        cout<<endl;
////    }
//    for(int k=0;k<100;k++)
//    {
//        for(int l=0;l<100;l++)
//           arc[k][l]=INT_MAX;
//    }
//    for(int k=0;k<N*N;k++)
//    {
//        if(k%N+1<N)
//            arc[k][k+1]=A[k%N+1][k/N];
//        if(k/N+1<N)
//            arc[k][k+N]=A[k%N][k/N+1];
//    }
////    for(int k=0;k<N*N;k++)
////    {
////        for(int l=0;l<N*N;l++)
////            cout<<arc[k][l]<<" ";
////        cout<<endl;
////    }
//    //cout<<arc[23][24];
//    Dijkstra(N);
//    ans -=dist[N*N-1];
//    cout<<ans<<endl;
//    for(int k=0;k<2*N-2;k++){
//        if(path[N*N-1][k]%N>0)
//            arc[path[N*N-1][k]-1][path[N*N-1][k]]=0;
//        if(path[N*N-1][k]/N>0)
//            arc[path[N*N-1][k]-N][path[N*N-1][k]]=0;
//    }
////    for(int k=0;k<N*N;k++)
////    {
////        for(int l=0;l<N*N;l++)
////            cout<<arc[k][l]<<" ";
////        cout<<endl;
////    }
//    memset(dist,0, sizeof(dist));
//    memset(visit,0,sizeof(visit));
//    Dijkstra(N);
//    for(int k=0;k<N*N;k++)
//        cout<<dist[k]<<" ";
//    cout<<endl;
//    ans -=dist[N*N-1];
//    cout<<ans;
//}


/*正确解法，唉多思考再下手啊！*/
//#include<cstdio>
//#include<algorithm>
//using namespace std;
//struct point
//{
//    int x,y,data;//记录每个点的位置和数值
//}p[100];
//int n,m,map[11][11],f[11][11];
//int main()
//{
//    int i,ii,j,jj,l;
//    scanf("%d",&n);
//    while(1)
//    {
//        int a,b,c;
//        scanf("%d%d%d",&a,&b,&c);
//        if(!a&&!b&&!c)
//            break;
//        p[++m].x=a;
//        p[m].y=b;
//        p[m].data=c;
//    }
//    for(i=1;i<=m;i++)
//        map[p[i].x][p[i].y]=p[i].data;
//    for(l=2;l<=n*2;l++)//每个点最少横着竖着都走一格，最多都走n格就到终点
//        for(i=l-1;i>=1;i--)//和前面说的一样，倒着做
//            for(ii=l-1;ii>=1;ii--)
//            {
//                j=l-i;jj=l-ii;//i+j=ii+jj=l
//                f[i][ii]=max(max(f[i][ii],f[i-1][ii-1]),max(f[i-1][ii],f[i][ii-1]))+map[i][j];
////重点说明一下吧，这里省略了很多。如果i不减1，意思就是j-1，因为上一个阶段就是l-1嘛。如果ii-1，意思就是说jj不减1。
//                f[i][ii]+=map[ii][jj]*(i!=ii);
////如果i==ii，其实就是(i==ii&&j==jj)，因为和都是l嘛。如果走过一遍，第二遍走得到的值就是0（题目上说的）。
//            }
//    printf("%d\n",f[n][n]);
////输出意思是在路径长度为2*n的阶段，两遍都走到(n,n)的最优值。因为在这里(j=2*n-i=n,jj=2*n-ii=n),所以走到的就是(n,n)的位置
//    return 0;
//}