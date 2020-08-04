#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+5;
const int mod=1e9+7;
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int,int> pii;
ll qpow(ll a,ll b){ll ans=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)ans=ans*a%mod;a=a*a%mod;}return ans;}
ll gcd(ll a,ll b){return b>0?gcd(b,a%b):a;}
int n,m,T;
ll t[maxn];
int cnt[2];
struct node{
	ll pre,num;
	bool operator<(const node B)const{
		return pre<B.pre;
	}
}a[maxn];
void update(int bit){
	ll temp=(1ll<<m)-(1<<(m-bit));
	for(int i=1;i<=n;i++){
		a[i].pre=a[i].num&temp;	
	}
}
void rev(int bit){
	ll temp=1<<(m-bit);
	for(int i=1;i<=n;i++){
		a[i].num=a[i].num^temp;
	}
}
bool check(int bit){
	ll temp=(1ll<<m)-(1<<(m-bit));
	for(int i=1;i<=n;i++){
		if(a[i].pre!=(t[i]&temp)){
			return 0;
		}	
	}
	return 1;
}
int ans;
void dfs(int t,int cnt){
	if(t>n){
		if(ans==-1) ans=cnt;
		else ans=min(ans,cnt);
		return;
	}
	update(t);
	sort(a+1,a+1+n);
	if(check(t)){
		dfs(t+1,cnt);
	}
	
	rev(t);
	
	update(t);
	sort(a+1,a+1+n);
	if(check(t)){
		dfs(t+1,cnt+1);
	}
	
	rev(t);
} 
int main() {
	cin>>T;
	while(T--){
		cin>>n>>m;
		string x;
		ans=-1; 
		for(int i=1;i<=n;i++){
			cin>>x;
			ll temp=0;
			for(auto c:x){
				temp=temp*2ll+c-'0';
			}
			a[i].num=temp;
		}
		
		for(int i=1;i<=n;i++){
			cin>>x;
			ll temp=0;
			for(auto c:x){
				temp=temp*2ll+c-'0';
			}
			t[i]=temp;
		}
		sort(t+1,t+1+n);
		dfs(1,0);
		if(ans==-1){
			cout<<"Impossible\n";
		}else{
			cout<<ans<<"\n";
		}
	}
	return 0;
}
/*
10
2 2
10 01
00 11


*/




