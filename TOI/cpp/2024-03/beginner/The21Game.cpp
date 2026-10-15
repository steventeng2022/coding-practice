// 1-搶 21 | 2024/03/18~2024/03/22 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202403/The21Game.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202403/The21Game.zip
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    int64_t t, r;
    cin >> t >> r;

    int64_t target = t - (1+r) * (t/(1+r));
    if (target <= r && target != 0)
        cout << 1 << endl;
    else
        cout << 0 << endl;
}
