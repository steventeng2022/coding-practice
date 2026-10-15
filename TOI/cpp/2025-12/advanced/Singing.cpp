// 3-唱歌對決 | 2025/12/22~2025/12/26 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202512/Singing.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202512/Singing.zip
#include <bits/stdc++.h>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<utility>
#include<unordered_map>
typedef long long ll;
using namespace std;

void bitAdd(vector<int>& bit, int pos, int v)
{
    while (pos < (int)bit.size())
    {
        bit[pos] += v;
        pos += pos & -pos;
    }
}

int bitSum(vector<int>& bit, int pos)
{
    int ret = 0;
    while (pos)
    {
        ret += bit[pos];
        pos -= pos & -pos;
    }
    return ret;
}

ll solve(int n, const int *_x, const int *_y)
{
    int *x = new int [n];
    int *y = new int [n];
    memcpy(x, _x, sizeof(int) * n);
    memcpy(y, _y, sizeof(int) * n);

    ll ret = 0;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i)
    {
        v[i] = make_pair(x[i], y[i]);
    }
    sort(v.begin(), v.end(), [](const auto& lhs, const auto& rhs) {
        return lhs > rhs;
    });

    sort(y, y + n);
    int n1 = unique(y, y + n) - y;
    unordered_map<int, int> hsh;
    for (int i = 0; i < n1; ++i)
    {
        hsh[y[i]] = i;
    }

    vector<int> bit(n1 + 1, 0);

    for (int i = 0; i < n; ++i)
    {
        bitAdd(bit, hsh[v[i].second] + 1, 1);
    }

    int right = n - 1;
    for (int left = 0; left < right; ++left)
    {
        bitAdd(bit, hsh[v[left].second] + 1, -1);
        while (left < right && v[left].first + v[right].first < 0)
        {
            bitAdd(bit, hsh[v[right].second] + 1, -1);
            --right;
        }
        if (left < right)
        {
            ret += (ll)bitSum(bit, n1) - (ll)bitSum(bit, lower_bound(y, y + n1, -v[left].second) - y);
        }
    }

    delete [] x;
    delete [] y;

    return ret;
}

int main()
{
    int n;
    int *x = nullptr, *y = nullptr;
    scanf("%d", &n);
    x = new int[n];
    y = new int[n];
    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d", &x[i], &y[i]);
    }
    printf("%lld\n", solve(n, x, y));
    delete [] x;
    delete [] y;
    return 0;
}
