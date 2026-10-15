// 搜集寶藏 | 2023/08 新手同好會 | 新手同好會
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202308-OFFLINE/Treasure.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202308-OFFLINE/Treasure.zip
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cin.sync_with_stdio(0);
        cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for(int i = 0; i < n; ++i)
    {
        for(int j= 0; j < m; ++j)
        {
            cin >> v[i][j];
        }
    }
    for(int i = 1; i < n; ++i)
    {
        v[i][0] += v[i-1][0];
    }

    for(int j = 1; j < m; ++j)
    {
        v[0][j] += v[0][j-1];
    }

    for(int i = 1; i < n; ++i)
    {
        for(int j= 1; j < m; ++j)
        {
            v[i][j] += max(v[i][j-1], v[i-1][j]);
        }
    }

    cout << v[n-1][m-1] << endl;
    return 0;
}
