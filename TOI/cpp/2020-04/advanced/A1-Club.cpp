// 1-社團 | 2020/04/27~2020/05/04 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202004/A1-Club.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202004/A1-Club.zip
#include <bits/stdc++.h>
#include<stdio.h>
#include<string.h>
#include<vector>

using namespace std;
const int N = 1000 + 5;

vector<int> g[N];
int n, m, a, b, status[N], ans[N], idx;

bool dfs(int u)
{
    status[u]=-1;
    for(int v : g[u])
    {
        if(status[v]==-1 || (!status[v] && !dfs(v))) return false;
    }
    ans[--idx]=u;
    status[u]=2;
    return true;
}

int main()
{
    memset(status, 0, sizeof(status));
    scanf("%d%d", &n, &m);
    idx=n;
    while(m--)
    {
        scanf("%d%d", &a, &b);
        g[a].emplace_back(b);
    }
    for(int i=1; i<=n; i++)
    {
        if(!status[i])
        {
            if(!dfs(i))
            {
                puts("NO");
                return 0;
            }
        }
    }
    puts("YES");
    for(int i=0; i<n; i++) printf("%d\n", ans[i]);
    return 0;
}
