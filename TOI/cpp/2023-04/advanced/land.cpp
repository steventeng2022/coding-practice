// 2-收購土地 | 2023/04/24~2023/04/28 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202304/land.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202304/land.zip
#include <bits/stdc++.h>
#include<cstdio>
#include<algorithm>
#include<unordered_map>
const int maxn = 2000000;
using namespace std;

int main()
{
    int n, k;
    static int p[maxn];
    int cnt = 0, left = 0;
    unordered_map<int, int> ump;
    int ans = 1;

    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &p[i]);
        if (++ump[p[i]] == 1)
        {
            ++cnt;
        }
        while (cnt > k)
        {
            unordered_map<int, int>::iterator it = ump.find(p[left]);
            if (--it->second == 0)
            {
                ump.erase(it);
                --cnt;
            }
            ++left;
        }
        ans = max(ans, i - left + 1);
    }
    printf("%d\n", ans);
    return 0;
}
