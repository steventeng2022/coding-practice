// 1-因數分解 | 2024/12/23~2024/12/27 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202412/Factors.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202412/Factors.zip
#include <bits/stdc++.h>
#include<cstdio>
#include<vector>
typedef long long ll;

void solve(ll p)
{
    ll f[66];
    int idx = 0;
    for (ll i = 9; i >= 2; --i)
    {
        while (p % i == 0)
        {
            f[idx] = i;
            ++idx;
            p /= i;
        }
    }
    if (p > 1)
    {
        printf("-1\n");
        return;
    }
    for (int i = idx - 1; i >= 0; --i)
    {
        printf("%d%c", f[i], i == 0 ? '\n' : ' ');
    }
    return;
}

int main()
{
    ll p;
    scanf("%lld", &p);
    solve(p);
    return 0;
}
