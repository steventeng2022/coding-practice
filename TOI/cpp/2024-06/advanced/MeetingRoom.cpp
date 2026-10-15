// 2-會議室租用 | 2024/06/17~2024/06/21 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202406/MeetingRoom.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202406/MeetingRoom.zip
#include <bits/stdc++.h>

#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int N = 200000 + 5;

struct Case {
    int l, r, w;
};

int solve(int n, const int l[N], const int r[N], const int w[N])
{
    static Case v[N];
    static int dp[N];

    for (int i = 0; i < n; ++i)
    {
        v[i] = (Case){l[i], r[i], w[i]};
    }
    sort(v, v + n, [](const auto& lhs, const auto& rhs) {
        return lhs.r < rhs.r;
    });
    dp[0] = v[0].w;
    for (int i = 1; i < n; ++i)
    {
        int cur;
        int pos = lower_bound(v, v + i, (Case){0, v[i].l, 0}, [](const auto& lhs, const auto& rhs) {
            return lhs.r < rhs.r;
        }) - v - 1;

        if (pos < 0)
        {
            cur = v[i].w;
        }
        else
        {
            cur = dp[pos] + v[i].w;
        }
        dp[i] = max(dp[i - 1], cur);
    }
    return dp[n - 1];
}

int main()
{
    int n;
    static int l[N], r[N], w[N];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d%d", &l[i], &r[i], &w[i]);
    }
    printf("%d\n", solve(n, l, r, w));
    return 0;
}
