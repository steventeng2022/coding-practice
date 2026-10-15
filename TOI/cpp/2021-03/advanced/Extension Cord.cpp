// 1-延長線 | 2021/03/22~2021/03/30 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202103/Extension Cord.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202103/Extension Cord.zip
#include <bits/stdc++.h>
#include<cstdio>
#include<cstring>
#include<vector>
const int N = 1000 + 5, NODE = 10 + 5;

using namespace std;

struct Edge{
    int id, to;
    Edge() {}
    Edge(int id, int to) : id(id), to(to) {}
};

int n, c, t, idx;
int ans[N], deg[NODE];
vector<Edge> g[NODE];
bool used[N];

void dfs(int u)
{
    for(int i=0; i<(int)g[u].size(); ++i)
    {
        if(used[g[u][i].id]) continue;
        used[g[u][i].id] = true;
        dfs(g[u][i].to);
        ans[--idx] = g[u][i].id;
    }
}

void add_edge(int from, int to, int id)
{
    g[from].push_back(Edge(id, to));
}

void solve()
{
    bool flag = true;
    idx = n;

    if(g[t].empty() || deg[t]) flag = false;

    for(int i=1; i<NODE; ++i)
    {
        if(deg[i])
        {
            flag = false;
            break;
        }
    }

    if(flag) dfs(t);

    if(flag==false || idx != 0) printf("0\n");
    else
    {
        printf("1\n");
        if(c==2)
        {
            printf("%d", ans[0]);
            for(int i=1; i<n; ++i) printf(" %d", ans[i]);
            printf("\n");
        }
    }
}

int main()
{
    scanf("%d%d", &n, &c);
    scanf("%d", &t);
    memset(deg, 0, sizeof(deg));
    for(int i=0; i<n; ++i)
    {
        int from, to;
        scanf("%d%d", &from, &to);
        add_edge(from, to, i+1);
        ++deg[from];
        --deg[to];
    }
    solve();

    return 0;
}
