//
// Created by liu on 19-10-17.
//

//#include<iostream>
//#include<cstdio>
//#include<cstdlib>
//#include<cstring>
//#include<string>
//#include<vector>
//#include<map>
//#include<cctype>
//#include<sstream> //stringstream
//using namespace std;
//typedef unsigned int uint;
//const int maxn = 1010;
//int dcnt, ans;
//bool bug;
//vector<string> vs;
//map<string, string> value;
//map<string, unsigned int> mdes;
//string get_val(string index, string name) //递归调用,返回下标的实数值(字符串形式)
//{
//    uint v = 0;
//    if(index.find('[') == index.npos) //直接是一个实数
//    {
//        stringstream ss(index); ss >> v;
//        if(name != " " && mdes[name] <= v) //容易理解mdes[name] <= v表示数组的下标越界
//            //而name == " "的情况为定义语句a[3];或赋值语句等号右值（这里理解的也不透彻。。。）
//            bug = true;
//        return index;
//    }
//    string pname, pindex;
//    pname = index.substr(0, index.find('['));
//    pindex = index.substr(index.find('[')+1, index.find_last_of(']')-2);
//    pindex = get_val(pindex, pname);
//    if(bug) return " ";
//    string vv;
//    vv = pname+"["+pindex+"]";
//    if(!value.count(vv)) bug = true; //若下标未初始化，则bug
//    return value[vv];
//}
//void Define(string str)
//{
//    string name, index; uint v = 0;
//    name = str.substr(0, str.find('['));//提取数组名
//    index = str.substr(str.find('[')+1, str.find_last_of(']')-2); //提取数组下标
//    index = get_val(index, " "); //此处" "意在区别赋值语句调用该函数的情况；
//    stringstream ss(index);     ss >> v;
//    mdes[name] = v;//存入数组name的范围
//}
//void Assign(string str)
//{
//    string L, R, name, index; uint v = 0;
//    L = str.substr(0, str.find('=')); R = str.substr(str.find('=')+1);
//    /*等号左边*/
//    name = L.substr(0, L.find('['));
//    ///find_last_of();
//    index = L.substr(L.find('[') + 1, L.find_last_of(']')-2);
//    index = get_val(index, name);
//    if(bug) {return;}
//    stringstream ss(index);     ss >> v;
//    if(v >= mdes[name]) {bug = true; return;}
//    /*赋值*/
//    string left_value, right_value;
//    left_value = name+"["+index+"]";
//    right_value = get_val(R, " ");
//    value[left_value] = right_value;
//}
//void init()
//{
//    mdes[" "] = 0;//初始化" "代表的数组大小为0，此主要为以后求数组下标值时区别赋值语句与定义语句(及赋值语句等号右边)。
//    vs.clear();
//    mdes.clear();
//    value.clear();
//}
//int main()
//{
//    //freopen("in.txt", "r", stdin);
//    string str;
//    while(cin >> str && str[0] != '.')
//    {
//        init();
//        vs.push_back(str);
//        while(cin >> str && str[0] != '.')
//        {
//            vs.push_back(str);
//        }
//        bug = false;
//        for(int i = 0; i < vs.size(); i++)
//        {
//            if(vs[i].find('=') == vs[i].npos)
//            {
//                Define(vs[i]);
//            }
//            else
//                Assign(vs[i]);
//            if(bug)
//            {
//                cout << i+1 << endl;
//                break;
//            }
//            if(!bug && i == vs.size()-1)
//                cout << 0 << endl;
//        }
//    }
//    return 0;
//}