// 基地台規畫 | 2022/08 新手同好會 | 新手同好會
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202208-OFFLINE/Station.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202208-OFFLINE/Station.zip
#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;
struct block
{
    int ux, uy;
    int dx, dy;
    int weight, id;
    bool exist;
};

bool cmp_w(block a, block b)
{
    if(a.weight == b.weight) return a.id < b.id;
    return a.weight > b.weight;
}

bool cmp_id(block a, block b)
{
    return a.id < b.id;
}

bool overlap(block a, block b)
{
    int inter_area = 0, union_area = 0;
    int ixmin, iymin, ixmax, iymax;

    ixmin = max(a.ux, b.ux);
    iymin = max(a.uy, b.uy);
    ixmax = min(a.dx, b.dx);
    iymax = min(a.dy, b.dy);
    inter_area = max(ixmax - ixmin, 0) * max(iymax - iymin, 0);

    int A = (a.dx - a.ux) * (a.dy - a.uy);
    int B = (b.dx - b.ux) * (b.dy - b.uy);
    union_area = A + B - inter_area;
    return inter_area * 4 > union_area;
}

int main()
{
    int N;
    cin >> N;
    block blks[101] = {};
    for(int i=0; i<N; i++)
    {
        cin >> blks[i].ux >> blks[i].uy;
        cin >> blks[i].dx >> blks[i].dy;
        cin >> blks[i].weight;
        blks[i].exist = true;
        blks[i].id = i + 1;
    }

    sort(blks, blks+N, cmp_w);

    for(int i=0; i<N; i++)
    {
        if(blks[i].exist)
        {
            for(int j=i+1; j<N; j++)
            {
                if(blks[j].exist && overlap(blks[i], blks[j]))
                {
                    blks[j].exist = false;
                }
            }
        }
    }

    bool ans = false;
    sort(blks, blks+N, cmp_id);
    for(int i=0; i<N; i++)
    {
        if(blks[i].exist)
        {
            if(ans) cout << " ";
            cout << blks[i].id;
            ans = true;
        }
    }
    cout << endl;
}
