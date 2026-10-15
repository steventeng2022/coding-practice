// 2-電力配送 | 2023/10/23~2023/10/27 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202310/Power.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202310/Power.zip
#include <bits/stdc++.h>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

int dfs1(vector<vector<pair<int,int>>> &graph, int ind, int par)
{
    int ans = 0;
    for(auto &p: graph[ind])
    {
        if(p.first==par)continue;
        ans += (p.second==-1);
        ans += dfs1(graph, p.first, ind);
    }
    return ans;
}
void dfs2(vector<vector<pair<int,int>>> &graph, int ind, int par, vector<int> &ans)
{
    for(auto &p: graph[ind])
    {
        if(p.first==par)continue;
        ans[p.first] = ans[ind] + p.second;
        dfs2(graph, p.first, ind, ans);
    }
}

int main()
{
    int N, K;
    scanf("%d %d", &N, &K);
    vector<vector<pair<int,int>>> graph(N);
    for(int i=0; i<N-1; ++i)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a-1].push_back(make_pair(b-1, 1));
        graph[b-1].push_back(make_pair(a-1, -1));
    }
    vector<int> ans(N);
    ans[0] = dfs1(graph, 0, -1);
    dfs2(graph, 0, -1, ans);
    for(int i=0; i<K; ++i)
    {
        int a;
        scanf("%d", &a);
        printf("%d ", ans[a-1]);
    }
    return 0;
}
