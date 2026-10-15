// 2-士兵排列 | 2022/03/28~2022/04/01 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202203/Soldiers.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202203/Soldiers.zip
#include <bits/stdc++.h>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    int n;
    vector<vector<int>> a, dp, last;
    scanf("%d", &n);

    a.resize(n, vector<int>(n));
    dp.resize(1 << n, vector<int>(n, 0x3f3f3f3f));
    last.resize(1 << n, vector<int>(n, -1));

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            scanf("%d", &a[i][j]);
        }
        dp[1 << i][i] = 0;
    }

    for(int mask = 1; mask < (1 << n); ++mask)
    {
        for(int i = 0; i < n; ++i)
        {
            if( (mask >> i) & 1 ) continue;
            for(int j = 0; j < n; ++j)
            {
                if( (~mask >> j) & 1 ) continue;
                if(dp[mask | (1 << i)][i] > dp[mask][j] + a[j][i])
                {
                    dp[mask | (1 << i)][i] = dp[mask][j] + a[j][i];
                    last[mask | (1 << i)][i] = j;
                }
                else if(dp[mask | (1 << i)][i] == dp[mask][j] + a[j][i] && last[mask | (1 << i)][i] > j)
                {
                    dp[mask | (1 << i)][i] = dp[mask][j] + a[j][i];
                    last[mask | (1 << i)][i] = j;
                }
            }
        }
    }

    int mask = (1 << n) - 1;
    int cur_pos = (int)(min_element(dp[mask].begin(), dp[mask].end()) - dp[mask].begin()), new_pos;

    printf("%d\n", dp[mask][cur_pos]);

    for(int cnt = 0; mask; new_pos = last[mask][cur_pos], mask ^= (1 << cur_pos), cur_pos = new_pos, ++cnt)
    {
        printf("%d%c", cur_pos + 1, (cnt == n - 1) ? '\n': ' ');
    }

    return 0;
}
