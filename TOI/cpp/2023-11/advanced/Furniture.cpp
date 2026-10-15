// 2-家具擺設 | 2023/11/20~2023/11/24 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202311/Furniture.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202311/Furniture.zip
#include <bits/stdc++.h>
#include<cstdio>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    int ans = 2147483647;
    int left = 0, tot = 0;
    vector<pair<int, int>> v;
    vector<int> cnt;

    scanf("%d", &n);
    cnt.resize(n, 0);
    for (int i = 0; i < n; ++i)
    {
        int m;
        scanf("%d", &m);
        for (int j = 0; j < m; ++j)
        {
            int val;
            scanf("%d", &val);
            v.emplace_back(make_pair(val, i));
        }
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < (int)v.size(); ++i)
    {
        if (++cnt[v[i].second] == 1)
        {
            ++tot;
        }
        while (left < i && tot == n)
        {
            ans = min(ans, v[i].first - v[left].first);
            if (--cnt[v[left].second] == 0)
            {
                --tot;
            }
            ++left;
        }
    }
    printf("%d\n", ans);
    return 0;
}
