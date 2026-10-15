// 2-像素圖放大 | 2026/06/8~2026/06/12 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202606/Pixel.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202606/Pixel.zip
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    int N, M, P, Q;
    cin >> N >> M >> P >> Q;
    int pixel[N][M];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> pixel[i][j];
        }
    }

    for (int i = 0; i < N; ++i)
    {
        for (int lmul = 0; lmul < P; ++lmul)
        {
            for (int j = 0; j < M; ++j)
            {
                for (int wmul = 0; wmul < Q; ++wmul)
                {
                    cout << pixel[i][j] << " ";
                }
            }
            cout << endl;
        }
    }
}
