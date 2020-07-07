////
//// Created by liu on 19-9-2.
////
//
//#include <iostream>
//using namespace std;
//
//enum operation{create_List=1,print_List,insert_Node,delete_Node,delete_List,quit};//枚举类型，用于菜单选择结果
//
//struct  node  //结点结构
//{ int data ;
//    node * next;
//};
//
//operation  Menu(); //菜单函数
//
//node * CreateList( );  //建立链表函数声明
//void  PrintList( node *); //输出链表中结点信息函数声明
//node * InsertNode(node *,node *); //在链表中插入结点函数声明
//node * DeleteNode(node *,int); //在链表中删除结点函数声明
//node * deleteList(node *head); //删除整个链表
//
//void Create();  //对应操作菜单--创建链表的操作
//void Print( );  //对应操作菜单--遍历链表的操作
//void Insert( ); //对应操作菜单--插入链表结点的操作
//void Delete( ); //对应操作菜单--删除链表结点的操作
//void DeleteAll(); //对应操作菜单--删除整个链表的操作
//
//
//int n=0; //全局整型变量存放链表中结点个数
//node * head=NULL ;  //全局指针变量存放链表头结点地址-头指针
//
//
//int main()
//{
//    operation menu_choice;  //存放菜单选择项
//
//    do   //循环现实直到用户退出程序
//    {
//        menu_choice=Menu(); //菜单显示及用户选择
//        switch(menu_choice) //用户选择功能匹配
//        {
//            case create_List: cout<<"1 创建链表"<<endl<<endl;
//                Create( );
//                break;
//            case  print_List: cout<<"2 遍历链表"<<endl<<endl;
//                Print();
//                break;
//            case  insert_Node: cout<<"3 插入链表结点"<<endl<<endl;
//                Insert();
//                break;
//            case  delete_Node: cout<<"4 删除链表结点"<<endl<<endl;
//                Delete();
//                break;
//            case  delete_List: cout<<"5 删除整个链表"<<endl<<endl;
//                DeleteAll();
//                break;
//            case quit :
//            default:   cout<<"退出链表操作，结束程序"<<endl;
//                return 0;
//
//        }
//
//    }while(menu_choice!=quit);
//
//    return 0;
//}
//
///*创建链表*/
//node * CreateList( )  //建立链表函数
//{ node * s, * p ; // s指向新结点，p指向链表中最后的结点
//    s = new node ;   //动态建立第一个新结点
//    cout<<"请输入一个整数值作为新结点的数据信息,输入0时建立链表结束"<<endl;
//    cout<<"第"<<n+1<<"个结点"<<endl;
//    cin >> s->data ;  //输入新结点数据
//    head = NULL ;   //头指针初始值为NULL
//    if( s->data==0)  //第一个结点数据就为0，建立一个空链表
//    {
//        cout<<"您建立的空链表"<<endl;
//        delete  s ;  //释放数据为0的结点
//    }
//    else //建立非空链表
//    {
//        while ( s->data != 0 )  //通过判断新结点数据来进行循环
//        { if ( head == NULL )   head = s ; //头指针赋值
//            else  p->next = s ;  //将新结点插入已有链表的最后
//            p = s ; // p指向链表中最后的结点
//            n=n+1;//结点个数增1
//            s = new node ; //动态建立一个新结点
//            cout<<"请输入一个整数值作为新结点的数据信息,输入0时建立链表结束"<<endl;
//            cout<<"第"<<n+1<<"个结点"<<endl;
//            cin >> s->data ; //输入新结点数据
//        }
//        p -> next = NULL ; //设置链表尾部为空
//        delete  s ;  //释放数据为0的结点
//        cout<<endl<<"链表建立完成...";
//        cout<<"建立的链表中共有"<<n<<"个节点"<<endl<<endl;
//    }
//    return ( head ) ; //返回头指针
//}
//
///*遍历链表*/
//void  PrintList( node * head)  //输出链表中结点信息函数,链表遍历
//{    node *p=head;
//    int i=1;
//    cout<<endl<<"遍历链表..."<<endl;
//    if (head!=NULL)  //如果链表非空，即链表中有结点
//        do             //循环输出接点数据，直到移动到链表尾，即最后一个结点
//        {     cout<<"第"<<i++<<"个结点数据为:"<<p->data<<endl;
//            p=p->next;
//        }while(p!=NULL) ;
//    else
//    {
//        cout<<"链表是空链表!"<<endl;
//    }
//    cout<<"链表中共有"<<n<<"个节点"<<endl;
//}
//
///*插入结点*/
//node * InsertNode(node *head,node * s)  //插入结点的函数，head为链表头指针，s指向要插入的新结点
//{node *p,*q;
//    p=head;   //使p指向链表中的第一个结点
//    if(head==NULL)      //原来的链表是空表
//    { head=s;           //使head指向的新结点作为头结点
//        s->next=NULL;
//    }
//    else  //原来的链表不是空表
//    {while((s->data>p->data) && (p->next!=NULL)) //用循环定位要插入的结点位置p，使s插入到p之前的位置
//        {q=p;  //q记录下当前的p，即q指向p的前一个结点
//            p=p->next;   //p后移一个结点
//        }
//        if(s->data<=p->data)  //要插入的结点数据比最后一个结点数据小
//        {	  if(head==p) //判断是否插入链表中的第一个结点之前
//            { head=s;  //插到原来第一个结点之前
//                s->next=p;
//            }
//            else //插到q指向的结点之后，p指向的结点之前
//            { q->next=s;
//                s->next=p;
//            }
//        }
//        else   //要插入的结点数据比最后一个结点数据还大
//        {  p->next=s;    // 插到链表最后的结点之后，作为链表的尾结点
//            s->next=NULL;
//        }
//    }
//    n=n+1;          //结点数加１
//    cout<<"成功完成一个新结点插入..."<<endl;
//    return (head);
//}
//
///*删除结点*/
//node *DeleteNode(node *head,int delData)   //删除数据为delDate的结点的函数
//{node *p,*q;
//    p=head;          //使p指向第一个结点
//    if (head==NULL)     //是空表
//    { cout<<"该链表是空链表，不能进行结点删除!"<<endl;
//        return(head);
//    }
//    //先找到要删除的结点
//    while(delData!=p->data && p->next!=NULL) //p指向的不是所要找的结点且后面还有结点
//    { q=p;  //q用来记录p前一个结点
//        p=p->next;
//    }         //p后移一个结点
//    if(delData==p->data)      //找到了要删除的结点
//    { if(p==head)  //如果要删除的是头结点
//            head=p->next;   //若p指向的是首结点，把第二个结点地址赋予head
//        else q->next=p->next;    //否则将下一结点地址赋给前一结点地址
//        cout<<"成功删除数据为"<<delData<<"的结点"<<endl;
//        n=n-1;
//    }
//    else
//        cout<<"要删除的数据为"<<delData<<"的结点在链表中没有找到"<<endl;     //找不到该结点
//    return(head);
//}
//
///*删除整个链表*/
//node * deleteList(node *head) //删除整个链表
//{
//    node *p,*s;
//    p=head;
//    if(head==NULL)
//        cout<<"链表本身就为空链表";
//    else
//    {
//        while(p->next!=NULL)
//        {
//            s=p;
//            p=p->next;
//            delete s;
//            n--;
//        }
//        delete p;
//        n--;
//        head=NULL;
//    }
//    cout<<"整个链表删除成功!"<<endl;
//    return head;
//}
//
//
///*菜单函数*/
//operation  Menu()
//{  int choice;
//    cout<<endl<<endl;
//    cout<<"链表操作菜单"<<endl;
//    cout<<"1 创建链表"<<endl;
//    cout<<"2 遍历链表"<<endl;
//    cout<<"3 插入链表结点"<<endl;
//    cout<<"4 删除链表结点"<<endl;
//    cout<<"5 删除整个链表"<<endl;
//    cout<<"6 退出"<<endl;
//
//    cout<<endl<<endl;
//    cout<<"请输入功能序号:";
//    cin>>choice;
//    return operation(choice);
//}
//
///*对应操作菜单--创建链表的操作*/
//void Create()
//{
//    if(head==NULL) //如果链表中已有结点，不允许重新建立
//    {
//        head=CreateList( );
//    }
//    else
//    {
//        cout<<"已创建过链表，不允许再次创建"<<endl;
//        cout<<"如果想重新创建，先删除原先链表"<<endl;
//    }
//}
//
///*对应操作菜单--遍历链表的操作*/
//void Print( )
//{
//    PrintList(head);
//}
//
///*对应操作菜单--插入链表结点的操作*/
//void Insert( )
//{
//    char IsGo;  //是否继续操作标志
//    IsGo='y';
//    cout<<endl<<"开始进行结点插入操作"<<endl;
//    node *stu;
//    while(IsGo=='y'||IsGo=='Y')
//    {   stu=new node;    //创建要插入的新结点
//        cout<<endl<<"输入要插入的新结点数据:";
//        cin>>stu->data;      //输入要插入的新结点数据
//        head=InsertNode(head,stu);    //调用插入函数，返回链表头指针
//        cout<<"是否继续插入新结点? (继续插入请按y或Y,退出请按其它键)";
//        cin>>IsGo;
//    }
//    cout<<endl<<"结点插入操作结束"<<endl;
//}
//
///*对应操作菜单--删除链表结点的操作*/
//void Delete( )
//{
//    char IsGo;  //是否继续操作标志
//    int del_num;	//要删除的结点的数据
//    IsGo='y';
//    cout<<endl<<"开始进行结点插入操作"<<endl;
//    while(IsGo=='y'||IsGo=='Y')
//    {
//        cout<<endl<<"输入要删除的节点的数据:";  //输入要插入的结点
//        cin>>del_num;  //输入要删除的结点的数据
//        head=DeleteNode(head,del_num);    //删除后链表的头地址
//        cout<<"是否继续删除结点? (继续插入请按y或Y,退出请按其它键)";
//        cin>>IsGo;
//    }
//    cout<<endl<<"结点删除操作结束"<<endl;
//}
//
///*对应操作菜单--删除整个链表的操作*/
//void DeleteAll()
//{
//    head=deleteList(head);
//
//}
