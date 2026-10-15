// 金塊投資 | 2023/12 新手同好會 | 新手同好會
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202312-OFFLINE/Gold.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202312-OFFLINE/Gold.zip
#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
    int X, N, M;
    cin >> X >> N >> M;
    int DP[21][21][X + 1], num[X + 1], ans = 0;
    memset(DP, 0, sizeof(DP));
    for (int i = 1; i <= X; ++i)
    {
        cin >> num[i];
    }

    for (int i = 0; i <= M; ++i)
    {
        for (int j = 0; j <= N; ++j)
        {
            for (int k = 1; k <= X; ++k)
            {
                DP[i][j][k] = max(DP[i][j][k], DP[i][j][k - 1] + num[k]);
                if (i > 0)
                {
                    DP[i][j][k] = max(DP[i][j][k], DP[i - 1][j][k - 1] + num[k] * 3);
                }
                if (j > 0)
                {
                    DP[i][j][k] = max(DP[i][j][k], DP[i][j - 1][k - 1] + num[k] * 2);
                }
                ans = max(ans, DP[i][j][k]);
            }
        }
    }
    cout << ans << endl;
}
