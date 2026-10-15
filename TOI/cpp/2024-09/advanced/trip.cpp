// 2-校外教學分組 | 2024/09/30~2024/10/04 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202410/trip.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202410/trip.zip
#include <bits/stdc++.h>
#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 16 + 1;
const int maxm = maxn * (maxn - 1) / 2;
const int inf = 2147483647;

void dfs(int cur, int n, int m, int *group, const int f[maxm][2], int& ans)
{
    if (cur == n)
    {
        bool flag = true;
        for (int i = 0; i < m; ++i)
        {
            if (group[f[i][0]] == group[f[i][1]])
            {
                flag = false;
                break;
            }
        }
        if (flag == true)
        {
            int cnt[3] = {0};
            for (int i = 0; i < n; ++i)
            {
                ++cnt[group[i]];
            }
            ans = min(ans, max({cnt[0], cnt[1], cnt[2]}) - min({cnt[0], cnt[1], cnt[2]}));
        }
        return;
    }
    for (int i = 0; i < 3; ++i)
    {
        group[cur] = i;
        dfs(cur + 1, n, m, group, f, ans);
    }
    return;
}

int solve(int n, int m, int f[maxm][2])
{
    int group[maxn];
    int ans = inf;
    dfs(0, n, m, group, f, ans);
    if (ans == inf)
    {
        return -1;
    }
    return ans;
}

int main()
{
    int n, m;
    int f[maxm][2];
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        scanf("%d%d", &f[i][0], &f[i][1]);
        --f[i][0];
        --f[i][1];
    }
    printf("%d\n", solve(n, m, f));
    return 0;
}
