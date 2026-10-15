// 3-防守城堡 | 2022/04/25~2022/04/29 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202204/Defense.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202204/Defense.zip
#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool bfs(int M, int N, vector<vector<int> > &graph, vector<int> &match)
{
    bool visited[1005] = {};
    int path[1005] = {};
    queue<int> vertex;

    for(int i=1; i<=M; i+=1)
    {
        if(!match[i])
        {
            vertex.push(i);
            visited[i] = true;
        }
    }

    while(!vertex.empty())
    {
        int node = vertex.front();
        for(int i=0; i<graph[node].size(); i+=1)
        {
            int neighbor = graph[node][i];
            if(!visited[neighbor])
            {
                visited[neighbor] = true;
                path[neighbor] = node;
                if(!match[neighbor])
                {
                    match[neighbor] = node;
                    match[node] = neighbor;
                    int route_node = node;
                    while(path[route_node])
                    {
                        int prev = path[route_node];
                        int last = path[prev];
                        match[prev] = last;
                        match[last] = prev;
                        route_node = last;
                    }
                    return true;
                }
                else if(visited[match[neighbor]]==false)
                {
                    vertex.push(match[neighbor]);
                    visited[match[neighbor]] = true;
                    path[match[neighbor]] = neighbor;
                }
            }
        }
        vertex.pop();
    }
    return false;
}

int main()
{
    int M,N,T;
    cin >> M >> N >> T;

    vector <vector<int> > graph(M+2);
    for(int i=0; i<T; i+=1)
    {
        int a,b;
        cin >> a >> b;
        graph[a+1].push_back(M+b+1);
    }

    int matching = 0;
    vector<int> match(M+N+1);
    while(bfs(M,N,graph,match))
    {
        matching += 1;
    }

    cout << M + N - matching << endl;
    return 0;
}
