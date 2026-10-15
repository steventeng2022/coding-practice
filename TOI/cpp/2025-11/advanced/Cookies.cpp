// 2-餅乾促銷 | 2025/11/10~2025/11/14 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202511/Cookies.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202511/Cookies.zip
#include <bits/stdc++.h>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int solve_ac(int n, int c, int *a, int *b)
{
    int mxc = c;
    static int dp[20000 + 1];

    for (int i = 0; i < n; ++i)
    {
        mxc = max(mxc, (c - 1) + (a[i] + b[i]));
    }

    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = a[i] + b[i]; j <= mxc; ++j)
        {
            dp[j] = min(dp[j], dp[j - (a[i] + b[i])] + a[i]);
        }
    }

    return *min_element(dp + c, dp + mxc + 1);
}

int main()
{
    int n, c;
    int a[100], b[100];
    scanf("%d%d", &n, &c);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d", &a[i], &b[i]);
    }

    printf("%d\n", solve_ac(n, c, a, b));

    return 0;
}
