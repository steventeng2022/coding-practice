// 2-圖書館 | 2023/03/27~2023/03/31 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202303/Library.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202303/library.zip
#include <bits/stdc++.h>
//library.cpp
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cassert>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    static int arr[1000005];
    static int suf_min[1000005];

    int ans = 0;
    int pre_max = INT_MIN;

    scanf("%d", &n);
    assert(1 <= n && n <= 1000000);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
        assert(0 <= arr[i] && arr[i] <= 1000000000);
    }

    suf_min[n] = INT_MAX;

    for (int i = n - 1; i >= 0; --i)
    {
        suf_min[i] = min(suf_min[i + 1], arr[i]);
    }

    for (int i = 0; i < n; ++i)
    {
        pre_max = max(pre_max, arr[i]);
        if (pre_max <= suf_min[i + 1])
        {
            ++ans;
            pre_max = INT_MIN;
        }
    }

    printf("%d\n", ans);

    return 0;
}
