// 3-供給調度 | 2025/04/28~2025/05/02 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202504/Supply.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202504/Supply.zip
#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<map>
using namespace std;

struct UnionFind
{
    vector<int> root;
    UnionFind(int n):root(n)
    {
        for(int i=0; i<n; ++i) root[i] = i;
    }
    int Find(int x)
    {
        if(root[x]!=x) root[x] = Find(root[x]);
        return root[x];
    }
    bool Union(int x, int y)
    {
        int a = Find(x), b = Find(y);
        if(a==b) return false;
        root[a] = b;
        return true;
    }
};
bool Check(int N, const vector<vector<int>> &edges, const map<pair<int,int>, int> &upgrades, int target)
{
    vector<vector<int>> real_edges(edges);
    for(auto &v : real_edges)
    {
        const auto &it = upgrades.find({v[1], v[2]});
        if(it!=upgrades.end()) v[0] += it->second;
    }
    sort(real_edges.begin(), real_edges.end());

    UnionFind uf(N);
    int total_cost = 0;
    for(auto &v : real_edges)
    {
        if(uf.Union(v[1], v[2])) total_cost += v[0];
    }
    return total_cost > target;
}
int main()
{
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<vector<int>> edges(M, vector<int>(3));
    for(int i=0; i<M; ++i)
    {
        cin >> edges[i][1] >> edges[i][2] >> edges[i][0];
    }
    vector<vector<int>> queries(Q, vector<int>(3));
    for(auto &v:queries)
    {
        for(int &i:v)cin >> i;
    }
    int K;
    cin >> K;

    int lb = 0, ub = Q+1;
    while(lb < ub)
    {
        int mid = lb + (ub - lb)/2;
        map<pair<int,int>, int> upgrades;
        for(int i=0; i<mid; ++i)
        {
            upgrades[make_pair(queries[i][0], queries[i][1])] += queries[i][2];
        }
        if ( Check(N, edges, upgrades, K) )
            ub = mid;
        else
            lb = mid + 1;
    }
    if(lb>Q) lb = -1;
    cout << lb << endl;
}
