//
// Created by liu on 19-9-9.
//

//#include<iostream>
//#include<string>
//#include<algorithm>
//#define NUM 50
//#define INT 65536
//using namespace std;
//int k[NUM][NUM];
//int c[NUM][NUM];
//int s[NUM];
//int f[NUM];
//void DYNAMIC_ACTIVITY_SELECTOR(int n)  //n is s's length
//{
//    s[n + 1] = INT;
//    f[n + 1] = INT;
//    for (int i = 0; i <= n; i++){
//        c[i][i + 1] = 0;
//        k[i][i + 1] = -1;
//    }
//
//    for (int l = 1; l <= n; l++){
//        for (int i = 0; i <= n - l + 1; i++){
//            int j = i + l + 1;
//            c[i][j] = 0;
//            k[i][j] = -1;
//            if (f[i] < s[j]){   //is there room between i and j
//                for (int p = i + 1; p <= j - 1; p++){
//                    if (s[p] >= f[i] && f[p] <= s[j]){
//                        int Kval = c[i][p] + c[p][j] + 1;
//                        if (Kval>c[i][j]){
//                            c[i][j] = Kval;
//                            k[i][j] = p;
//                        }
//                    }
//                }
//            }
//        }
//    }
//}
//
//void PRINT_SELECTOR(int i, int j)
//{
//    if (k[i][j] == -1)
//        return;
//    cout << "a" << k[i][j]<<" ";
//    PRINT_SELECTOR(i, k[i][j]);
//    PRINT_SELECTOR(k[i][j], j);
//}
//int main()
//{
//    for (int i = 1; i <= 11; i++)
//        cin >> s[i];
//    for (int i = 1; i <= 11; i++)
//        cin >> f[i];
//    DYNAMIC_ACTIVITY_SELECTOR(11);
//    PRINT_SELECTOR(0, 12);
//    cout << endl;
//}