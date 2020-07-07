//#include <iostream>
//#include <cstring>
//#include <string>
//#include<sstream>
///*注释这个对程序没有影响  string.h等价与cstring表示c中string类,注意string不是
// * string.h的升级版
//*/
//#include<cstdlib>
//#include<cmath>
//#include<vector>
//#include <algorithm>
//#include <regex>
//#include <map>
//#include <set>
////#include<time.h>
//#define local
//#define INF 1000000000
//#define pi acos(-1)
//#define maxn 1000000
////#define length(array, len) { len=sizeof(array)/sizeof(array[0]);}
//char maps[5][7];
//char cmd[1001];
////char s[maxn];
//const char* rev = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
////int l,chance,win,lose;
////char s[100],s1[100];
////int n, k, m, s[25];
//int readchar();
//int readint(int c);
//int code[8][1<<8]; //<<有符号左移位，将运算数的二进制整体左移指定位数，低位用0补齐。
//int readcodes();
//int go(int p,int d,int t);
//void guess(char ch);
//char r(char ch);
//int small(const char*s, int p, int q);
//int hamming(char *s1,char *s2);
//int little(char *s1,char *s2);
//bool check();
//long long C(int n, int m);
//int is_prime(int n);
//int myAtoi(std::string str);
//
//using namespace std;
//
//struct face{
//    int x, y;
//}a[6];
//
//struct Point{
//    int x,y;
//    Point(int x=0, int y=0):x(x),y(y){}
//};
//
//Point operator + (const Point& A, const Point& B){
//    return Point(A.x+B.x, A.y+B.y);
//}
//
//ostream& operator << (ostream &out, const Point& p){
//    out<<"("<<p.x<<","<<p.y<<")";
//    return out;
//}
//
//int main() {
////    cout.setf(ios::fixed);
////    cout.setf(ios::showpoint);
////    cout.precision(2);
////    double price=78.5;
////    cout<<"Price is "<<price<<endl;
////    string user_name;
////    int feet= 1;
////    cout<<feet<<endl;
////    char a='b';
////    char b='c';
////    char c=a;
////    cout<<a<<b<<c<<'c'<<endl;
////    int j=-1, i=2;
////    int n=1/(j+1);
////    if(j>0 && 1/(j+1)>10)   cout<<i<<endl;
////    cout<<"Please input your name:";
////    cin>>user_name;
////    cout<<"Hello! "<<user_name<<".Goodbye!"<<endl;
//
////读入文件读出文件
////#ifdef local
////    freopen("test.txt","r",stdin);
////    freopen("out.txt","w",stdout);
////#endif
////    string str[100];
////    for(int i;i<99;++i)
////    {
////        cin>>str[i];
////    }
////    for(int i;i<99;++i)
////    {
////        if(str[i]=="hate")
////        {
////            str[i]="love";
////        }
////        cout<<str[i]<<" ";
////    }
////
////    int facobbi(int n);
////    cout<<facobbi(4)<<endl;
////    srand(98);
////    for(int i=0;i<10;++i)
////        cout<<rand()%11<<" ";
////    cout<<endl;
////    cout<<1.0/0.0<<endl;
////    int a,b,c;
////    scanf("%d %d %d",&a,&b,&c);
////    cout.setf(ios::fixed);
////    cout.setf(ios::showpoint);
////    cout.precision(3);
////    cout<<(a+b+c)/3.0<<endl;
////    printf("%.3f",(a+b+c)/3.0);
////    double f,c;
////    scanf("%lf",&f);
////    c=5*(f-32)/9;
////    printf("%.3f",c);
////    int n;
////    scanf("%d",&n);
////    printf("%f %f",sin(n/180.0*pi),cos(n/180.0*pi));
////    int n;
////    scanf("%d",&n);
////    if(n*95<300)
////    {
////        printf("%.2f",n*95);
////    }
////    else
////    {
////        printf("%.2f",n*95*0.85);
////    }
////    int a,b,c,t;
////    scanf("%d %d %d",&a,&b,&c);
////    if(a>b){t=a;a=b;b=t;}  //使得a<=b
////    if(a>c){t=a;a=c;c=t;}
////    if(b>c){t=b,b=c;c=t;}
////    if(a*a+b*b==c*c)
////    {
////        printf("This is a triangle!");
////    }
////    else
////    {
////        printf("This is not triangle!");
////    }
////    int year;
////    while(scanf("%d",&year)!=EOF && year!=0)
////    {
////        if(year%4==0 && year%100!=0)
////        {
////            printf("This year is runyear!\n");
////        }
////        else if(year%100==0 && year%400==0)
////        {
////            printf("The year is runyear!\n");
////        }
////        else
////        {
////            printf("The year is pinyear!\n");
////        }
////    }
////    cout<<INT8_MAX<<" "<<INT16_MAX<<endl;
////    cout<<pow(2,15)<<endl;
////    int i=1;
////    while(i>0)
////    {
////        i++;
////    }
////    printf("%d %d",i,i-1);
////    printf("%.51f",10.0/3.0);
////    int n;
////    scanf("%d",&n);
////    for(int i=1;i<=n;i++)
////        printf("%d\n",i);
//
//// aabb是不是完全平方数
//
////    for(int i=1;i<=9;++i)
////        for(int j=0;j<=9;++j)
////        {
////            int n = i*1100 + j*11;
////            int m = floor(sqrt(n)+0.5);
////            if(m*m==n)
////                printf("%d\n",n);
////        }
//
//// 3n+1问题
//
////    int n1;
////    while(scanf("%d",&n1)!=EOF && n1!=0)
////    {
////        int count = 0;
////        long long n = n1;
////        while(n > 1)
////        {
////            if(n % 2 == 1)  n = n*3 + 1;
////            else    n /= 2;
////            count++;
////        }
////        printf("%d\n",count);
////    };
//
//// 近似计算
////    double sum;
////    int i=0;
////    double term;
////    do
////    {
////        term = 1.0 / (2*i+1);
////        if(i%2 == 0)    sum += term;
////        else    sum -= term;
////        i++;
////    } while(term >=  1e-6);
////    printf("%.6f\n",sum);
//
////计算阶之和
//
////#ifdef local
////    freopen("in.txt","r",stdin);
////    freopen("out.txt","w",stdout);
////#endif
////    const int mod = 1000000;
////    int n;
////    while(scanf("%d",&n) != EOF && n!=0)
////    {
////        int s=0;
////        for(int i=1;i<=n;i++)
////        {
////            int fac=1;
////            for(int j=1;j<=i;j++)
////            {
////                fac=(fac*j%mod);
////            }
////            s = (s+fac)%mod;
////        }
////        printf("%d\n",s);
////        printf("Time used = %.2f",(double)clock()/CLOCKS_PER_SEC);
////        printf("s\n");
////    }
//
////数据统计（重定向版本）
//
////#ifdef local
////    freopen("in.txt","r",stdin);
////    freopen("out.txt","w",stdout);
////#endif
////    int x,n = 0, min = INF, max = -INF, s=0;
////    while (scanf("%d",&x)==1)
////    {
////        s += x;
////        if(x<min)   min=x;
////        if(x>max)   max=x;
////        /*
////        printf("x = %d, min = %d, max = %d\n",x, min,max);
////        */
////        n++;
////    }
////    printf("%d %d %.3f\n", min, max, (double)s/n);
//
////数据统计（fopen版本）
//
////    FILE *fin, *fout;
////    fin=fopen("data.in","rb");
////    fout=fopen("data.out","wb");
////    /*要改成标准输入输出流*/
////    /*
////     fin=stdin;
////     fout=stdout;
////     */
////    int x,n,m=0;
////    while (fscanf(fin,"%d",&n)==1 && n!=0)
////    {
////
////        int s=0, min = INF, max = -INF;
////        int count=n;
////        while(n--)
////        {
////            fscanf(fin,"%d",&x);
////            s += x;
////            if(x<min)   min=x;
////            if(x>max)   max=x;
////            //fprintf(fout, "s = %d, min = %d, max = %d\n",s, min,max);
////        }
////        /*处理结果之间要空行的好办法，如果直接在结果后面加的话，运行完会留空行*/
////        if(m)  fprintf(fout,"\n");
////        fprintf(fout,"Case %d: %d %d %.3f\n", ++m, min, max, (double)s/count);
////    }
////    fclose(fin);
////    fclose(fout);
//
//// 求100～999的水仙花数，即等于各位三次方和的数
////    int n=0;
////    for(int i=100;i<1000;i++)
////    {
////        int a=i/100;
////        int b=i/10%10;
////        int c=i%10;
////        int ans=pow(a,3)+pow(b,3)+pow(c,3);
////        if(i==ans)  printf("No%d: %d\n",++n,i);
////    }
//
//// 韩信点兵
//
////    int a,b,c,n=0;
////    while(scanf("%d %d %d",&a,&b,&c)==3)
////    {
////        bool flag= true;
////        for(int i=10;i<=100;i++)
////        {
////            if(i%3==a && i%5==b && i%7==c)
////            {
////                printf("Case %d: %d\n",++n,i);
////                flag= false;
////                break;
////            }
////        }
////        if(flag)  printf("Case %d: No answer\n",++n);
////    }
//
////输出倒三角形
//
////    int n;
////    while(scanf("%d",&n)==1 && n)
////    {
////        for(int j=n;j>0;j--)
////        {
////            for(int k=0;k<n-j;k++)  printf(" ");
////            for(int i=0;i<2*j-1;i++)
////            {
////                 printf("#");
////            }
////            printf("\n");
////        }
////
////    }
//
////子序列的和
//
////    int m,n,k=0;
////    while(scanf("%d %d",&n,&m)==2 && m)
////    {
////        double s = 0;
////        for(int i=n;i<=m;i++)
////        {
////            s += (1.0/i)*(1.0/i);
////            /*
////            printf("i= %d, s= %.5f\n",i,s);//调试程序
////            */
////        }
////        printf("Case %d: %.5f\n",++k,s);
////    }
//
////分数化小数
//
////    int a,b,c,m=0;
////    while(cin>>a>>b>>c && b)
////    {
////        double ans = (double)a/b;
////        ++m;
////        cout.setf(ios::fixed);
////        cout.setf(ios::showpoint);
////        cout.precision(c);
////        cout<<"Case "<<m<<": "<<ans<<endl;
////    }
//
////排列
//
////    for(int i=100;i<1000;i++)
////    {
////        int a=i/100;
////        int b=i/10%10;
////        int c=i%10;
////        if(a!=b && a!=c && b!=c && a*b*c !=0)
////        {
////            for(int j=100;j<1000;j++)
////            {
////                int d=j/100;
////                int e=j/10%10;
////                int f=j%10;
////                if(d!=e && d!=f && e!=f && d*e*f !=0)
////                {
////                    for(int k=100;k<1000;k++)
////                    {
////                        int g=k/100;
////                        int h=k/10%10;
////                        int l=k%10;
////                        if(g!=h && g!=l && h!=l && g*h*l !=0)
////                        {
////                            int ans=a+b+c+d+e+f+g+h+l;
////                            int ans1=a*b*c*d*e*f*g*h*l;
////                            if(j==2*i && k==3*i && ans == 45 && ans1==362880)
////                                printf("%d %d %d\n",i,j,k);
////                        }
////                    }
////                }
////            }
////        }
////    }
////    for(int i=1;i<10;i++)
////    {
////        for(int j=1;j<10;j++)
////        {
////            if(j!=i)
////            {
////                for(int k=1;k<10;k++)
////                {
////                    if(k!=j && k!=i)
////                    {
////                        int a=i*100+j*10+k;
////                        int b,c;
////                        if(a*2<999) b=a*2;
////                        if(a*3<999) c=a*3;
////                        int b1=b/100;
////                        int b2=b/10%10;
////                        int b3=b%10;
////                        int c1=c/100;
////                        int c2=c/10%10;
////                        int c3=c%10;
////                        int ans=i+j+k+b1+b2+b3+c1+c2+c3;
////                        if(ans==45 && b1!=b2 && b1!=b3 && b2!=b3 && c1!=c2 && c1!=c3 && c2!=c3)
////                            printf("%d %d %d\n",a,b,c);
////                    }
////                }
////            }
////        }
////    }
//
//// 和数字相关可以理解为下标！判断下标存在比较简单
//
////    int abc, def, ghi;
////    for (abc = 123; abc<=329; ++abc) {
////        bool visit[10] = {false}; //统计0~9是否出现
////        //标记abc各位
////        visit[abc / 100] = visit[abc / 10 % 10] = visit[abc % 10] = true;
////        //标记def各位
////        def = 2 * abc;
////        visit[def / 100] = visit[def / 10 % 10] = visit[def % 10] = true;
////        //标记ghi各位
////        ghi = 3 * abc;
////        visit[ghi / 100] = visit[ghi / 10 % 10] = visit[ghi % 10] = true;
////        //检查完全性
////        bool flag = true;
////        for (int i = 1; i <= 9; ++i)
////            if (visit[i] != true) {
////                flag = false;
////                break;
////            }
////        if (flag)
////            printf("%d %d %d\n", abc, def, ghi);
////    }
////    double i;
////    for(i=0;i!=10.0-0.000000000000020;i += 0.1)
////    {
////        printf("%.1f %.17f\n",i,i-10.0);
////        if(i>20)
////            break;
////    }
//
//
//// 开灯问题 注意：保证不多输出空格和空行可以采用加标志变量的方法
//
////    int n,k;
////    while(scanf("%d %d",&n,&k)==2 && k)
////    {
////        int first = 1;
////        bool a[n];
////        for(int i=0;i<n;i++)    a[i]=true;
////        for(int j=2;j<=k;j++)
////        {
////            for(int i=0;i<n;i++)
////            {
////                if((i+1)%j==0)
////                {
////                    a[i]= !a[i];
////                }
////            }
////        }
////       for(int i=0;i<n;i++)
////       {
////           if(a[i])
////           {
////               if(first)    first=0;
////               else printf(" ");
////               printf("%d",i+1);
////           }
////       }
////       printf("\n");
////    }
//
//
//// 蛇形填数 注意输出可以控制格式和长度，甚至可以确定保留的位数
//
////    int a[20][20];
////    int n,x,y,tot=0;
////    scanf("%d", &n);
////    memset(a,0,sizeof(a));
////    tot = a[x=0][y=n-1]=1;
////    while(tot<n*n)
////    {
////        while(x+1<n && !a[x+1][y])  a[++x][y] = ++tot;
////        while(y-1>=0 && !a[x][y-1])  a[x][--y] = ++tot;
////        while(x-1>=0 && !a[x-1][y])  a[--x][y] = ++tot;
////        while(y+1<n && !a[x][y+1])  a[x][++y] = ++tot;
////    }
////    for(x = 0;x<n;x++)
////    {
////        for(y=0;y<n;y++)    printf("%-4d",a[x][y]);
////        /*
////         *  %3d   可以指定宽度，不足的左边补空格
////            %-3d  左对齐
////            %03d  一种左边补0 的等宽格式,比如数字12,%03d出来就是: 012
////         * */
////        printf("\n");
////    }
//
////竖式问题 注意：字符可以当作int来使用，另外使用scanf碰到空格和回车默认停止，另外printf
////打印时也可以像cout语句一样，一句输出多个输出行。
//
////    int count=0;
////    char s[20],buf[99];
////    scanf("%s",s);
////    for(int abc=111;abc<=999;abc++)
////    {
////        for(int de=11;de<=99;de++)
////        {
////            int x= abc*(de%10),y=abc*(de/10),z=abc*de;
////            sprintf(buf,"%d%d%d%d%d",abc,de,x,y,z);
////            /*
////             * printf,fprintf,sprintf输出三兄弟，一个输出到屏幕，输出到文件，输出到字符串中，第三个
////             * 保证字符串足够的空间
////             * */
////            int ok =1;
////            for(int i=0;i<strlen(buf);i++)
////                //strchr判断两个字符数组是否存在相同字符
////                if(strchr(s,buf[i])==NULL)  ok=0;
////            if(ok)
////            {
////                printf("<%d>\n",++count);
////                printf("%5d\nx%4d\n-----\n%5d\n%4d\n-----\n%5d\n\n",abc,de,x,y,z);
////            }
////        }
////    }
////    printf("The number of solutions = %d\n", count);
//
//// Tex Quotes UVa 272
//
////    FILE *fin, *fout;
////    fin=fopen("data.in","rb");
////    fout=fopen("data.out","wb");
////    int c, q = 1;
////    while((c = fgetc(fin)) != EOF) //getchar()是一个一个字符读入！等价与fgetc(stdin)
////    {
////        if(c == '"')
////        {
////            fprintf(fout,"%s",q ? "``" : "''"); //机智！
////            q = !q;
////
////        }
////        else    fprintf(fout,"%c",c);
////    }
//
//
////    char c;//根据ASCALL码值，其实字符也是特殊的整数，可以用int定义
////    int q = 1;
////    while((c = getchar()) != EOF) //getchar()是一个一个字符读入！等价与fgetc(stdin)
////    {
////        if(c == '"')
////        {
////            printf("%s",q ? "``" : "''"); //机智！
////            q = !q;
////
////        }
////        else    printf("%c",c);
////    }
//
////WERTYU UVa10082
//
////    char s[]="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./"; //中间两个斜杠，转义
////    int c,i;
////    while((c=getchar()) != EOF)
////    {
////        for(i=1; s[i] && s[i] !=c;i++);
////        if(s[i])    putchar(s[i-1]);
////        else    putchar(c);
////    }
//
////Palindromes uva401 回文和镜像文
//
////#ifdef local
////    freopen("in.txt","r",stdin);
////    freopen("out.txt","w",stdout);
////#endif
////    const char* msg[] = {"not a palindrome","a regular palindrome","a mirrored string",
////                         "a mirrored palindrome"};
////    char s[30];
////    while(scanf("%s",s)!=EOF)
////    {
////        int len = strlen(s);
////        int p = 1, m = 1;
////        for(int i = 0; i<(len+1)/2;i++)
////        {
////            if(s[i] !=s[len-1-i])   p=0; //不是回文串
////            if(r(s[i]) != s[len-1-i])   m=0;//不是镜像串
////        }
////        printf("%s -- is %s.\n\n",s,msg[m*2+p]);
////    }
//
////猜数字游戏提示 Master-Mind Hints, UVa 340
//
////#ifdef local
////    freopen("in.txt","r",stdin);
////    freopen("out.txt","w",stdout);
////#endif
////    int n, a[maxn], b[maxn];
////    int kase = 0;
////    while(scanf("%d",&n) == 1 && n)
////    {
////        printf("Game %d:\n",++kase);
////        for(int i=0;i<n;i++)    scanf("%d",&a[i]);
////        for(;;)
////        {
////            int A=0, B=0;
////            for(int i=0;i<n;i++)
////            {
////                scanf("%d",&b[i]);
////                if(a[i]==b[i])  A++;
////            }
////            if(b[0]==0) break;//判断序列存在0,即跳出循环
////            for(int d=1;d<=9;d++)
////            {
////                int c1 = 0, c2 = 0;
////                for(int i=0;i<n;i++)
////                {
////                    if(a[i]==d) c1++;
////                    if(b[i]==d) c2++;
////                }
////                if(c1<c2)   B += c1; else   B += c2;
////            }
////            printf("    (%d,%d)\n",A,B-A);
////        }
////    }
//
//// 生成元 UVa1583
//
////    int T,n;
////    memset(ans,0, sizeof(ans));
////    for(int m=1;m<maxn;m++)
////    {
////        int x = m, y = m;
////        while(x>0)                                { y += x%10; x /= 10; }
////        if(ans[y] == 0 || m < ans[y])   ans[y] = m;
////    }
////    scanf("%d",&T);
////    while(T--)
////    {
////        scanf("%d",&n);
////        printf("%d\n", ans[n]);
////    }
//
//// 环状序列 UVa1584
//
////    int T;
////    char s[maxn];
////    scanf("%d", &T);
////    while(T--)
////    {
////        scanf("%s", s);
////        int ans = 0;
////        int n =strlen(s);
////        for(int i =1; i<n;i++)
////            if(small(s,i,ans))   ans=i;
////        for(int i=0;i<n;i++)
////            putchar(s[(i+ans)%n]);
////        putchar('\n');
////    }
//
////得分 UVa1585
//
////#ifdef local
////    freopen("in.txt","r",stdin);
////    //freopen("out.txt","w",stdout);
////#endif
////    char s[90];
////    int T;
////    scanf("%d",&T);
////    while(T--)
////    {
////        int m=0, ans=0;
////        scanf("%s",s);
////        for(int i=0;i<strlen(s);i++)
////        {
////            if(i==0 && s[0]=='O')
////            {
////                m=1;
////                ans += m;
////            }
////            if(i>0 && s[i]=='O' && s[i-1]=='X')
////            {
////                m=1;
////                ans +=m;
////            }
////            if(i>0 && s[i]=='O' && s[i-1]=='O')
////            {
////                m++;
////                ans += m;
////            }
////            if(s[i]=='X')   m=0;
////            //printf("m= %d, ans= %d\n", m, ans);
////        }
////        printf("%d\n",ans);
////    }
//
////分子量 UVa1586
//
////#ifdef local
////    freopen("in.txt","r",stdin);
////    //freopen("out.txt","w",stdout);
////#endif
////    char s[85];
////    const char b[]="CHON";
////    const double c[]={12.01,1.008,16.00,14.01};
////    int T;
////    scanf("%d",&T);
////    while(T--)
////    {
////        double ans = 0;
////        scanf("%s",s);
////        char s1[strlen(s)+1];
////        memset(s1,0,sizeof(s1));
////        for(int i=0;i<strlen(s);i++)    s1[i]=s[i];
////        int l1=strlen(s);
////        if(l1==1)
////        {
////            for(int i=0;i<l1;i++)
////            {
////                for(int i1=0;i1<strlen(b);i1++)
////                    if(s1[l1-1]==b[i1])
////                        ans += c[i1];
////            }
////        }
////        else
////        {
////            if(isalpha(s1[l1-1]))
////            {
////                for(int i1=0;i1<strlen(b);i1++)
////                    if(s1[l1-1]==b[i1])
////                        ans += c[i1];
////            }
////            for(int i=0;i<l1;i++)
////            {
////                if(isalpha(s1[i]))
////                {
////                    for(int i1=0;i1<strlen(b);i1++)
////                    {
////                        if(s1[i]==b[i1] && isalpha(s1[i+1]))
////                        {
////                            ans += c[i1];
////                        }
////                        else if(s1[i]==b[i1])
////                        {
////                            int t[10], j1=0;
////                            for(int j=i+1;j<l1;j++)
////                            {
////                                if(isalpha(s1[j]))  break;
////                                t[j-i-1]=s1[j]-'0';
////                                j1++;
////                            }
////                            for(int j=0;j<j1;j++)
////                            {
////                                ans += t[j]*pow(10,j1-j-1)*c[i1];
////                            }
////                        }
////                    }
////                }
////            }
////        }
////        printf("%.3f\n",ans);
////    }
//
//// 数数字 UVa1225
//
////    const char num[] = "0123456789";
////    int n,T;
////    scanf("%d",&T);
////    while(T--)
////    {
////        int k=0;
////        int ans[10];
////        memset(ans,0, sizeof(ans));
////        memset(s,0,sizeof(s));
////        scanf("%d",&n);
////        for(int i=1;i<=n;i++)
////        {
////            char s1[6];
////            sprintf(s1,"%d",i);//输出到字符串，但是会覆盖s1之前的内容
////            strcat(s,s1);
////        }
////        //printf("%s\n",s);
////        for(int i=0;i<strlen(s);i++)
////            for(int j=0;j<strlen(num);j++)
////            {
////                if(s[i]==num[j])    ans[j]++;
////            }
////        for(int i=0;i<10;i++)
////        {
////            if(k) printf(" ");else  k++;
////            printf("%d",ans[i]);
////        }
////        printf("\n");
////    }
//
////周期串 UVa455
//
////#ifdef local
////    freopen("in.txt","r",stdin);
////    //freopen("out.txt","w",stdout);
////#endif
////    char s[85],s1[85];
////    memset(s,0,sizeof(s));
////    int T,kk=0;
////    scanf("%d",&T);
////    while(T--)
////    {
////        scanf("%s",s);
////        int l=strlen(s);
////        for(int i=1;i<=l;i++)
////        {
////            if(l%i==0)
////            {
////                memset(s1,0, sizeof(s1));
////                char ss[i+1];
////                memset(ss,0,sizeof(ss));//数组不会被覆盖
////                for(int j=0;j<i;j++)
////                {
////                    ss[j]=s[j];
////                }
////                for(int k=0;k<l/i;k++)
////                {
////                    strcat(s1,ss);
////                }
////                if(!strcmp(s,s1))
////                {
////                    if(kk)
////                    {printf("\n");}
////                    else   kk++;
////                    printf("%d\n",i);
////                    break;
////                }
////            }
////        }
////    }
//
////  谜题 UVa227
//
////#ifdef local
////    //freopen("in.txt","r",stdin);
////    //freopen("out.txt","w",stdout);
////#endif
////    char s[5][6];
////    char s1[100];
////    int m=0,si=0,sj=0,kk=0,kk2=1;
////    //这里用scanf没法读取带有空格的一行，采用%[^\n]只能读一行跳出循环了，未找到原因。
////    while(fgets(s1,sizeof(s1),stdin) != NULL && (s1[0] != 'Z' || isalpha(s1[1])))
////    //while(scanf("%[^\n]",s1)==1 && (s1[0] != 'Z' || isalpha(s1[1])))
////    {
//////        if(s1[4]=='\n')
//////        {
//////            s1[4]=' ';
//////            s1[5]='\n';
//////        }
////        if(m<5)
////        {
////            sprintf(*(s+m),"%s",s1);
////            for(int i=0;i<6;i++)
////            {
////                if(s1[i]==' ')
////                {
////                    si=m;sj=i;
////                }
////            }
////            m++;
////           // printf("m= %d\n",m);
////        }
////        else
////        {
////            //printf("si= %d, sj= %d\n",si,sj);
////            char t1,t2,t3,t4;
////            for(int i=0;i<strlen(s1);i++)
////            {
////                if(s1[i]=='A')
////                {
////                    if(si==0)
////                    {
////                        if(kk2) kk2=0;else printf("\n");
////                        printf("Puzzle #%d:\nThis puzzle has no final configuration.\n",++kk);
////                        m %= 5;
////                        break;
////                    }
////                    else
////                    {
////                        t1 = s[si][sj];
////                        s[si][sj]=s[si-1][sj];
////                        s[si-1][sj]=t1;
////                        si = si-1;
////                    }
////                }
////                if(s1[i]=='B')
////                {
////                    if(si==4)
////                    {
////                        if(kk2) kk2=0;else printf("\n");
////                        printf("Puzzle #%d:\nThis puzzle has no final configuration.\n",++kk);
////                        m %= 5;
////                        break;
////                    }
////                    else
////                    {
////                        t2 = s[si][sj];
////                        s[si][sj]=s[si+1][sj];
////                        s[si+1][sj]=t2;
////                        si = si+1;
////                    }
////                }
////                if(s1[i]=='L')
////                {
////                    if(sj==0)
////                    {
////                        if(kk2) kk2=0;else printf("\n");
////                        printf("Puzzle #%d:\nThis puzzle has no final configuration.\n",++kk);
////                        m %= 5;
////                        break;
////                    }
////                    else
////                    {
////                        t3 = s[si][sj];
////                        s[si][sj]=s[si][sj-1];
////                        s[si][sj-1]=t3;
////                        sj=sj-1;
////                    }
////                }
////                if(s1[i]=='R')
////                {
////                    if(sj==4)
////                    {
////                        if(kk2) kk2=0;else printf("\n");
////                        printf("Puzzle #%d:\nThis puzzle has no final configuration.\n",++kk);
////                        m %= 5;
////                        break;
////                    }
////                    else
////                    {
////                        t4 = s[si][sj];
////                        s[si][sj]=s[si][sj+1];
////                        s[si][sj+1]=t4;
////                        sj=sj+1;
////                    }
////                }
////                if(s1[i]=='0')
////                {
////                    if(kk2) kk2=0;else printf("\n");
////                    printf("Puzzle #%d:\n",++kk);
////                    for(int i=0;i<5;i++)
////                    {
////                        int kk1=1;
////                        for(int j=0;j<5;j++)
////                        {
////                            if(kk1)   kk1=0;else    printf(" ");
////                            printf("%c",s[i][j]);
////                        }
////                        printf("\n");
////                    }
////                    m %= 5;
////                }
////            }
////        }
////    }
//
////第二个答案
//
//
////    int cases = 0;
////    while (fgets(maps[0],sizeof(maps[0]),stdin)) {
////        if (maps[0][0] == 'Z') break;
////        for (int i = 1 ; i < 5 ; ++ i)
////            fgets(maps[i],sizeof(maps[i]),stdin);
////        int b_x = 0,b_y = 0;
////        for (int i = 0 ; i < 5 ; ++ i)
////            for (int j = 0 ; j < 5 ; ++ j)
////                if (maps[i][j] == ' ') {
////                    b_x = i;b_y = j;
////                    break;
////                }
////        int count = 0;
////        while (~scanf("%c",&cmd[count]))
////            if (cmd[count] != '0') count ++;
////            else break;
////        cmd[count] = 0;getchar();
////
////        int flag = 0,x = b_x,y = b_y;
////        for (int i = 0 ; cmd[i] ; ++ i) {
////            switch(cmd[i]) {
////                case 'A':	x = b_x-1;y = b_y; break;
////                case 'B':	x = b_x+1;y = b_y; break;
////                case 'L':	x = b_x;y = b_y-1; break;
////                case 'R':	x = b_x;y = b_y+1; break;
////            }
////
////            if (x < 0 || x > 4 || y < 0 || y > 4) {
////                flag = 1;break;
////            }else {
////                maps[b_x][b_y] = maps[x][y];
////                maps[x][y] = ' ';
////                b_x = x; b_y = y;
////            }
////        }
////
////        if (cases ++) printf("\n");
////        printf("Puzzle #%d:\n",cases);
////
////        if (flag)
////            printf("This puzzle has no final configuration.\n");
////        else {
////            for (int i = 0 ; i < 5 ; ++ i) {
////                printf("%c",maps[i][0]);
////                for (int j = 1 ; j < 5 ; ++ j)
////                    printf(" %c",maps[i][j]);
////                printf("\n");
////            }
////        }
////    }
//
//// 纵横字谜的答案 UVa232
//
////#ifdef local
////    freopen("in.txt","r",stdin);
////    //freopen("out.txt","w",stdout);
////#endif
////    char s[11][11]; //存放待处理数组最好在循环外面进行声明，否则可能造成runtime error危险！！
////    int r,c,k=0,k1=1;  //数组的行列大小
////    while(scanf("%d %d",&r,&c)==2 && r)
////    {
////        for(int i=0;i<r;i++)
////        {
////            scanf("%s",s[i]);   //待处理的数组
////        }
////        //printf("s[0][0]= %c,s[1][1]= %c\n",s[0][0],s[1][1]);
////        int s1[r][c];    //存放起始位置的数组，包括标号，0代表白格，-1代表黑格
////        int s2[r][c];
////        memset(s1,0, sizeof(s1));
////        memset(s2,0, sizeof(s2));
////        for(int i=0;i<r;i++)
////            for(int j=0;j<c;j++)
////            {
////                if(s[i][j] =='*')
////                {
////                    s1[i][j]=-1;//表示*地方，即黑格位置
////                    s2[i][j]=-1;
////                }
////            }
////        //printf("s1[0][0]= %d,s1[2][2]= %d\n",s1[0][0],s1[2][2]);
////        // 求起始位置
////        int m=1; //记录起始位置的标签在s2中
////        for(int i=0;i<r;i++)
////            for(int j=0;j<c;j++)
////            {
////                if(s1[i][j]==0)
////                {
////                    if(i==0 || j==0)
////                    {
////                        s2[i][j]=m;
////                        m++;
////                    }
////                    else if(s1[i-1][j] != 0 || s1[i][j-1] != 0)
////                    {
////                        s2[i][j]=m;
////                        m++;
////                    }
////                }
////
////            }
//////        for(int i=0;i<r;i++)
//////            for(int j=0;j<c;j++)
//////            {
//////                printf("s2[%d][%d]= %d\n",i,j,s2[i][j]);
//////            }
////        if(k1)  k1=0;else printf("\n");
////        printf("puzzle #%d:\n",++k);
////        printf("Across\n");
////        for(int i=0;i<r;i++)
////            for(int j=0;j<c;j++)
////            {
////                if(s2[i][j] !=0 && s2[i][j] !=-1)
////                {
////                    // 输出across结果
////                    if(j==0)
////                    {
////                        printf("%3d.",s2[i][j]);
////                        for(int j1=j;j1<c;j1++)
////                        {
////                            if(s2[i][j1] ==-1) break;
////                            printf("%c",s[i][j1]);
////                        }
////                        printf("\n");
////                    }
////                    else if(s2[i][j-1] == -1)
////                    {
////                        printf("%3d.",s2[i][j]);
////                        for(int j1=j;j1<c;j1++)
////                        {
////                            if(s2[i][j1] ==-1)  break;
////                            printf("%c",s[i][j1]);
////                        }
////                        printf("\n");
////                    }
////                }
////            }
////        printf("Down\n");
////        for(int i=0;i<r;i++)
////            for(int j=0;j<c;j++)
////            {
////                if(s2[i][j] !=0 && s2[i][j] !=-1)
////                {
////                    // 输出down结果
////                    if(i==0)
////                    {
////                        printf("%3d.",s2[i][j]);
////                        for(int i1=i;i1<r;i1++)
////                        {
////                            if(s2[i1][j] ==-1) break;
////                            printf("%c",s[i1][j]);
////                        }
////                        printf("\n");
////                    }
////                    else if(s2[i-1][j] == -1)
////                    {
////                        printf("%3d.",s2[i][j]);
////                        for(int i1=i;i1<r;i1++)
////                        {
////                            if(s2[i1][j] ==-1)  break;
////                            printf("%c",s[i1][j]);
////                        }
////                        printf("\n");
////                    }
////                }
////            }
////    }
//
//// DNA序列 UVa1368
//
////#ifdef local
////    freopen("in.txt","r",stdin);
////    freopen("out.txt","w",stdout);
////#endif
////    char s[51][1001];
////    int ans[51];
////    int m,n,T,min=INF;
////    scanf("%d",&T);
////    while(T--)
////    {
////        scanf("%d %d",&m,&n);
////        for(int i=0;i<m;i++)
////        {
////            scanf("%s",s[i]);
////        }
////        for(int i=0;i<m;i++)
////        {
////            int si_ans=0;
////            for(int j=0;j<m;j++)
////            {
////                if(j!=i)
////                    si_ans += hamming(s[i],s[j]);
////            }
////            ans[i]=si_ans;
////            if(si_ans<min)  min=si_ans;
////        }
////        int min_num[51],num=0;
////        for(int i=0;i<m;i++)
////        {
////            if(ans[i]==min)
////            {
////                min_num[num]=i;
////                num++;
////            }
////        }
////        //printf("num= %d\n",num);
////        for(int i=0;i<num;i++)
////        {
////            int flag =1;
////            for(int j=0;j<num;j++)
////            {
////                if(j!=i)
////                {
////                    if(!little(s[min_num[i]],s[min_num[j]]))
////                    {
////                        flag=0;
////                    }
////                }
////            }
////            if(flag)
////            {
////                printf("%s\n%d\n",s[min_num[i]],ans[min_num[i]]);
////            }
////        }
////    }
//
//// 循环小数 UVa202
//
////#ifdef local
////    freopen("in.txt","r",stdin);
////    //freopen("out.txt","w",stdout);
////#endif
////        int a,b,k=1;
////        while(scanf("%d %d",&a,&b)==2)
////        {
////            vector<int> s;
////            vector<int> s1;
////            int a1=a;
////            if(k)   k=0;else printf("\n");
////            if(a%b==0)  printf("%d/%d = %d.(0)\n%4d = number of digits in repeating cycle\n",a,b,a/b,1);
////            else
////            {
////                s1.push_back(a/b);
////                a=a%b;
////                s.push_back(a);
////                vector<int>::iterator iter;
////                //求无限循环小数
////                while(1)
////                {
////                    int l= a*10/b;
////                    a=(a*10)%b;
////                    s1.push_back(l);
////                    iter=std::find(s.begin(),s.end(),a);
////                    if(iter !=s.end())  break;
////                    s.push_back(a);
////                }
////                int pos = distance(s.begin(),iter); //记录重复的起始位置
////                int k = distance(iter,s.end());     //记录循环位数
////                printf("%d/%d = %d.",a1,b,s1[0]);
////                for(int i=1;i<pos+1;i++)
////                    printf("%d",s1[i]);
////                printf("(");
////                for(int i=pos+1;i<s1.size();i++)
////                {
////                    if(i<=50)   printf("%d",s1[i]);
////                }
////                if(k>50)    printf("...)\n%4d = number of digits in repeating cycle\n",k);
////                else    printf(")\n%4d = number of digits in repeating cycle\n",k);
////                //printf("k= %d, s1[%d]= %d\n",k,k,s1[k]);
////            }
////        }
//
//// 子序列 UVa10340
//
////#ifdef local
////    freopen("in.txt","r",stdin);
////    //freopen("out.txt","w",stdout);
////#endif
////    char s[maxn],t[maxn];
////    while(scanf("%s %s",s,t)==2)
////    {
////        if(strlen(s)>strlen(t))
////            printf("No\n");
////        else
////        {
////            int m=0,flag=0;
////            for(int i=0;i<strlen(s);i++)
////            {
////                flag=0;
////                for(int j=m;j<strlen(t);j++)
////                {
////                    if(s[i]==t[j])
////                    { m=j+1;flag=1;break;}
////                }
////                if(!flag)
////                { printf("No\n");flag=0;break;}
////            }
////            if(flag)    printf("Yes\n");
////        }
////    }
//
//// 盒子 UVa1587
//
//
////#ifdef local
////    freopen("in.txt","r",stdin);
////    //freopen("out.txt","w",stdout);
////#endif
////    while(cin >> a[0].x >> a[0].y >> a[1].x >> a[1].y >> a[2].x >> a[2].y >> a[3].x >> a[3].y >> a[4].x >> a[4].y >> a[5].x >> a[5].y)
////    {
////        for(int i = 0; i < 6; ++i)
////            if(a[i].x < a[i].y)
////                swap(a[i].x, a[i].y);
////        sort(a, a+6, [](const face a, const face b) {return a.x==b.x ? (a.y > b.y) : (a.x > b.x);});
////        printf("%s\n", check() ? "POSSIBLE" : "IMPOSSIBLE");
////    }
//
//// 换抵挡装置 UVa1588
//
////#ifdef local
////    freopen("in.txt","r",stdin);
////    //freopen("out.txt","w",stdout);
////#endif
////    char bt[350];
////    char tp[120];
////    while(scanf("%s%s",bt,tp)==2)
////    {
////        int ans_min=INF;
////        int m=strlen(tp);
////        int n=strlen(bt);
////        char bt1[350];
////        memset(bt1,0, sizeof(bt1));
////        int ans[2*m+n];
////        for(int i=0;i<2*m+n;i++)
////            ans[i]=INF+1;
////        for(int i=0;i<m;i++)
////        {
////            if(tp[i]=='1')
////            { tp[i]='2';}
////            else if(tp[i]=='2')
////            {tp[i]='1';}
////        }
////        for(int i=0;i<2*m+n;++i)
////        {
////            if(i>=m && i<m+n)   bt1[i]=bt[i-m];
////            else    bt1[i]='1';
////        }
////        //printf("%s\n",bt1);
////        for(int i=0;i<=m+n;i++)
////        {
////            int flag=1;
////            for(int j=0;j<m;j++)
////            {
////               if(tp[j]<bt1[i+j])
////                {
////                    flag=0;break;
////                }
////            }
////            if(flag)
////            {
////                ans[i]=max(m+i,m+n)-min(i,m);
////            }
////           //printf("%d\n",ans[i]);
////        }
////        for(int i=0;i<2*m+n;i++)
////            if(ans[i]<ans_min)  ans_min=ans[i];
////        printf("%d\n",ans_min);
////    }
//
//// 组合数 long long类型输出用%lld
//
////    int n = 29;
////    printf("%lld\n",C(25,12));
////    if(is_prime(n))
////        printf("%d is a prime!\n",n);
////    else   printf("%d is not a prime!\n",n);
//
//// 古老的密码 UVa1339
//
////#ifdef local
////    freopen("in.txt","r",stdin);
////    //freopen("out.txt","w",stdout);
////#endif
////    char m[101],n[101];
////    int cnt1[26],cnt2[26];
////    int len;
////    while(scanf("%s %s",m,n)==2)
////    {
////        len=strlen(m);
////        memset(cnt1,0,sizeof(cnt1));
////        memset(cnt2,0,sizeof(cnt2));
////        for(int i=0;i<len;i++)
////        {
////            cnt1[m[i]-'A']++;
////            cnt2[n[i]-'A']++;
////        }
////        sort(cnt1,cnt1+26);
////        sort(cnt2,cnt2+26);
////        int flag = 1;
////        for(int i=0;i<26;i++)
////            if(cnt1[i] != cnt2[i])
////            {
////                flag=0;
////                break;
////            }
////        if(flag)    printf("YES\n");
////        else    printf("NO\n");
////    }
//
//// 刽子手游戏 UVa489
////
////    int rnd;
////    while(scanf("%d",&rnd)==1 && rnd != -1)
////    {
////        scanf("%s%s",s,s1);
////        printf("Round %d\n",rnd);
////        win = lose = 0;
////        l=strlen(s);
////        chance = 7;
////        for(int i=0;i<strlen(s1);i++)
////        {
////            guess(s1[i]);
////            if(win||lose) break;
////        }
////        if(win) printf("You win.\n");
////        else if(lose)   printf("You lose.\n");
////        else    printf("You chickened out.\n");
////    }
//
//// 救济金发放 UVa133
//
////    while(scanf("%d%d%d",&n,&k,&m)==3 && n)
////    {
////        for(int i=1;i<=n;i++)   s[i]=i;
////        int left = n;
////        int p1=n,p2=1;
////        while(left)
////        {
////            p1 = go(p1,1,k);
////            p2=go(p2,-1,m);
////            if(p2 != p1)    { printf("%3d",p1);left--; }
////            printf("%3d",p2);left--;
////            s[p1]=s[p2]=0;
////            if(left)    printf(",");
////        }
////        printf("\n");
////    }
//
//// 信息解码 UVa213
//
////#ifdef local
////    freopen("in.txt","r",stdin);
////    //freopen("out.txt","w",stdout);
////#endif
////    while(readcodes())
////    {
////        for(;;)
////        {
////            int len = readint(3);
////            if(len == 0) break;
////            for(;;)
////            {
////                int v = readint(len);
////                if(v == (1<<len)-1) break;
////                putchar(code[len][v]);
////            }
////        }
////        putchar('\n');
////    }
//
//
//    //printf("%d\n",myAtoi("     00020 sf"));
//
//// 正则表达式
//
////    long long num;
////    std::string pattern{ "[^\\s]*[+-]?\\d+" }; // url
////    std::regex re(pattern);
////
////    std::string str{ "   .1" };
////    std::smatch results;
////    std::regex_search(str, results, re);
//     //匹配到的第一个结果
////    string s=results[0];
////    cout << s <<endl;
////    int n=s.size();
////    int m;
////    for(int i=0;i<n;i++)
////    {
////        if(s[i] !='0')
////        {m=i;break;}
////    }
////    cout<<m<<endl;
////    if(n != 0)
////    {
////        if(n-m>16)
////            cout<<0<<endl;
////        else    num = stoll(s);
////        if(num>INT32_MAX)
////            cout<< INT32_MAX <<endl;
////        else if(num<INT32_MIN)
////            cout<< INT32_MIN <<endl;
////        else
////            cout<< num << endl;
////    }
////    else    cout<<0<<endl;
//    //while (std::regex_search(str, results, re)) {
////        for (auto x : results)
////            {std::cout << x << " ";}
//        //std::cout << std::endl;
//        //str = results.suffix().str();
//    //}
//
//// 滑窗法，双指针o(N),space o(1)
//
////
//
//// 数字转为罗马数字
//
////    int num;
////    while(scanf("%d",&num)==1)
////    {
////        const string roman[] = { "I", "V", "X", "L", "C", "D", "M" };
////        string result;
////        for( int i = 0; num > 0; i++ ) {
////            int last = num % 10;
////            if ( last < 4 )
////                for ( int j = 0; j < last; j++ ) result.insert( 0, roman[ i * 2 ] );
////            else if ( last == 4 )
////                result.insert( 0, roman[ i * 2 ] + roman[ i * 2 + 1 ] );
////            else if ( last > 4 && last < 9 ) {
////                for ( int j = 0; j < last - 5; j++ ) result.insert( 0, roman[ i * 2 ] );
////                result.insert( 0, roman[ i * 2 + 1 ] );
////            } else if ( last == 9 )
////                result.insert( 0, roman[ i * 2 ] + roman[ i * 2 + 2 ] );
////            num /= 10;
////        }
////        cout<<result<<endl;
////    }
//
//// 最长前缀子串
//
////sum is 0, three nums(a,b,c)
//
////    vector<int> nums={-1,-1,2,3,-4,-5,3,4,6,7,8,-2,4,-6,2,3,23,4,-9,2,3,10,13,-12};
////    int n = nums.size();
////    sort(nums.begin(),nums.end());
////    int i=0,j=n-1,a,b,c,m=0,flag1=1,ff=1,nn=0;
////    vector<vector<int>> ans;
////    set<int> s;
////    while(i<j){
////        a=nums[i];
////        c=nums[j];
////        int pred=s.size();
////        int af=0,flag=0;
////        vector<int> zeros;
////        for(int k=i+1;k<j;k++)
////        {
////            b=nums[k];
////            if(a+b+c==0)
////            {
////                s.insert(a);s.insert(b);s.insert(c);
////                af=s.size();
////                flag=1;
////                break;
////            }
////        }
////        if(m==0 && flag)
////            { zeros.push_back(a);zeros.push_back(b);zeros.push_back(c);ans.push_back(zeros); }
////        if(m>0 && flag && af>pred)
////            { zeros.push_back(a);zeros.push_back(b);zeros.push_back(c);ans.push_back(zeros); }
////        if(flag1 && nn<2)
////        {
////            if(abs(a)<abs(c))
////            {
////                j--;
////            }
////            else if(abs(a)==abs(c))
////            {
////                flag1=0;
////                if(ff==1)   {j--;ff=2;}
////                nn++;
////            }
////            else
////            {
////                i++;
////            }
////        }
////        else if(!flag1)
////        {
////            if(ff==2)   {j++;i++;}
////            if(ff==1)   {i--;j--;}
////            flag1=1;
////            nn++;
////        }
////        if(nn==2)   nn=0;
////        m++;
////    }
////    for(vector<vector<int>>::iterator i=ans.begin();i<ans.end();i++)
////    {
////        for(int j=0;j<(*i).size();j++)
////            cout<<(*i)[j]<<" ";
////        cout<<endl;
////    }
//
////
////    int n,m;
////    string s,name;
////    cin>>n;
////    cin>>s;
////    cin>>m;
////    while(m--)
////    {
////        string s1=s;
////        int ans=-1;
////        cin>>name;
////        int na = name.size();
////        for(int i=0;i<na;i++)
////            for(int j=0;j<n;j++)
////            {
////                if(name[i]==s1[j])
////                {
////                    if(j>ans)
////                        ans=j;
////                    s1[j]=' ';
////                    break;
////                }
////            }
////        cout<<ans+1<<endl;
////    }
//
////    int n,m;
////    string s,t;
////    vector<int> pos[26];//向量数组
////    cin>>n>>s;
////    for(int i=0;i<n;i++)
////        pos[s[i]-'a'].push_back(i+1);
////    cin>>m;
////    for(int i=0;i<m;i++)
////    {
////        cin>>t;
////        vector<int> cnt(26);
////        for(auto &c : t)
////            ++cnt[c-'a'];
////        int ans =-1;
////        for(int j=0;j<26;j++)
////            if(cnt[j]>0)
////                ans = max(ans,pos[j][cnt[j]-1]);
////        cout<<ans<<endl;
////    }
//
//
////    int n,m,t,l,r;
////    vector<int> a;
////    cin>>n>>m;
////    while(m--)
////    {
////        cin>>t>>l>>r;
////        if(t)
////        {
////            for(int i=l;i<r;i++)
////                a[i]=a[i-1]+1;
////        }
////        else
////        {
////            for(int i=l;i<r;i++)
////                a[i-1]=a[i]+1;
////        }
////    }
//
//
////    printf("\007");
//
//
//// string和sstream的使用
////    string line;
////    while(getline(cin, line)){
////        int sum = 0, x;
////        stringstream ss(line);
////        while(ss>>x)    sum += x;
////        cout<<sum<<endl;
////    }
//
//
//// 结构体的例子
////    Point a, b(1,2);
////    a.x = 3;
////    cout<<a+b<<endl;
//
//// UVa 10474
//
////#ifdef local
////    freopen("in.txt","r",stdin);
////    //freopen("out.txt","w",stdout);
////#endif
////    int n, q, x, a[10000],kase=0;
////    while(scanf("%d%d",&n, &q)==2 && n){
////        printf("CASE# %d:\n", ++kase);
////        for(int i = 0;i<n;i++)  scanf("%d", &a[i]);
////        sort(a, a+n);
////        while(q--){
////            scanf("%d", &x);
////            int p = lower_bound(a,a+n,x)-a;
////            if(a[p] == x)   printf("%d found at %d\n",x,p+1);
////            else    printf("%d not found\n",x);
////        }
////    }
//
//// UVa10815
//
////#ifdef local
////    freopen("in.txt","r",stdin);
////    //freopen("out.txt","w",stdout);
////#endif
////    set<string> dict;
////    string s, buf;
////    while(cin>>s){
////        for(int i=0;i<s.length();i++)
////            if(isalpha(s[i]))   s[i]=tolower(s[i]); else    s[i]= ' ';
////        stringstream ss(s);
////        while(ss >> buf)    dict.insert(buf); // 解释下这里为何不直接插入s,因为s中存在处理过的空格
////    }
////    for(set<string>::iterator it = dict.begin();it != dict.end();++it)
////        cout<<*it<<endl;
//
//// UVa 11565
//
////    int N,A,B,C;
////    cin>>N;
////    while(N--){
////        int flag=1;
////        cin>>A>>B>>C;
////        for(int x=-100;x<=100;x++)
////            for(int y=-100;y<=100;y++)
////                for(int z=-100;z<=100;z++)
////                    if(y !=x && z!=x && z!=y && x+y+z==A && x*y*z==B && x*x+y*y+z*z==C){
////                        if(flag)    printf("%d %d %d\n",x,y,z);
////                        flag = 0;
////                    }
////        if(flag)    printf("No solution.\n");
////    }
//
//
//    return 0;
// }
////镜像回文的判断
//char r(char ch)
//{
//    if(isalpha(ch)) return rev[ch-'A'];
//    return rev[ch-'0'+25];
//}
////字典序列大小判断
//int small(const char* s, int p, int q)
//{
//    int n = strlen(s);
//    for(int i = 0;i < n;i++)
//        if(s[(p+i)%n] != s[(q+i)%n])
//            return s[(p+i)%n] < s[(q+i)%n];
//    return 0; // 相等
//}
////海明距离的计算
//int hamming(char *s1,char *s2)
//{
//    int m=0;
//    for(int i=0;i<strlen(s1);i++)
//    {
//        if(s1[i]!=s2[i])    m++;
//    }
//    return m;
//}
//// 字典序s1比s2小
//int little(char *s1,char *s2)
//{
//    for(int i=0;i<strlen(s1);i++)
//    {
//        if(s1[i] != s2[i])
//            return s1[i]<s2[i];
//    }
//    return 0;
//}
//bool check()
//{
//    if(memcmp(a, a+1, sizeof(face)) || memcmp(a+2, a+3, sizeof(face)) || memcmp(a+4, a+5, sizeof(face))) return false;
//    if(a[0].x!=a[2].x || a[0].y!= a[4].x || a[2].y!=a[4].y) return false;
//    return true;
//}
//// 组合数
//long long C(int n, int m)
//{
//    if(m < n-m) m = n-m;
//    long long ans = 1;
//    for(int i = m+1; i <= n; i++)   ans *= i;
//    for(int i = 1; i <= n-m; i++)   ans /=i;
//    return ans;
//}
//// 判断是否为素数
//int is_prime(int n)
//{
//    if(n<=1)    return 0;
//    int m = floor(sqrt(n)+0.5);
//    for(int i=2;i<=m;i++)
//        if(n % i ==0) return 0;
//    return 1;
//}
////void guess(char ch)
////{
////    int bad = 1;
////    for(int i = 0; i < strlen(s); i++)
////        if(s[i]==ch)    { l--; s[i] = ' '; bad = 0;}
////    if(bad) --chance;
////    if(!chance) lose = 1;
////    if(!l)   win =1;
////}
//
////逆时针走t步，步长d（-1表示顺时针走），返回新位置。
////int go(int p,int d, int t)
////{
////    while(t--)
////    {
////        do  { p = (p+d+n-1)%n+1;}   while(s[p] == 0);
////    }
////    return p;
////}
//
////处理跨行读字符
//int readchar()
//{
//    for(;;)
//    {
//        int ch = getchar();
//        if(ch != '\n' && ch != '\r')    return ch;
//    }
//}
//
////将二进制转换为十进制
//int readint(int c)
//{
//    int v = 0;
//    while(c--)  v=v*2+readchar()-'0';
//    return v;
//}
//
//int readcodes()
//{
//    memset(code, 0, sizeof(code));
//    code[1][0]=readchar();
//    for(int len = 2; len <= 7; len++)
//    {
//        for(int i =0; i< (1<<len)-1;i++)
//        {
//            int ch = getchar();
//            if(ch==EOF) return 0;
//            if(ch == '\n' || ch == '\r') return 1;
//            code[len][i]=ch;
//        }
//    }
//}
//
//
//// 字符串转换为数字，isdigit()可以用ASCALL码值的范围替代！
//
//int myAtoi(string str) {
//    int n=str.size();
//    if(n==0)    return 0;
//    char s[n];
//    long long ans=0,flag=0,m=0,f=0;
//    for(int i=0;i<n;i++)
//    {
//        if(str[i] != ' ' &&  (isdigit(str[i]) || str[i] == '-' || str[i] == '+'))
//        {
//            if(f>1) {return 0;}
//            if(str[i]=='+')
//            {
//                f++;
//                if(!isdigit(str[i+1]))  return 0;
//            }
//            if(str[i]=='-')
//            {
//                if(isdigit(str[i+1]))    flag=1;
//                else    return 0;
//                f++;
//            }
//            else if(isdigit(str[i]))
//            {
//                for(int j=i;j<n;j++)
//                {
//                    if(isdigit(str[j]))
//                    {
//                        s[j-i]=str[j];
//                        m++;
//
//                    }
//                    else    break;
//                }
//                break;
//            }
//        }
//        else if(str[i] != ' ' || i==n-1)
//        { return 0; }
//    }
//
//    for(int i=0;i<m;i++)
//    {
//        ans += s[i]-'0';
//        if(i<m-1)   ans *=10;
//        if(ans>INT32_MAX)
//        {
//            if(flag)    return INT32_MIN;
//            else    return INT32_MAX;
//        }
//    }
//    if(flag)
//        return -ans;
//    else
//        return ans;
//}
