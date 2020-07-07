#include<bits/stdc++.h>
using namespace std;

struct Stu{
    int order;
    string name;
    int grade_end,grade_class;
    char st_cadre,west_st;
    int paper_num;
    int money;
}st[105];
bool cmp(const Stu &a, const Stu &b){
    if(a.money!=b.money) return a.money>b.money;
    return a.order<b.order;
}
int main()
{
    int N,sum=0;
    cin>>N;
    for(int i=1;i<=N;i++){
        st[i].order=i;
        st[i].money=0;
        cin>>st[i].name>>st[i].grade_end>>st[i].grade_class>>st[i].st_cadre>>st[i].west_st>>st[i].paper_num;
        if(st[i].paper_num>0 && st[i].grade_end>80) st[i].money+=8000;
        if(st[i].grade_end>85 && st[i].grade_class>80) st[i].money+=4000;
        if(st[i].grade_end>90) st[i].money += 2000;
        if(st[i].grade_end>85 && st[i].west_st=='Y') st[i].money+=1000;
        if(st[i].grade_class>80 && st[i].st_cadre=='Y') st[i].money+=850;
        sum+=st[i].money;
    }
    sort(st+1,st+N+1,cmp);
    cout<<st[1].name<<endl<<st[1].money<<endl<<sum<<endl;
    return 0;
}