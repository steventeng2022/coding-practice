// 草圖 | 2023/08 新手同好會 | 新手同好會
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202308-OFFLINE/Sketch.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202308-OFFLINE/Sketch.zip
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    int R, N;
    cin >> R >> N;
    int range = R * 2 - 1;
    char ans[range][range];
    for (int i = 0; i < range; ++i)
    {
        for (int j = 0; j < range; ++j)
        {
            ans[i][j] = '#';
        }
    }

    int x, y;
    for (int i = 0; i < N; ++i)
    {
        cin >> x >> y;
        ans[x * 2][y * 2] = '&';
    }

    for (int i = 0; i < range; ++i)
    {
        for (int j = 0; j < range; ++j)
        {
            if (ans[i][j] == '#')
            {
                if (i - 1 >= 0 && i + 1 < range && ans[i - 1][j] == '&' && ans[i + 1][j] == '&')
                    ans[i][j] = '|';
                else if (j - 1 >= 0 && j + 1 < range && ans[i][j - 1] == '&' && ans[i][j + 1] == '&')
                    ans[i][j] = '-';
                else if (j - 1 >= 0 && j + 1 < range && i - 1 >= 0 && i + 1 < range)
                {
                    if (ans[i - 1][j - 1] == '&' && ans[i + 1][j + 1] == '&' && ans[i - 1][j + 1] == '&' && ans[i + 1][j - 1] == '&')
                    {
                        ans[i][j] = 'X';
                    }
                    else if (ans[i - 1][j - 1] == '&' && ans[i + 1][j + 1] == '&')
                    {
                        ans[i][j] = '\\';
                    }
                    else if (ans[i + 1][j - 1] == '&' && ans[i - 1][j + 1] == '&')
                    {
                        ans[i][j] = '/';
                    }
                }
            }
        }
    }

    for (int i = 0; i < range; ++i)
    {
        for (int j = 0; j < range; ++j)
        {
            cout << ans[i][j];
        }
        cout << endl;
    }
}
