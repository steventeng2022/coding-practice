// 1-射擊遊戲 | 2022/03/28~2022/04/01 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202203/Shooting.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202203/Shooting.zip
#include <bits/stdc++.h>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
typedef long long ll;

struct P{
    int c;
    ll d;
    int one_plus;
    bool operator < (const P &rhs) const{
        return d < rhs.d;
    }
};

int main()
{
    int n, r, vidx = 0;
    ll curD, curD2;

    vector<P> v;
    priority_queue<pair<int, int>> pq;

    scanf("%d%d%lld", &n, &r, &curD);
    curD2 = curD * curD;

    v.resize(n);

    for(int i = 0; i < n; ++i)
    {
        ll x, y;
        scanf("%lld%lld%d%d", &x, &y, &v[i].c, &v[i].one_plus);
        v[i].d = x * x + y * y;
    }

    sort(v.begin(), v.end());

    while(vidx < n && v[vidx].d <= curD2 )
    {
        pq.push(make_pair(v[vidx].one_plus, v[vidx].c));
        ++vidx;
    }

    while(pq.size() && r)
    {
        curD += (ll)pq.top().second;
        curD2 = curD * curD;
        if(pq.top().first == 0) --r;
        pq.pop();

        while(vidx < n && v[vidx].d <= curD2 )
        {
            pq.push(make_pair(v[vidx].one_plus, v[vidx].c));
            ++vidx;
        }
    }

    printf("%lld\n", curD);
    return 0;
}
