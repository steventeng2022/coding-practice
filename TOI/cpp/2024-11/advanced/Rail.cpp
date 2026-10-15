// 2-鐵路 | 2024/11/11~2024/11/15 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202411/Rail.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202411/Rail.zip
#include <bits/stdc++.h>
#include<cstdio>
#include<vector>
using namespace std;

void dfs(const vector<vector<int>>& g, vector<int>& label, int u, int tag)
{
    label[u] = tag;
    for (const int& v : g[u])
    {
        if (label[v] == -1)
        {
            dfs(g, label, v, tag);
        }
    }
    return;
}

void solve(int n, int m, const vector<vector<int>>& g, const vector<vector<int>>& edges)
{
    vector<int> label(n, -1);
    vector<int> nodeCnt, edgeCnt;
    int tag = 0;
    int gcnt = 0, tcnt = 0;
    for (int u = 0; u < n; ++u)
    {
        if (label[u] == -1)
        {
            dfs(g, label, u, tag);
            ++tag;
        }
    }
    nodeCnt.resize(tag, 0);
    edgeCnt.resize(tag, 0);
    for (int u = 0; u < n; ++u)
    {
        ++nodeCnt[label[u]];
    }
    for (int i = 0; i < m; ++i)
    {
        ++edgeCnt[label[edges[i][0]]];
    }
    for (int i = 0; i < tag; ++i)
    {
        if (nodeCnt[i] - 1 == edgeCnt[i])
        {
            ++tcnt;
        }
        else
        {
            ++gcnt;
        }
    }
    printf("%d %d\n", gcnt, tcnt);
    return;
}

int main()
{
    int n, m;
    vector<vector<int>> g, edges;
    scanf("%d%d", &n, &m);
    g.resize(n);
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
        edges.push_back(vector<int>{a, b});
    }
    solve(n, m, g, edges);
    return 0;
}
