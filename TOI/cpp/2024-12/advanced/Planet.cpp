// 3-超能星球 | 2024/12/23~2024/12/27 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202412/Planet.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202412/Planet.zip
#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<climits>
using namespace std;

int main()
{
    int S, T;
    cin >> S >> T;
    --S;
    --T;
    vector<vector<pair<int,int>>> graph(12);
    constexpr int edges[30][2] =
    {0, 1, 0, 2, 0, 3, 0, 4, 0, 5, //1-5
     1, 2, 2, 3, 3, 4, 4, 5, 5, 1, //6-10
     1, 8, 1, 7, 2, 7, 2, 6, 3, 6, //11-15
     3, 10, 4, 10, 4, 9, 5, 9, 5, 8, //16-20
      6, 7, 7, 8, 8, 9, 9, 10, 10, 6, //21-25
      11, 6, 11, 7, 11, 8, 11, 9, 11, 10 //26-30
     };
    for(int i=0; i<30; ++i)
    {
        int cost;
        cin >> cost;
        graph[edges[i][0]].push_back({edges[i][1], cost});
        graph[edges[i][1]].push_back({edges[i][0], cost});
    }
    vector<int> dist(12, INT_MAX);
    vector<bool> visited(12, false);
    dist[S] = 0;
    while(!visited[T])
    {
        int min_dist = INT_MAX;
        int min_node = 0;
        for(int i=0; i<12; ++i)
        {
            if(!visited[i] && dist[i]<min_dist)
            {
                min_node = i;
                min_dist = dist[i];
            }
        }
        visited[min_node] = true;
        for(auto &p: graph[min_node])
        {
            dist[p.first] = min(dist[p.first], dist[min_node]+p.second);
        }
    }
    cout << dist[T] << endl;
}
