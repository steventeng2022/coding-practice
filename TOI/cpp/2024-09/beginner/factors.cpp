// 3-因數計算 | 2024/09/30~2024/10/04 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202410/factors.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202410/factors.zip
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    int x, y;
    cin >> x >> y;
    int max = 0, maxNum = 0, cnt = 0;
    for (int i = x; i <= y; ++i) // 查詢整個區間
    {
        cnt = 0;
        for (int j = 1; j <= i; ++j) // 確認因數數量
        {
            if (i % j == 0)
            {
                cnt += 1;
            }
        }
        if (cnt > max) // 如果為當前最大 則更新結果
        {
            max = cnt;
            maxNum = i;
        }
    }
    cout << maxNum << " " << max << endl;
}
