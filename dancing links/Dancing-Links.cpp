//
// Created by liu on 19-10-17.
//
/*解决稀疏矩阵中那些行保证每列只有一个1，数据结构：dancing links*/

//#include <bits/stdc++.h>
//#include "dancing_links.h"
//using namespace std;
//
//
//int main()
//{
//    vector<string> board;
//    board.emplace_back("0010110");
//    board.emplace_back("1001001");
//    board.emplace_back("0110010");
//    board.emplace_back("1001000");
//    board.emplace_back("0100001");
//    board.emplace_back("0001101");
//    Cell* head=new Cell(0);
//    Cell* lastCell=head;
//    vector<Cell*> colCells;
//    for(int i=0;i<board.size();i++)
//    {
//        Cell* cell=new Cell(-1-i);
//        lastCell->right=cell;
//        cell->left=lastCell;
//        cell->up=cell;
//        cell->down=cell;
//        colCells.push_back(cell);
//        lastCell=cell;
//    }
//    lastCell->right=head;
//    head->left=lastCell;
//    for(int i=0;i<board.size();i++){
//        Cell *lastCell=NULL,*firstCell=NULL;
//        for(int j=0;j<board[i].length();j++){
//            if(board[i][j]=='1'){
//                Cell* columnCell=colCells[j];
//                Cell* cell=new Cell(i+1);
//                cell->up=columnCell->up;
//                cell->down=columnCell;
//                columnCell->up->down=cell;
//                columnCell->up=cell;
//                cell->col=columnCell;
//                if(lastCell==NULL){
//                    firstCell=cell;
//                    lastCell=cell;
//                }
//                cell->left=lastCell;
//                lastCell->right=cell;
//                lastCell=cell;
//            }
//        }
//        firstCell->left=lastCell;
//        lastCell->right=firstCell;
//    }
//    vector<int>answers;
//    solveWithDLX(head,answers);
//    for(int i=0;i<answers.size();i++) {
//        cout << answers[i] << endl;
//    }
//}
