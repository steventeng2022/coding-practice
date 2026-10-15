// 3-搭船渡河 | 2024/04/29~2024/05/03 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202404/Boat.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202404/Boat.zip
#include <bits/stdc++.h>
// boat.cpp
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

const int N = 17;

int solve(int n, int m, int l, const int w[N])
{
    vector<int> dp(1 << n, 2147483647), sumw(1 << n, 0);

    for (int mask = 0; mask < (1 << n); ++mask)
    {
        for (int i = 0; i < n; ++i)
        {
            if ((mask >> i) & 1)
            {
                sumw[mask] += w[i];
            }
        }
    }

    dp[0] = 0;
    for (int mask = 1; mask < (1 << n); ++mask)
    {
        for (int s = mask; s; s = (s - 1) & mask)
        {
            if (__builtin_popcount(s) <= m && sumw[s] <= l)
            {
                dp[mask] = min(dp[mask], dp[mask ^ s] + 1);
            }
        }
    }

    return dp[(1 << n) - 1];
}

int main()
{
    int n, m, l;
    int w[N];

    scanf("%d%d%d", &n, &m, &l);

    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &w[i]);
    }

    printf("%d\n", solve(n, m, l, w));

    return 0;
}
