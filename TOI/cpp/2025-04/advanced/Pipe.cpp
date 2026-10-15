// 2-水管 | 2025/04/28~2025/05/02 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202504/Pipe.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202504/Pipe.zip
#include <bits/stdc++.h>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 2000 + 1;

int solve(int n, int *a, int *b)
{
    int dp[maxn] = {0};

    for (int i = 1; i <= n; ++i)
    {
        int dg = dp[0];
        for (int j = 1; j <= n; ++j)
        {
            int val = max({dg + min(a[i], b[j]), dp[j], dp[j - 1]});
            dg = dp[j];
            dp[j] = val;
        }
    }
    return dp[n];
}

int main()
{
    int n;
    int a[maxn], b[maxn];
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
    }
    for (int j = 1; j <= n; ++j)
    {
        scanf("%d", &b[j]);
    }
    printf("%d\n", solve(n, a, b));
    return 0;
}
