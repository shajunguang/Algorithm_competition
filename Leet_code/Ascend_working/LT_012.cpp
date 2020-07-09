/*
罗马数字包含以下七种字符： I， V， X， L，C，D 和 M。
思路：对比十进制表示法，同位数，超过一次累加一次，罗马也一样
 */
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
        int values[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string reps[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

        string res;
        for(int i=0; i<13; i++){
            while(num>=values[i]){
                num -= values[i]; //不断减表示法
                res += reps[i];
            }
        }
        return res;
    }
};