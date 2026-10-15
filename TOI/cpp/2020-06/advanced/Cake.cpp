// 2-蛋糕 | 2020/06/29~2020/07/03 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202006/Cake.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202006/Cake.zip
#include <bits/stdc++.h>
//cake.cpp
#include<cstdio>
#include<algorithm>
#include<deque>
#include<utility>
#define val first
#define pos second
using namespace std;

int main()
{
    int n, k, ans=0, pre=0, v;
    deque<pair<int, int>> dq;
    scanf("%d%d", &n, &k);
    dq.push_back(make_pair(0, 0));
    for(int i=1; i<=n; ++i)
    {
        scanf("%d", &v);
        pre+=v;
        while(dq.size() && dq.front().pos < i-k) dq.pop_front();
        ans=max(ans, pre-dq.front().val);
        while(dq.size() && dq.back().val > pre) dq.pop_back();
        dq.push_back(make_pair(pre, i));
    }
    printf("%d\n", ans);
    return 0;
}
