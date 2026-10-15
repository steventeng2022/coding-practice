// 1-團康活動 | 2022/05/30~2022/06/05 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202205/Activity.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202205/Activity.zip
#include <bits/stdc++.h>
//activity_bs.cpp
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

bool can(vector<int> &a, int t)
{
    int cnt = 0;
    for(const auto &it : a) if(it >= t) ++cnt;
    return cnt >= t;
}

int main()
{
    int n, t;
    vector<int> a;
    scanf("%d", &n);
    a.resize(n);
    for(int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
    }
    int x = 1, y = n, ans = 1;
    while(x <= y)
    {
        int mid = (x + y) / 2;
        if(can(a, mid))
        {
            ans = max(ans, mid);
            x = mid + 1;
        }
        else
        {
            y = mid - 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}
