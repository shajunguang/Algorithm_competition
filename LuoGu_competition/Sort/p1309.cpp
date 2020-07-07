#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+1;
struct Player{
    int order;
    int grade;
    int power;
}pl[MAXN],loser[MAXN],winer[MAXN];
bool cmp(const Player &a,const Player &b){
    if(a.grade!=b.grade) return a.grade>b.grade;
    return a.order<b.order;
}
int main()
{
    int N,R,Q;
    cin>>N>>R>>Q;
    for(int i=1;i<=2*N;i++){
        pl[i].order=i;
        cin>>pl[i].grade;
    }
    for(int i=1;i<=2*N;i++) cin>>pl[i].power;
    sort(pl+1,pl+2*N+1,cmp);
    for(int i=1;i<=R;i++) {
        for (int j = 2; j <= 2 * N; j += 2) {
            if (pl[j].power > pl[j - 1].power) {
                pl[j].grade++;
                loser[j/2]=pl[j-1];
                winer[j/2]=pl[j];
            } else {
                pl[j - 1].grade++;
                loser[j/2]=pl[j];
                winer[j/2]=pl[j-1];
            }
        }
        merge(loser+1,loser+N+1,winer+1,winer+N+1,pl+1,cmp); //O(n)
    }
    //O(R*4*N)
    cout<<pl[Q].order;
    return 0;
}