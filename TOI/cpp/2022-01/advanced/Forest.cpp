// 1-森林 | 2022/01/03~2022/01/07 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202112/Forest.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202112/Forest.zip
#include <bits/stdc++.h>

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
const int inf = 0x3f3f3f3f;
const int maxt = 1000, maxn = 200, maxm = 200;

int dp[maxt + 1][maxn][maxm], atk[maxt + 1][maxn][maxm];
char maze[maxn][maxm + 1];

int main()
{
    int ans = inf;
    int n, m, time, q;
    int di[] = {-1, 1, 0, 0, 0}, dj[] = {0, 0, -1, 1, 0};

    scanf("%d%d%d%d", &n, &m, &time, &q);
    for(int i = 0; i < n; ++i)
    {
        scanf("%s", maze[i]);
    }

    for(int i = 0; i < q; ++i)
    {
        int begin_time, end_time, attack;
        int posh, posw;
        scanf("%d%d%d%d%d", &posh, &posw, &begin_time, &end_time, &attack);
        for(int j = begin_time; j <= end_time; ++j)
        {
            atk[j][posh][posw] = attack;
        }
    }

    memset(dp, 0x3f, sizeof(dp));
    dp[0][0][0] = 0;

    for(int t = 1; t <= time; ++t)
    {
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                int res = inf;

                if(maze[i][j] == '#') continue;

                for(int k = 0; k < 5; ++k)
                {
                    int ni = i + di[k], nj = j + dj[k];
                    if(0 <= ni && ni < n && 0 <= nj && nj < m && dp[t - 1][ni][nj] != inf)
                    {
                        res = min(res, dp[t - 1][ni][nj] + atk[t][i][j]);
                    }
                }

                dp[t][i][j] = res;
            }
        }
        ans = min(ans, dp[t][n - 1][m - 1]);
    }

    if(ans < inf) printf("%d\n", ans);
    else printf("-1\n");
    return 0;
}
