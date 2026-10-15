// 2-雕像排序成本 | 2024/03/18~2024/03/22 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202403/Sculpture.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202403/Sculpture.zip
#include <bits/stdc++.h>

#include<cstdio>
#include<cstring>
#include<cassert>
typedef long long ll;

void msort(int *a, int lb, int ub, ll& ret)
{
    if (lb == ub)
    {
        return;
    }
    int mid = (lb + ub) / 2;
    msort(a, lb, mid, ret);
    msort(a, mid + 1, ub, ret);

    int xidx = lb, yidx = mid + 1;
    int tidx = 0;
    int *tmp = new int[ub - lb + 1];
    ll *pre = new ll[mid - lb + 1 + 1];
    pre[0] = 0;
    for (int i = lb; i <= mid; ++i)
    {
        pre[i - lb + 1] = pre[i - lb] + (ll)a[i];
    }

    while (xidx <= mid && yidx <= ub)
    {
        if (a[xidx] <= a[yidx])
        {
            tmp[tidx] = a[xidx];
            ++xidx;
        }
        else
        {
            ret += pre[mid + 1 - lb] - pre[xidx - lb];
            ret += (ll)(mid - xidx + 1) * (ll)a[yidx];
            tmp[tidx] = a[yidx];
            ++yidx;
        }
        ++tidx;
    }

    while (xidx <= mid)
    {
        tmp[tidx] = a[xidx];
        ++xidx;
        ++tidx;
    }

    while (yidx <= ub)
    {
        tmp[tidx] = a[yidx];
        ++yidx;
        ++tidx;
    }

    for (int i = lb; i <= ub; ++i)
    {
        a[i] = tmp[i - lb];
    }

    delete [] tmp;
    delete [] pre;
    return;
}

ll solve_nlgn(int n, int *w)
{
    ll ret = 0;
    msort(w, 0, n - 1, ret);
    return ret;
}

int main()
{
    int n, *w = nullptr;

    scanf("%d", &n);

    w = new int[n];
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &w[i]);
    }

    ll ans = solve_nlgn(n, w);

    printf("%lld\n", ans);

    delete [] w;

    return 0;
}
