#include<bits/stdc++.h>
using namespace std;

const int MAXN=1000;

struct Student{
    int id;
    string name;
    int grade;
}a[MAXN];

int main()
{
    freopen("in.txt","r",stdin);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i].id>>a[i].name>>a[i].grade;
    string target;
    while(cin>>target) {
        int j=n;
        while (j > 0 && a[j].name != target) {
            j--;
        }
        if (!j) cout << target << " is not in system!"<<endl;
        else cout << a[j].id << " " << a[j].grade<<endl;
    }
    return 0;
}