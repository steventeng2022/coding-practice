// 1-外送接單 | 2023/05/29~2023/06/02 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202305/Delivery.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202305/dilivery.zip
#include <bits/stdc++.h>
//dilivery.cpp
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;

struct Data{
    int p, t;
};

int main()
{
    int n;
    int ans = 0;
    Data *a = nullptr;

    priority_queue<int> pq;

    scanf("%d", &n);
    a = new Data[n];
    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d", &a[i].p, &a[i].t);
    }
    sort(a, a + n, [](const Data &lhs, const Data &rhs) {
        if (lhs.t != rhs.t)
        {
            return lhs.t < rhs.t;
        }
        return lhs.p < rhs.p;
    });

    for (int i = 0, cur = 0; i < n; ++i)
    {
        pq.push(a[i].p);
        cur += a[i].p;
        if (cur > a[i].t)
        {
            cur -= pq.top(); pq.pop();
        }
    }

    ans = (int)pq.size();

    printf("%d\n", ans);

    delete []a;
    return 0;
}
