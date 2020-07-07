////
//// Created by liu on 19-8-22.
////
//
//#include <iostream>
//
//using namespace std;
//
//class A{
//public:
//    A();
//};
//
//class B{
//public:
//    explicit  B(int x=0, bool b = true);
//};
//
//class C{
//public:
//    explicit C(int x);
//};
//
//void dosomthing(B obj);
//
//int main()
//{
//    B obj1;
//    dosomthing(obj1);
//    B obj2(28);
//
//    //dosomthing(28);  //int到B没有隐式转换
//    dosomthing(B(28));
//
//}