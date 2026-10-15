// 3-旅行 | 2019/12/23~2019/12/27 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201912/A3-Trip.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201912/A3-Trip.zip
#include <bits/stdc++.h>
#include<iostream>
#define N 205
using namespace std;
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
int main()
{
    IOS;
    int n, m, q;
    cin >> n >> m >> q;
    bool dis[N][N] = {};
    for(int i = 0; i < n; i+=1)
    {
        dis[i][i] = true;
    }
    for(int i = 0; i < m ; i+=1)
    {
        int a, b;
        cin >> a >> b;
        dis[a][b] = true;
    }
    for(int k = 0; k < n; k+=1)
    {
        for(int i = 0; i < n; i+=1)
        {
            for(int j = 0; j < n; j+=1)
            {
                dis[i][j] = dis[i][j] || (dis[i][k] && dis[k][j]);
            }
        }
    }
    for(int i = 0; i < q; i+=1)
    {
        int a, b;
        cin >> a >> b;
        if(dis[a][b])
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}
