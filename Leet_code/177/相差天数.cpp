#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int stringto_int(string s){
        int t=0;
        for(int i=0;i<s.size();i++) t=t*10+s[i]-'0';
        return t;
    }
    bool isRunYear(int y){
        return (y%4==0 && y%100!=0) || (y%400==0);
    }
    int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int daysBetweenDates(string s1, string s2) {
        int y1=0,m1=0,d1=0,y2=0,m2=0,d2=0;
        y1=stringto_int(s1.substr(0,4));
        y2=stringto_int(s2.substr(0,4));
        if(y1>y2) swap(y1,y2),swap(s1,s2);
        m1=stringto_int(s1.substr(5,2));
        m2=stringto_int(s2.substr(5,2));
        d1=stringto_int(s1.substr(8));
        d2=stringto_int(s2.substr(8));
        cout<<y1<<" "<<y2<<" "<<m1<<" "<<m2<<" "<<d1<<" "<<d2<<endl;

        int t1=0,t2=0,t3=0;

        for(int i=1;i<m1;i++){
            if(i==2) {t1+=(isRunYear(y1)?29:28);continue;}
            t1+=month[i-1];
        }
        t1+=d1;
        t1=(isRunYear(y1)?366:365)-t1;

        for(int i=y1+1;i<y2;i++)
            t2+=isRunYear(i)?366:365;


        for(int i=1;i<m2;i++){
            if(i==2) {t3+=(isRunYear(y2)?29:28);continue;}
            t3+=month[i-1];
        }
        t3+=d2;
        cout<<t1<<" "<<t2<<" "<<t3<<endl;

        return y1==y2?abs(t1+t3-(isRunYear(y1)?366:365)):t1+t2+t3;
    }
};
int main()
{
    string s1="1971-06-29",s2="2010-09-23";
    Solution res;
    int ans=res.daysBetweenDates(s1,s2);
    cout<<ans;
    return 0;
}