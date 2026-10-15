// 2-香料 | 2024/12/23~2024/12/27 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202412/Spices.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202412/Spices.zip
#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> s(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> s[i];
    }

    int r, c;
    cin >> r >> c;
    vector<vector<int>> shelf(r, vector<int>(c));
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            cin >> shelf[i][j];
        }
    }
    for (int i = 0; i < n; ++i)
    {
        bool find = false;
        int x = 0, y = 0;
        for (int j = 0; j < r; ++j)
        {
            for (int k = 0; k < c; ++k)
            {
                if (shelf[j][k] == s[i])
                {
                    x = j;
                    y = k;
                    find = true;
                    break;
                }
            }
        }
        if (!find)
        {
            cout << -1 << endl;
        }
        else
            cout << x+1 << " " << y+1 << endl;
    }
}
