////
//// Created by liu on 19-10-17.
////
//
////01矩阵的完美覆盖 HUST1017
//#include <iostream>
//#include <cstdio>
//#include <vector>
//using namespace std;
///***最大行***/
//#define MAXROW 1005
///***最大列***/
//#define MAXCOL 1005
//
//int ans[MAXROW+5];
//struct DancingLinksNode
//{
//    int r, c; /***结点所在的行列位置***/
//    DancingLinksNode *U, *D, *L, *R;/***结点的上下左右结点指针***/
//};
//DancingLinksNode node[MAXROW * MAXCOL];/****备用结点****/
//DancingLinksNode row[MAXROW];/****行头****/
//DancingLinksNode col[MAXCOL];/****列头****/
//DancingLinksNode head;/****表头****/
//int cnt;/****使用了多少结点****/
//int size[MAXCOL];/****列含有多少个域****/
//int m, n;/****表的行与列变量****/
//void init(int r, int c)/****初始化，r, c分别表示表的大小***/
//{
//    cnt = 0;/****将可以使用的结点设为第一个****/
//    head.r = r; /****head结点的r,c分别表示表的大小,以备查****/
//    head.c = c;
//    head.L = head.R = head.U = head.D = &head;/****初始化head结点****/
//    for(int i = 0; i < c; ++i) /***初始化列头***/
//    {
//        col[i].r = r;
//        col[i].c = i;
//        col[i].L = &head;
//        col[i].R = head.R;
//        col[i].L->R = col[i].R->L = &col[i];
//        col[i].U = col[i].D = &col[i];
//        size[i] = 0;
//    }
//    for(int i = r - 1; i > -1; --i)/***初始化行头,在删除的时候，如果碰到row[i].c  == c的情形应当被跳过***/
//    {
//        row[i].r = i;
//        row[i].c = c;
//        row[i].U = &head;
//        row[i].D = head.D;
//        row[i].U->D = row[i].D->U = &row[i];
//        row[i].L = row[i].R = &row[i];
//    }
//}
//inline void addNode(int r, int c)/****增加一个结点,在原表中的位置为r行,c列***/
//{
//    DancingLinksNode *ptr = &node[cnt++];/****找一个未曾使用的结点****/
//    ptr->r = r;/****设置结点的行列号****/
//    ptr->c = c;
//    ptr->R = &row[r];/****将结点加入双向链表中****/
//    ptr->L = row[r].L;
//    ptr->L->R = ptr->R->L = ptr;
//    ptr->U = &col[c];
//    ptr->D = col[c].D;
//    ptr->U->D = ptr->D->U = ptr;
//    ++size[c];/****将size域加1****/
//}
//inline void delLR(DancingLinksNode * ptr)/****删除ptr所指向的结点的左右方向****/
//{
//    ptr->L->R = ptr->R;
//    ptr->R->L = ptr->L;
//}
//inline void delUD(DancingLinksNode * ptr)/****删除ptr所指向的结点的上下方向****/
//{
//    ptr->U->D = ptr->D;
//    ptr->D->U = ptr->U;
//}
//inline void resumeLR(DancingLinksNode * ptr)/****重置ptr所指向的结点的左右方向****/
//{
//    ptr->L->R = ptr->R->L = ptr;
//}
//inline void resumeUD(DancingLinksNode * ptr)/****重置ptr所指向的结点的上下方向****/
//{
//    ptr->U->D = ptr->D->U = ptr;
//}
//inline void cover(int c)/****覆盖第c例***/
//{
//    if(c == n)/**** c == n 表示头****/
//        return;
//    delLR(&col[c]);/****删除表头****/
//    DancingLinksNode *R, *C;
//    for(C = col[c].D; C != (&col[c]); C = C->D)
//    {
//        if(C->c == n)
//            continue;
//        for(R = C->L; R != C; R = R->L)
//        {
//            if(R->c == n)
//                continue;
//            --size[R->c];
//            delUD(R);
//        }
//        delLR(C);
//    }
//}
//inline void resume(int c)/****重置第c列****/
//{
//    if(c == n)
//        return;
//    DancingLinksNode *R, *C;
//    for(C = col[c].U; C != (&col[c]); C = C->U)
//    {
//        if(C->c == n)
//            continue;
//        resumeLR(C);
//        for(R = C->R; R != C; R = R->R)
//        {
//            if(R->c == n)
//                continue;
//            ++size[R->c];
//            resumeUD(R);
//        }
//    }
//    resumeLR(&col[c]);/****把列头接进表头中****/
//}
//bool search(int k)/****搜索核心算法,k表示搜索层数****/
//{
//    if(head.L == (&head)) /***搜索成功,返回true***/
//    {
//        printf("%d\n",k);
//        for(int i=0;i<k;i++)
//            printf("%d\n",ans[i]);
//        return true;
//    }
//    /***c表示下一个列对象位置,找一个分支数目最小的进行覆盖***/
//    int INF = (1<<30), c = -1;
//    for(DancingLinksNode *ptr=head.L;ptr!=(&head);ptr=ptr->L)
//        if(size[ptr->c] < INF)
//        {
//            INF = size[ptr->c];
//            c = ptr->c;
//        }
//    cover(c); /***覆盖第c列***/
//    DancingLinksNode * ptr;
//    for(ptr = col[c].D; ptr != (&col[c]); ptr = ptr->D)
//    {
//        DancingLinksNode *rc;
//        ptr->R->L = ptr;
//        for(rc = ptr->L; rc != ptr; rc = rc->L)
//            cover(rc->c);
//        ptr->R->L = ptr->L;
//        ans[k]=ptr->r+1;
//        if(search(k + 1))
//            return true;
//        ptr->L->R = ptr;
//        for(rc = ptr->R; rc != ptr; rc = rc->R)
//            resume(rc->c);
//        ptr->L->R = ptr->R;
//    }
//    resume(c);/***取消覆盖第c列***/
//    return false;
//}
//int main()
//{
//    while(scanf("%d%d", &m, &n) != EOF)
//    {
//        init(m, n);
//        for(int i = 0; i < m; ++i)
//        {
//            int x,j;
//            scanf("%d",&x);
//            while(x--)
//            {
//                scanf("%d",&j);
//                j--;
//                addNode(i, j);//i行j列为1
//            }
//        }
//        if(!search(0))
//            puts("NO");
//    }
//}
///*
//模型的建立自然是要把冲突的条件都摆出来，这里有4个。
//1.同行不能有相同的数
//2.同列不能有相同的数
//3.同块不能有相同的数
//除了这3个很显然的约束，还有一个比较重要的，就是
//4.每个位置只能有一个数
//
//所以，对于一个9*9的数独，如此设置行:
//(行标号，列标号)，(行标号，数)，(列标号，数)，(块标号，数)
//每块都是9*9=81,一共是324个位置。
//其中比据我要加入一个i行j列的数字k那么要加入一个含4个1的行，即
//(i,j),(i,k),(j,k)(block(i,j),k)
//block(i,j)返回(i,j)的块标号
//如果有初始值的话把所有初始值都放一起，放在第0行，然后在第1层循环中做下特判，
//只进行一次覆盖。。如果能保证第一次必然循环到此行就这么做。
//否则，在递归开始前就先把这些列删除。提出前一种方案只是因为写起来方便。
//*/