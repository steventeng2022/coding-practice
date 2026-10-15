// 1-環狀路徑 | 2022/11/28~2022/12/02 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202211/Cycle.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202211/Cycle.zip
#include <bits/stdc++.h>
#include<cstdio>
#include<vector>
using namespace std;

bool dfs(const vector<vector<int>> &g, vector<int> &vis, vector<bool> &hasCycle, int u)
{
    bool ret = false;
    vis[u] = -1;
    for(const int &v : g[u])
    {
        if(vis[v] == 0 && dfs(g, vis, hasCycle, v) )
        {
            ret = true;
        }
        else if(vis[v] == -1)
        {
            ret = true;
        }
        else if(vis[v] == 1 && hasCycle[v])
        {
            ret = true;
        }
    }
    vis[u] = 1;
    hasCycle[u] = ret;
    return ret;
}

int main()
{
    int n, m;
    vector<vector<int>> g;
    vector<int> vis;
    vector<bool> hasCycle;
    scanf("%d%d", &n, &m);
    g.resize(n);
    vis.resize(n, 0);
    hasCycle.resize(n, false);
    for(int i = 0; i < m; ++i)
    {
        int from, to;
        scanf("%d%d", &from, &to);
        g[from].emplace_back(to);
    }
    for(int i = 0; i < n; ++i)
    {
        if(vis[i] == 0)
        {
            dfs(g, vis, hasCycle, i);
        }
    }

    bool first = true;
    for(int i = 0; i < n; ++i)
    {
        if(hasCycle[i])
        {
            if(first == false) printf(" ");
            else first = false;
            printf("%d", i);
        }
    }
    if(first == true) printf("-1");
    printf("\n");
    return 0;
}
