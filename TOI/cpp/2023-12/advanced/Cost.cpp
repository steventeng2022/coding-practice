// 1-材料成本 | 2023/12/25~2023/12/29 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202312/Cost.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202312/Cost.zip
#include <bits/stdc++.h>
#include<cstdio>
#include<cstring>
#include<vector>
#include<utility>
using namespace std;
const int N = 1000 + 5;

void dfs(int n, const int *p, const vector<pair<int, int>> *materials, int u, int *cost)
{
    if (cost[u] != -1)
    {
        return;
    }
    int res = p[u];
    for (const pair<int, int> &it : materials[u])
    {
        dfs(n, p, materials, it.first, cost);
        res += cost[it.first] * it.second;
    }
    cost[u] = res;
    return;
}

void solve(int n, const int *p, const int *m, const vector<pair<int, int>> *materials, int *cost)
{
    memset(cost, -1, sizeof(int) * n);
    for (int i = 0; i < n; ++i)
    {
        if (cost[i] == -1)
        {
            dfs(n, p, materials, i, cost);
        }
    }
    return;
}

int main()
{
    int n;
    int p[N];
    int m[N];
    vector<pair<int, int>> materials[N];

    int cost[N];

    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &p[i]);
    }

    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &m[i]);
        materials[i].resize(m[i]);
        for (int j = 0; j < m[i]; ++j)
        {
            int s, a;
            scanf("%d%d", &s, &a);
            materials[i][j] = make_pair(s - 1, a);
        }
    }

    solve(n, p, m, materials, cost);

    for (int i = 0; i < n; ++i)
    {
        printf("%d\n", cost[i]);
    }

    return 0;
}
