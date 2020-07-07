//
// Created by liu on 19-9-28.
//

//#include <bits/stdc++.h>
//using namespace std;
//string str;
//set<char> dict;
//
//class Solution{
//public:
//    int cnt[1050][26];
//    int countLetters(string S){
//        int n = S.length();
//
//        for(int i=0;i<26;i++)   cnt[0][i]=0;
//        for(int i=1;i<=n;i++){   //计算每个字母的前缀和(0-i区间）
//            for(int c=0;c<26;c++)   cnt[i][c]=cnt[i-1][c];
//            ++cnt[i][S[i-1]-'a'];  //利用这种方式统计每个字母的前缀和值得借鉴！
//        }
//
//        int ans=0;
//        for(int l=1;l<=n;l++){
//            for(int r=l;r<=n;r++){  //遍历每个子串的左右位置
//                int app=0;
//                for(int c=0;c<26;c++)
//                    if(cnt[r][c]-cnt[l-1][c]>0) ++app;  //相减表示区间内字母出现的次数
//                if(app==1)  ++ans;  //只求字母出现一次的子串数量（这里注意子串时连续的）
//            }
//        }
//        return ans;
//    }
//};
//
//int main()
//{
//    cin>>str;
//    int ans=0;
//    for(auto i:str)
//        dict.insert(i);
//    for(auto i=dict.begin();i!=dict.end();i++){
//        for(int j=0;j<str.length();j++){
//            int flag=1;
//            if(str[j]==*i){
//                for(int k=j+1;k<str.length();k++)
//                    if(str[k]!=str[j]){
//                        ans += (k-j)*(k-j+1)/2;
//                        j=k;
//                        flag=0;
//                        break;
//                    }
//                if(flag)    { ans +=(str.length()-j)*(str.length()-j+1)/2;break; }
//            }
//        }
//    }
//    cout<<ans<<endl;
//    Solution s;
//    cout<<s.countLetters(str);
//    return 0;
//}