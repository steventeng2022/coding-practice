// 3-塗鴉連線 | 2025/12/22~2025/12/26 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202512/Doodle.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202512/Doodle.zip
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    int L, W;
    int area[20][20] = {0};
    cin >> L >> W;
    for (int i = 0; i < L; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            cin >> area[i][j];
        }
    }

    int curx = 0, cury = 0, cnt = 1;
    while (1)
    {
        area[cury][curx] = 0;
        if (curx == W - 1 && cury == L - 1)
        {
            cout << cnt << endl;
            break;
        }

        if (curx + 1 < W && area[cury][curx + 1] == 1)
        {
            curx++;
            cnt++;
        }
        else if (cury + 1 < L && area[cury + 1][curx] == 1)
        {
            cury++;
            cnt++;
        }
        else if (curx - 1 >= 0 && area[cury][curx - 1] == 1)
        {
            curx--;
            cnt++;
        }
        else if (cury - 1 >= 0 && area[cury - 1][curx] == 1)
        {
            cury--;
            cnt++;
        }
    }
}
