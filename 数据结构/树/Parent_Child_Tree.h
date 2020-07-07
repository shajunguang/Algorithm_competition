#ifndef ALGORITHM_COMPETITION_PARENT_CHILD_TREE_H
#define ALGORITHM_COMPETITION_PARENT_CHILD_TREE_H
//一般树建立的思路-孩子双亲法
#include<bits/stdc++.h>
using namespace std;
#define MAX_TREE_SIZE 100
typedef int ElemType;

typedef struct CTNode{ //孩子节点
    int child;
    CTNode* next;
}*ChildPtr;

typedef struct{//表头
    ElemType data;
    int parent; //双亲位置
    ChildPtr firstchild;//第一个孩子指针
}CTBox;

typedef struct{ //树
    CTBox node[MAX_TREE_SIZE];//结点数组
    int r,n;//根节点位置，节点个数
}PCTree;
#endif //ALGORITHM_COMPETITION_PARENT_CHILD_TREE_H
