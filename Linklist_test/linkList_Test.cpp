////
//// Created by liu on 19-9-2.
////
//
//#include "linkList.h"
//#include <pthread.h>//exit()
//#include<iostream>
//
//using namespace std;
//char pause;
//typedef int T;
//
//int main()
//{
//    int i;
//    T e,prior_e;
//    linkList<int>L;   //建立整形空链表
//    system("cls");    //执行系统命令，清屏
//    int choice;
//    do
//    {
//        cout<<"1-创建链表\n";
//        cout<<"2-在链表第i个位置插入元素\n";
//        cout<<"3-删除链表中第i个位置的元素\n";
//        cout<<"4-返回第i个元素的值\n";
//        cout<<"5-元素定位\n";
//        cout<<"6-按值求前驱\n";
//        cout<<"7-测表空\n";
//        cout<<"8-测表长\n";
//        cout<<"9-显示链表\n";
//        cout<<"10-退出\n";
//        cout<<"Enter choice:";
//        cin>>choice;
//        switch(choice)
//        {
//            case 1://创建链表
//                cout<<"请输入要创建的链表中元素的个数:";
//                cin>>i;
//                cout<<endl;
//                L.createList(i);
//                break;
//            case 2://元素插入
//                cout<<"请输入插入的位置";
//                cin>>i;
//                cout<<endl;
//                cout<<"请输入插入元素的值:";
//                cin>>e;
//                cout<<endl;
//                try
//                {
//                    L.Insert(i,e);
//                }
//                catch(char* err)
//                {
//                    cout<<err<<endl;
//                }
//                break;
//            case 3://元素删除
//                cout<<"请输入删除位置";
//                cin>>i;
//                cout<<endl;
//                try
//                {
//                    e = L.Delete(i);
//                    cout<<"被删除元素为："<<e<<endl;
//                }
//                catch(char* err)
//                {
//                    cout<<err<<endl;
//                }
//                cin.get(pause);
//                system("pause");
//                break;
//            case 4://返回第i个元素值
//                cout<<"请输入要查询的元素位置:";
//                cin>>i;
//                try
//                {
//                    e = L.getElem(i);
//                    cout<<"第"<<i<<"个元素值为:"<<e<<endl;
//                }
//                catch(char* err)
//                {
//                    cout<<err<<endl;
//                }
//                cin.get(pause);
//                system("pause");
//                break;
//            case 5://按值进行元素查询
//                cout<<"请输入要查询的元素值：";
//                cin>>e;
//                i = L.Locate(e);
//                cout<<"查询元素"<<e<<"在链表中的位置为："<<i<<endl;
//                cin.get(pause);
//                system("pause");
//                break;
//            case  6://求元素前驱
//                cout<<"请输入要求前驱元素的值：";
//                cin>>e;
//                try
//                {
//                    prior_e = L.prior(e);
//                    cout<<"元素"<<e<<"的前驱值为:"<<prior_e<<endl;
//                }
//                catch(char *err)
//                {
//                    cout<<err<<endl;
//                }
//                cin.get(pause);
//                system("pause");
//                break;
//            case 7://测表空
//                i = L.Empty();
//                if(i)
//                {
//                    cout<<"表空"<<endl;
//                }
//                else
//                {
//                    cout<<"表不空"<<endl;
//                }
//                cin.get(pause);
//                system("pause");
//                break;
//            case 8://测表长
//                cout<<"链表长度为:"<<L.Length()<<endl;
//                cin.get(pause);
//                system("pause");
//                break;
//            case 9://遍历输出表
//                L.listDisplay();
//                cout<<endl;
//                cin.get(pause);
//                system("pause");
//                break;
//            case 10://退出
//                break;
//            default://非法选择
//                cout<<"Invalid choice";
//                break;
//        }
//
//    }while(choice != 10);
//    return 0;
//}
