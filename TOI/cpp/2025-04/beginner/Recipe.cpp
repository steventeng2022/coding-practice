// 1-食譜換算 | 2025/04/28~2025/05/02 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202504/Recipe.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202504/Recipe.zip
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    int n; // 食材數量
    int a; // 原始份數
    cin >> n >> a;
    int x[10010]; // 所有食材重量
    for (int i = 0; i < n; i++)
    {
        cin >> x[i]; // 食材重量
    }
    int b;
    cin >> b; // 欲製作人數

    for (int i = 0; i < n; i++)
    {
        // 計算每種食材的重量
        if ((x[i] * b) % a != 0)
            x[i] = x[i] * b / a + 1; // 如果無法整除，則向上取整
        else
            x[i] = x[i] * b / a; // 否則直接取整

        cout << x[i] << " "; // 輸出每種食材的重量
    }
    cout << endl;

    return 0;
}
