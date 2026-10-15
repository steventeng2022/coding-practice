// 3-遊戲升等 | 2021/04/26~2021/04/30 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202104/Game.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202104/Game.zip
#include <bits/stdc++.h>
#include<cstdio>
const int N = 100000 + 5;
typedef long long ll;

int n;
ll c, arr[N];

int can(ll level)
{
    ll sum = 0;
    for(int i=0; i<n; ++i)
    {
        if(arr[i] < level)
        {
            sum += (level-arr[i])*(level-arr[i]);
            if(sum>c)
            {
                return 0;
            }
        }
    }
    if(sum <= c)
    {
        return 1;
    }
    return 0;
}

int main()
{
    ll x=1, y=20000000, mid, ans=0;

    scanf("%d%lld", &n, &c);
    for(int i=0; i<n; ++i)
    {
        scanf("%lld", &arr[i]);
    }

    while(x<=y)
    {
        mid = (x+y) / 2;
        if(can(mid))
        {
            x = mid+1;
            if(ans < x) ans = mid;
        }
        else
        {
            y = mid-1;
        }
    }

    printf("%lld\n", ans);

    return 0;
}
