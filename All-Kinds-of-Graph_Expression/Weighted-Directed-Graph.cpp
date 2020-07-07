//
// Created by liu on 19-10-18.
//

//#include <iostream>
//#include <vector>
//#include <tuple>
//#include <map>
//using namespace std;
//
//map<int , vector<tuple<int, int, double>>> EWD; //带权有向图的板子
//
//int main()
//{
//    int V, E;
//    cin >> V >> E;
//    for(int i = 0 ; i < E ;i++)
//    {
//        int v, w;
//        double weight;
//        cin >> v >> w >> weight;
//        EWD[v].push_back(make_tuple(v, w, weight));
//    }

//    cout << "EdgeWeightedDigraph : " << endl;
//    for(int v = 1; v < V; v++)
//    {
//        cout << v << " : ";
//        for(auto & ii : EWD[v])
//            cout << get<0>(ii) << "->" << get<1>(ii) << " " << get<2>(ii) << "  ";
//        cout << endl;
//    }
//    return 0;
//}