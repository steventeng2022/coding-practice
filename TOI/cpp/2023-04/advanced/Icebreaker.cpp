// 1-破冰活動 | 2023/04/24~2023/04/28 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202304/Icebreaker.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202304/Icebreaker.zip
#include <bits/stdc++.h>
//icebreaker.cpp
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int maxn = 10000 + 5;

int n, m;
vector<int> g[maxn];
int label[maxn];

bool dfs(const vector<int> g[maxn], int label[maxn], int u, int tag, int &cnt0, int &cnt1)
{
    label[u] = tag;
    if (tag == -1)
    {
        ++cnt0;
    }
    else
    {
        ++cnt1;
    }

    for (const int &v : g[u])
    {
        if (label[v] == tag)
        {
            return false;
        }
        else if (label[v] == 0 && dfs(g, label, v, -tag, cnt0, cnt1) == false)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int ret = 0;
    scanf("%d%d", &n, &m);
    memset(label, 0, sizeof(label));
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    for (int i = 1; i <= n; ++i)
    {
        int cnt0 = 0, cnt1 = 0;
        if (label[i] == 0)
        {
            if(dfs(g, label, i, 1, cnt0, cnt1) == false)
            {
                ret = 0;
                break;
            }
            ret += max(cnt0, cnt1);
        }
    }
    printf("%d\n", ret);
    return 0;
}
