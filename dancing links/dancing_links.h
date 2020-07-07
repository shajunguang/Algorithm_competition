//
// Created by liu on 19-10-17.
//

#ifndef ALGORITHM_COMPETITION_DANCING_LINKS_H
#define ALGORITHM_COMPETITION_DANCING_LINKS_H

#include <bits/stdc++.h>
using namespace std;

struct Cell{
    Cell* up,*down,*left,*right;
    Cell* col;
    int rowIndex;
    Cell(int r):up(NULL),down(NULL),left(NULL),right(NULL),col(NULL),rowIndex(r){}
};

//删除元素，其实移除元素上下左右元素的指向
bool removeColCell(Cell* colCell){
    colCell->left->right=colCell->right;
    colCell->right->left=colCell->left;
    Cell* downCell =colCell->down;
    if(downCell==colCell)
        return false;
    while(downCell != colCell){
        Cell* downRightCell = downCell->right;
        while(downRightCell != downCell){
            downRightCell->up->down = downRightCell->down;
            downRightCell->down->up = downRightCell->up;
            downRightCell=downRightCell->right;
        }
        downCell=downCell->down;
    }
    return true;
}

void recoverColCell(Cell* colCell){
    Cell* downCell=colCell->down;
    while(downCell !=colCell){
        Cell* downRightCell = downCell->right;
        while(downRightCell!=downCell){
            downRightCell->up->down=downRightCell;
            downRightCell->down->up=downRightCell;
            downRightCell=downRightCell->right;
        }
        downCell=downCell->down;
    }
    colCell->right->left=colCell;
    colCell->left->right=colCell;
}


bool solveWithDLX(Cell* head,vector<int>& answers){
    if(head->right==head)
        return true;
    Cell* nextCell=head->right;
    if(!removeColCell(nextCell))
        return false;
    Cell* downCell = nextCell->down;
    while(downCell!=nextCell){
        Cell* downRightCell = downCell->right;
        while(downRightCell!=downCell){  //删除过程
            Cell* rightColCell = downRightCell->col;
            removeColCell(rightColCell);
            downRightCell=downRightCell->right;
        }
        if(solveWithDLX(head,answers)){ //递归过程
            answers.push_back(downCell->rowIndex);
            return true;
        }else{  //回溯过程
            Cell* downRightCell=downCell->right;
            while(downRightCell!=downCell){
                Cell* rightColCell = downRightCell->col;
                recoverColCell(rightColCell);
                downRightCell=downRightCell->right;
            }
            downCell=downCell->down;
        }
    }
    recoverColCell(nextCell);
    return false;
}

#endif //ALGORITHM_COMPETITION_DANCING_LINKS_H
