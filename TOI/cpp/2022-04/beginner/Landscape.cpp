// 3-風景 | 2022/04/25~2022/04/29 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202204/Landscape.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202204/Landscape.zip
#include <bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    int N, M;
    cin >> N >> M;
    int build[1005] = {};
    for(int i=0; i<N; i++)
    {
        cin >> build[i];
    }
    int ans = 0;
    // right
    int cur_height = build[M-1];
    for(int i=M; i<N; i++)
    {
        if(build[i] > cur_height)
        {
            ans += 1;
            cur_height = build[i];
        }
    }
    // left
    cur_height = build[M-1];
    for(int i=M-2; i>=0; i--)
    {
        if(build[i] > cur_height)
        {
            ans += 1;
            cur_height = build[i];
        }
    }
    cout << ans << endl;
}
