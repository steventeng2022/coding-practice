// 1-辦公室 | 2023/12/25~2023/12/29 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202312/Office.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202312/Office.zip
#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int H, W, K, in, ans = 0;
    cin >> H >> W >> K;
    int8_t workPoint[H][W], tmp[H][W];

    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            cin >> in;
            workPoint[i][j] = in;
        }
    }

    for (int i = 0; i < K; ++i)
    {
        copy(&workPoint[0][0], &workPoint[0][0] + H * W, &tmp[0][0]);

        for (int h = 0; h < H; ++h)
        {
            for (int w = 0; w < W; ++w)
            {
                int big = 0, small = 0, equal = 0;

                if (h - 1 >= 0)
                {
                    if (tmp[h - 1][w] > tmp[h][w])
                        ++big;
                    else if (tmp[h - 1][w] < tmp[h][w])
                        ++small;
                    else
                        ++equal;
                }
                if (h + 1 < H)
                {
                    if (tmp[h + 1][w] > tmp[h][w])
                        ++big;
                    else if (tmp[h + 1][w] < tmp[h][w])
                        ++small;
                    else
                        ++equal;
                }
                if (w - 1 >= 0)
                {
                    if (tmp[h][w - 1] > tmp[h][w])
                        ++big;
                    else if (tmp[h][w - 1] < tmp[h][w])
                        ++small;
                    else
                        ++equal;
                }
                if (w + 1 < W)
                {
                    if (tmp[h][w + 1] > tmp[h][w])
                        ++big;
                    else if (tmp[h][w + 1] < tmp[h][w])
                        ++small;
                    else
                        ++equal;
                }

                if (small > big + equal)
                {
                    workPoint[h][w] = tmp[h][w] - 1;
                    ans -= 1;
                }
                else if (big > small + equal)
                {
                    workPoint[h][w] = tmp[h][w] + 1;
                    ans += 1;
                }
            }
        }
    }
    cout << ans << endl;
}
