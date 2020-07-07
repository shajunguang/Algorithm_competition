////
//// Created by liu on 19-10-19.
////
//
//#include <bits/stdc++.h>
//#define local
//using namespace std;
//int d=1;
//
//struct Node{
//    Node* left,*right;
//    int data;
//    Node(int x):left(NULL),right(NULL),data(x){};
//};
//Node* root=NULL;
//
//bool Insert(int key)
//{
//    Node* parent=NULL;
//    Node* pcur = root;
//    while (pcur)
//    {
//        if (pcur->data >= key)
//        {
//            parent = pcur;
//            pcur = pcur->left;
//            d++;
//        }
//        else
//        {
//            parent = pcur;
//            pcur = pcur->right;
//            d++;
//        }
//    }
//    if (parent->data < key)
//    {
//        parent->right = new Node(key);
//    }
//    else
//    {
//        parent->left = new Node(key);
//    }
//    return true;
//}
//
//int main()
//{
//#ifdef local
//    freopen("in.txt","r",stdin);
//#endif
//    int N,key,c;
//    cin>>N;
//    cin>>c;
//    root=new Node(c);
//    cout<<d<<" ";
//    for(int i=1;i<N;i++)
//    {
//        cin>>key;
//        Insert(key);
//        cout<<d<<" ";
//        d=1;
//    }
//    return 0;
//}