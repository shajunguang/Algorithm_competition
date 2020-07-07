#include"BiTree.h"

int main()
{
    BiTree root;
    CreateBiTree(&root);
    cout<<"前序遍历："<<endl;PreOrderTraverse(root,1);
    cout<<endl;
    cout<<"中序遍历："<<endl;InOrderTraverse(root,1);
    cout<<endl;
    cout<<"后序遍历："<<endl;BackOrderTraverse(root,1);
    return 0;
}