// 1-建築物拆除 | 2025/04/28~2025/05/02 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202504/Building.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202504/Building.zip
#include <bits/stdc++.h>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;

struct Data {
    ll a, b;
    Data() {}
    Data(ll a, ll b) : a(a), b(b) {}
};

ll solve(Data *arr, int n)
{
    ll ret = 0, pen = 0;
    sort(arr, arr + n, [](const Data& lhs, const Data& rhs) {
        return lhs.a * rhs.b > rhs.a * lhs.b;
    });

    for (int i = 0; i < n; ++i)
    {
        pen += arr[i].a;
    }

    for (int i = 0; i < n; ++i)
    {
        ret += pen * arr[i].b;
        pen -= arr[i].a;
    }

    return ret;
}

int main()
{
    int n;
    Data *arr = nullptr;
    scanf("%d", &n);
    arr = new Data[n];

    for (int i = 0; i < n; ++i)
    {
        scanf("%lld%lld", &arr[i].a, &arr[i].b);
    }

    printf("%lld\n", solve(arr, n));
    delete [] arr;
    return 0;
}
