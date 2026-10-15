// 1-片段排序 | 2025/09/29~2025/10/03 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202509/cut.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202509/cut.zip
#include <bits/stdc++.h>
#include<cstdio>
#include<unordered_map>
using namespace std;
const int maxn = 200000;

int solve(int n, int *a, int *b)
{
    int ret = 0;
    unordered_map<int, int> id;
    for (int i = 0; i < n; ++i)
    {
        id[b[i]] = i;
    }
    for (int i = 1; i < n; ++i)
    {
        if (id[a[i]] != id[a[i - 1]] + 1)
        {
            ++ret;
        }
    }
    return ret;
}

int main()
{
    int n;
    static int a[maxn], b[maxn];

    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &b[i]);
    }

    printf("%d\n", solve(n, a, b));

    return 0;
}
