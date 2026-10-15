// 運送隕石 | 2020/08/15 新手同好會 | 新手同好會
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202008/Delivery.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202008/Delivering.zip
#include <bits/stdc++.h>
//Delivering.cpp
#include<stdio.h>
#include<queue>
using namespace std;
typedef long long ll;

struct point{
    int f, d;
    point(int f, int d) : f(f), d(d) {}
    bool operator < (const point &rhs) const {
        return (ll)f*(ll)rhs.d < (ll)d*(ll)rhs.f;
    }
};

int main()
{
    int n, m, a;
    priority_queue<point> pq;
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; ++i)
    {
        scanf("%d", &a);
        if(a > 1) pq.push(point(a, 1));
    }
    for(int i=0; i<m && pq.size(); ++i)
    {
        point p = pq.top(); pq.pop();
        p.d *= 2;
        if(p.f > p.d)
        {
            pq.push(p);
            pq.push(p);
        }
    }
    if(pq.empty()) printf("1\n");
    else printf("%d\n", pq.top().f/pq.top().d + (pq.top().f%pq.top().d!=0));
    return 0;
}
