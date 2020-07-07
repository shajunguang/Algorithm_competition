//
// Created by liu on 19-8-26.
//

//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <numeric>
//#include <string>
//#include <sstream>
//
//using namespace std;
//
//int solve_fre(vector<int>& nums){
//    int max_fre = 0,fre;
//    vector<int> nums_fre(nums.size(),0);
//    for(int i=0;i<nums.size();i++){
//        nums_fre[i]=1;
//        for(int j=i+1;j<nums.size();j++){
//            if(nums[j]==nums[i])    nums_fre[j]=1;
//        }
//        fre= accumulate(nums_fre.begin(),nums_fre.end(),0);
//        if(fre>=max_fre)    { max_fre=fre;}
//        fill(nums_fre.begin(),nums_fre.end(),0);
//    }
//    return max_fre;
//}
//
//int solve_fre_i(vector<int>& nums){
//    int max_fre = 0,fre,t;
//    vector<int> nums_fre(nums.size(),0);
//    for(int i=0;i<nums.size();i++){
//        nums_fre[i]=1;
//        for(int j=i+1;j<nums.size();j++){
//            if(nums[j]==nums[i])    nums_fre[j]=1;
//        }
//        fre= accumulate(nums_fre.begin(),nums_fre.end(),0);
//        if(fre>=max_fre)    { max_fre=fre;t=i;}
//        fill(nums_fre.begin(),nums_fre.end(),0);
//    }
//    return t;
//}
//
//int main()
//{
//    vector<int> nums;
//    int fre_max,fre;
//    string line;
//    getline(cin,line);
//    stringstream ss(line);
//    int num=0,t;
//    while(ss>>num)
//        nums.push_back(num);
//    fre_max = solve_fre(nums);
//    t = solve_fre_i(nums);
//    vector<int> nums_t(nums.begin()+t,nums.end());
//    while(nums_t.size()>=1){
//        nums_t.pop_back();
//        fre=solve_fre(nums_t);
//        if(fre != fre_max)  {
//            cout<< nums_t.size()+1 <<endl;
//            break;
//        }
//    }
//}