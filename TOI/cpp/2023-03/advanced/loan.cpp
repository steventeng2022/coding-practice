// 1-借款金額 | 2023/03/27~2023/03/31 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202303/loan.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202303/loan.zip
#include <bits/stdc++.h>

#include<cstdio>
typedef long long ll;

ll get_interest(ll balance, int r)
{
    ll interest = balance / (ll)r;
    if (balance % (ll)r != 0)
    {
        ++interest;
    }
    return interest;
}

bool can(const int *arr, int n, int r, ll balance, ll sum)
{
    for (int i = 0; i < n; ++i)
    {
        balance += get_interest(balance, r);
        balance -= (ll)arr[i];

        sum -= (ll)arr[i];

        if (balance <= 0)
        {
            return true;
        }
        if (balance > sum)
        {
            return false;
        }
    }
    return false;
}

int main()
{
    int n, r;
    static int arr[200005];
    ll x = 0, y = 0;
    ll sum = 0;
    ll ans = 0;

    scanf("%d%d", &n, &r);

    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
        sum += (ll)arr[i];
    }

    y = sum;

    while (x <= y)
    {
        ll mid = x + (y - x) / 2ll;

        if (can(arr, n, r, mid, sum))
        {
            x = mid + 1;
            ans = mid;
        }
        else
        {
            y = mid - 1;
        }
    }

    printf("%lld\n", ans);
    return 0;
}
