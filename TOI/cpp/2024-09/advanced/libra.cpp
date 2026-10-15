// 3-天秤 | 2024/09/30~2024/10/04 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202410/libra.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202410/libra.zip
#include <bits/stdc++.h>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 100 + 5;

int solve(int n, int *a)
{
    int *dp = nullptr;
    int sum = 0;
    int ret = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += a[i];
    }
    if (sum % 2)
    {
        return 0;
    }
    dp = new int[sum + 1];
    memset(dp, 0, sizeof(int) * (sum + 1));
    dp[0] = 1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = sum; j >= a[i]; --j)
        {
            if (dp[j - a[i]])
            {
                dp[j] = 1;
            }
        }
    }
    ret = dp[sum / 2];
    delete [] dp;
    return ret;
}

int main()
{
    int n;
    int a[maxn];

    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
    }
    printf("%d\n", solve(n, a));

    return 0;
}
