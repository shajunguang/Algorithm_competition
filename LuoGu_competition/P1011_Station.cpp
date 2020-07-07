//
// Created by liu on 19-9-21.
//

//#include <bits/stdc++.h>
//using namespace std;
//
//const int MAXN = 25;
//int pnums[MAXN],up[MAXN];
//
//int main()
//{
//    int a,n,m,x;
//    cin>>a>>n>>m>>x;
//    pnums[0]=pnums[1]=a;
//    pnums[2]=2*a;
//    for(int i=0;i<=m-a;i++){
//        up[0]=a;
//        up[1]=i;
//        pnums[3]=pnums[2]+up[1];
//        for(int j=2;j<=n-1;j++){
//            up[j]=up[j-1]+up[j-2];
//            pnums[j+2]=pnums[j+1]+up[j];
//        }
//        if(pnums[n-2]==m){
//            cout<<pnums[x-1];
//            break;
//        }
//    }
//    return 0;
//}

// 更加数学的方法,直接把第二站上下车人数计算出来,根据系数的性质

//#include<bits/stdc++.h>
//using namespace std;
//int Cft_a[25]={0,1,1,2},Cft_b[25]={0,0,0,0};//Coefficient n.系数
//int a,b,n,m,x;
//int main()
//{
//    scanf("%d%d%d%d",&a,&n,&m,&x);
//    for(int i=4;i<n;i++)
//    {
//        Cft_a[i]=Cft_a[i-2]+Cft_a[i-1]-1;
//        Cft_b[i]=Cft_b[i-2]+Cft_b[i-1]+1;
//    }
//    b=(m-a*Cft_a[n-1])/Cft_b[n-1];
//    printf("%d",a*Cft_a[x]+b*Cft_b[x]);
//    return 0;
//}