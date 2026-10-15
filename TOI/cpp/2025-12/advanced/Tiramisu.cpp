// 2-提拉米蘇 | 2025/12/22~2025/12/26 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202512/Tiramisu.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202512/Tiramisu.zip
#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

struct Point
{
    int x=0, y=0;
};

int main()
{
    int M, N;
    cin >> M >> N;
    vector<Point> Segment1(M);
    long long maxy = 0;
    for(int i=0; i<M; ++i)
    {
        int x, y;
        cin >> x >> y;
        if(y>maxy) maxy = y;
        Segment1[i] = {x, y};
    }
    long long upper = 0;
    for(int i=1; i<M; ++i)
    {
        long long dx = Segment1[i].x - Segment1[i-1].x;
        int dy1 = maxy - Segment1[i].y;
        int dy2 = maxy - Segment1[i-1].y;
        upper += dx * (dy1+dy2);
    }

    vector<Point> Segment2(N);
    for(int i=0; i<N; ++i)
    {
        int x, y;
        cin >> x >> y;
        Segment2[i] = {x, y};
    }
    long long lower = 0;
    for(int i=1; i<N; ++i)
    {
        long long dx = Segment2[i].x - Segment2[i-1].x;
        int dy1 = Segment2[i].y;
        int dy2 = Segment2[i-1].y;
        lower += dx * (dy1+dy2);
    }
    long long rectangle = maxy * Segment1.back().x * 2;
    cout << rectangle - upper - lower << endl;
}
