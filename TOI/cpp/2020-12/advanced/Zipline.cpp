// 2-空中鋼索 | 2020/12/28~2021/01/01 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202012/Zipline.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202012/Zipline.zip
#include <bits/stdc++.h>
#include<cstdio>
#include<algorithm>
#include<vector>
const int N = 10000 + 5;
using namespace std;

int n, m, h[N];
int cnt[N]={0}, dis[N], used[N]={0};
vector<int> g[N];

void dfs(int u)
{
    if(used[u]) return;
    dis[u] = 0;
    if(u == n)
    {
        cnt[u] = 1;
        used[u] = 1;
        return;
    }
    for(int v : g[u])
    {
        dfs(v);
        dis[u] = max(dis[u], dis[v]);
    }

    for(int v : g[u])
    {
        if(dis[u] == dis[v])
        {
            cnt[u] += cnt[v];
        }
    }
    dis[u] += 1;
    used[u] = 1;
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; ++i) scanf("%d", &h[i]);
    for(int i=0; i<m; ++i)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        if(h[a] > h[b]) g[a].push_back(b);
        else if(h[a] < h[b]) g[b].push_back(a);
    }
    dfs(1);
    printf("%d\n", cnt[1]);
    return 0;
}
