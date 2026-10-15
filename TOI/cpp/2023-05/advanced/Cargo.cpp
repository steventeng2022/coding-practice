// 3-載運貨物 | 2023/05/29~2023/06/02 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202305/Cargo.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202305/cargo.zip
#include <bits/stdc++.h>
#include<cstdio>
#include<algorithm>
const int maxn = 200000 + 5, MOD = 1000000000 + 7;
typedef long long ll;
using namespace std;

int solve(int n, int l, int u, const int *w)
{
    static int dp[maxn + 1];
    static int preW[maxn + 1];

    int left = 0, right = 0;

    preW[0] = 0;
    for (int i = 0; i < n; ++i)
    {
        preW[i + 1] = preW[i] + w[i];
    }

    dp[0] = 0;
    dp[1] = 1;

    for (int i = 0; i < n; ++i)
    {

        while (preW[i + 1] - preW[left] > u)
        {
            ++left;
        }
        while (preW[i + 1] - preW[right] >= l)
        {
            ++right;
        }
        dp[i + 1] = (dp[i + 1] + dp[i]) % MOD;
        dp[i + 2] = (dp[right] - dp[left] + MOD) % MOD;
    }

    return dp[n + 1];
}

int main()
{
    int n, l, u;
    static int w[maxn];

    scanf("%d%d%d", &n, &l, &u);

    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &w[i]);
    }

    printf("%d\n", solve(n, l, u, w));

    return 0;
}
