//
// Created by liu on 19-10-10.
//

//#include <bits/stdc++.h>
//using namespace std;
//
//int ans[25][25][25];
//
//int w(long long a,long long b,long long c){
//    if(a<=0 || b<=0 || c<=0)   return 1;
//    else if(ans[a][b][c])  return ans[a][b][c];
//    else if(a>20 || b>20 || c>20)    ans[a][b][c]=w(20,20,20);
//    else if(a<b && b<c)  ans[a][b][c]=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
//    else  ans[a][b][c]=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
//    return ans[a][b][c];
//}
//
//int main()
//{
//    long long a,b,c;
//    while(cin>>a>>b>>c && (a!=-1 || b!=-1 || c!=-1)){
//        memset(ans,0,sizeof ans);
//        if(a>20) a=21;
//        if(b>20) b=21;
//        if(c>20) c=21;
//        cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<w(a,b,c)<<endl;
//    }
//}

//记忆宏（大佬解法）
//#include<bits/stdc++.h>
//using namespace std;
//
//#define W_MEM(x,y,z) (w_mem[x][y][z] ? w_mem[x][y][z] : w_mem[x][y][z] = w(x, y, z))
//
//int a=1,b=1,c=1;
//int w_mem[25][25][25];
//
//int w(int a, int b, int c){
//    if(a<=0 || b<=0 || c<=0) return 1;
//    if(a > 20 || b > 20 || c > 20) return W_MEM(20,20,20);
//    if(a < b && b < c) return W_MEM(a,b,c-1)+W_MEM(a,b-1,c-1) - W_MEM(a,b-1,c);
//    return W_MEM(a-1,b,c)+W_MEM(a-1,b-1,c)+W_MEM(a-1,b,c-1) - W_MEM(a-1,b-1,c-1);
//}
//
//int main(){
//    while(1){
//        cin>>a>>b>>c;
//        if(a==-1 && b==-1 && c==-1) break;
//        cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<w(a,b,c)<<endl;
//    }
//}