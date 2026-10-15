// 1-窗花 | 2025/06/09~2025/06/13 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202506/Tracery.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202506/Tracery.zip
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    int w, h;
    cin >> w >> h;
    char data[1000][1000];

    // 輸入
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            cin >> data[i][j];
        }
    }

    // 輸出
    for (int i = 0; i < h; ++i) // 由上到下輸出
    {
        for (int j = 0; j < w; ++j) // 由左到右輸出
        {
            cout << data[i][j] << " ";
        }
        for (int j = w - 1; j >= 0; --j) // 由右到左輸出
        {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = h - 1; i >= 0; --i) // 由下到上輸出
    {
        for (int j = 0; j < w; ++j) // 由左到右輸出
        {
            cout << data[i][j] << " ";
        }
        for (int j = w - 1; j >= 0; --j) // 由右到左輸出
        {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
}
