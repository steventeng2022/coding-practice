// 3-吸血鬼 | 2024/06/17~2024/06/21 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202406/Vampire.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202406/Vampire.zip
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    int H, W, K;
    cin >> H >> W >> K;
    int map[H + 2][W + 2], newMap[H + 2][W + 2];
    for (int i = 0; i < H + 2; ++i)
    {
        for (int j = 0; j < W + 2; ++j)
        {
            map[i][j] = 2;
            newMap[i][j] = 2;
        }
    } // 初始化所有陣列

    for (int i = 1; i <= H; ++i)
    {
        for (int j = 1; j <= W; ++j)
        {
            cin >> map[i][j];
        }
    } // 輸入初始狀態

    for (int i = 0; i < K; ++i)
    {
        for (int h = 1; h <= H; ++h)
        {
            for (int w = 1; w <= W; ++w)
            {
                if (map[h - 1][w] == 1 || map[h + 1][w] == 1 || map[h][w - 1] == 1 || map[h][w + 1] == 1)
                {
                    newMap[h][w] = 1;
                } // 若四周有吸血鬼獵人，必變成吸血鬼獵人
                else if (map[h][w] == 0 &&
                         (map[h - 1][w - 1] == -1 || map[h - 1][w + 1] == -1 || map[h + 1][w - 1] == -1 || map[h + 1][w + 1] == -1))
                {
                    newMap[h][w] = -1;
                } // 若自身是一般人，且四角有吸血鬼，則變成吸血鬼
                else
                {
                    newMap[h][w] = map[h][w];
                } // 其餘情況照舊
            }
        }

        for (int h = 1; h <= H; ++h)
        {
            for (int w = 1; w <= W; ++w)
            {
                map[h][w] = newMap[h][w];
            }
        } // 複製新的地圖
    }

    for (int i = 1; i <= H; ++i)
    {
        for (int j = 1; j <= W; ++j)
        {
            cout << map[i][j] << " ";
        }
        cout << endl;
    } // 輸出結果
}
