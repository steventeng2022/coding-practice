// 直播趕場 | 2021/10/23 新手同好會 | 新手同好會
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202110-OFFLINE/Live.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202110-OFFLINE/Live.zip
#include <bits/stdc++.h>
//live_100.cpp
#include<stdio.h>
#include<algorithm>
using namespace std;
typedef long long ll;

int main()
{
    ll n;
    int s;
    ll ans = 0;
    static ll t[100005] = {0};

    scanf("%lld%d", &n, &s);

    for(int i = 0; i < s; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        ++t[x];
        --t[y + 1];
    }
    for(int i = 1; i <= 100000; ++i)
    {
        t[i] += t[i - 1];
        ans += min(t[i], n);
    }
    printf("%lld\n", ans);
    return 0;
}
