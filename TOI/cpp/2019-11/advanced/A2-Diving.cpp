// 2-潛水 | 2019/11/25~2019/11/29 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201911/A2-Diving.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201911/A2-Diving.zip
#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define IOS cin.tie(0), cout.tie(0), ios::sync_with_stdio(false)
#define N 1500
using namespace std;
struct edge
{
    int st;
    int en;
    int w;
    edge(int a, int b, int c):
        st(a), en(b), w(c){};
};
int dis[N] = {};
bool cmp(edge l, edge r)
{
    return l.w < r.w;
}
void init(int n)
{
    for(int i = 0; i < n; i++)
    {
        dis[i] = i;
    }
}
int find_(int x)
{
    if(x == dis[x])
    {
        return x;
    }
    return dis[x] = find_(dis[x]);
}
void union_(int x, int y)
{
    x = find_(x);
    y = find_(y);
    if(x != y)
    {
        dis[x] = y;
    }
}
int main()
{
    IOS;
    int n, m;
    vector<edge> v;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int x, y ,z;
        cin >> x >> y >> z;
        v.emplace_back(edge(x, y, z));
    }
    int a, b;
    cin >> a >> b;
    sort(v.begin(), v.end(), cmp);
    init(n);
    int ans = 0;
    for(int i = 0; i < m; i++)
    {
        int x = v[i].st, y = v[i].en;
        if(find_(x) != find_(y))
        {
            union_(x, y);
        }
        if(find_(a) == find_(b))
        {
            ans = v[i].w;
            break;
        }
    }
    if(ans != 0)
        cout << ans << endl;
    else
        cout << "-1" << endl;
}
