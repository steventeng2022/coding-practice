// 3-販售蔬果 | 2022/11/28~2022/12/02 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202211/Selling.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202211/Selling.zip
#include <bits/stdc++.h>
//selling.cpp
#include<cstdio>
#include<climits>
#include<algorithm>
#include<deque>
#include<vector>
#include<utility>
using namespace std;

void sgt_init(vector<int> &sgt, vector<int> &no, int id, int l, int r)
{
    sgt[id] = INT_MIN;
    if(l == r)
    {
        no[l] = id;
        return;
    }
    int mid = (l + r) >> 1;
    sgt_init(sgt, no, id << 1, l, mid);
    sgt_init(sgt, no, id << 1 | 1, mid + 1, r);
    return;
}

void sgt_update(vector<int> &sgt, int id, int val)
{
    sgt[id] = val;
    id >>= 1;
    while(id)
    {
        sgt[id] = max(sgt[id << 1], sgt[id << 1 | 1]);
        id >>= 1;
    }
    return;
}

int sgt_query(vector<int> &sgt, int id, int x, int y, int l, int r)
{
    if(x > r || y < l)
    {
        return INT_MIN;
    }
    if(x >= l && y <= r)
    {
        return sgt[id];
    }
    int mid = (x + y) >> 1;
    return max(sgt_query(sgt, id << 1, x, mid, l, r), sgt_query(sgt, id << 1 | 1, mid + 1, y, l, r));
}

int solve(int n, int d, vector<int> &p)
{
    vector<int> sgt(n * 5);
    vector<int> no(n);

    sgt_init(sgt, no, 1, 0, n - 1);
    sgt_update(sgt, no[0], 0);

    for(int i = 1; i < n; ++i)
    {
        sgt_update(sgt, no[i], sgt_query(sgt, 1, 0, n - 1, max(i - d, 0), i - 1) + p[i]);
    }
    return sgt[no[n - 1]];
}

int main()
{
    int n, d;
    vector<int> p;
    scanf("%d%d", &n, &d);
    p.resize(n, 0);
    for(int i = 1; i < n - 1; ++i)
    {
        scanf("%d", &p[i]);
    }
    printf("%d\n", solve(n, d, p));
    return 0;
}
