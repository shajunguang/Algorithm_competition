//
// Created by liu on 19-10-19.
//

//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//vector<long long> vec;
//
//int main() {
//    long long a, b, c;
//    cin >> a >> b >> c;
//    long long n, m;
//
//    for(long long i = c; i >= b; --i) {
//        n = a / i;
//        m = a % i;
//        if(m == 0) {
//            for(long long j = 0; j < n; ++j) {
//                vec.push_back(i);
//            }
//            break;
//        }
//        else if(m < b) {
//            for(long long j = 0; j < n-1; ++j) {
//                vec.push_back(i);
//            }
//            a -= (n - 1) * i;
//        }
//        else if(m >= b && m < c) {
//            for(long long j = 0; j < n; ++j) {
//                vec.push_back(i);
//            }
//            vec.push_back(m);
//            break;
//        }
//    }
//    if(vec.empty()) cout << "NO";
//    else {
//        cout << "YES" << endl;
//        for(long long i = vec.size() - 1; i >=0; --i) {
//            cout << vec[i] << " ";
//        }
//    }
//    return 0;
//}