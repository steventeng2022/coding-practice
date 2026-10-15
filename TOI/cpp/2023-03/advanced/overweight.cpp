// 3-行李超重 | 2023/03/27~2023/03/31 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202303/overweight.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202303/overweight.zip
#include <bits/stdc++.h>

#include<cstdio>
#include<cstdint>
#include<climits>
#include<algorithm>
using namespace std;

int main()
{
    int n, t, v;
    int sumW = 0, sumL = 0;
    int ans = INT_MAX;
    int w[100], l[100];
    int dp[10001] = {0};

    scanf("%d%d%d", &n, &t, &v);

    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d", &w[i], &l[i]);
        sumW += w[i];
        sumL += l[i];
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = sumW; j >= w[i]; --j)
        {
            dp[j] = max(dp[j], dp[j - w[i]] + l[i]);
        }
    }

    for (int j = t; j <= sumW; ++j)
    {
        ans = min(ans, (j - t) * v + (sumL - dp[j]));
    }

    if (t >= sumW)
    {
        ans = 0;
    }

    printf("%d\n", ans);
    return 0;
}
