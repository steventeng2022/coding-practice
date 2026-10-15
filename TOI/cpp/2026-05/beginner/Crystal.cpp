// 1-水晶共鳴 | 2026/05/04~2026/05/08 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202605/Crystal.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202605/Crystal.zip
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int cnt = 1, now;
    cin >> now;     // 輸入第一個能量團屬性
    int last = now; // 記錄上一個能量團屬性
    for (int i = 1; i < N; ++i)
    {
        cin >> now;
        if (now == last) // 會合併成之前的能量團
        {
            ++cnt;
        }
        else // 新的能量團
        {
            cout << cnt << " "; // 輸出上個能量團強度
            cnt = 1;            // 重置計數器
            last = now;         // 更新當前能量團屬性
        }
    }
    cout << cnt << endl; // 輸出最後一個能量團的強度
}
