// 1-萬有引力 | 2025/03/17~2025/03/21 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202503/Gravitation.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202503/Gravitation.zip
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    int m1, m2, r;
    cin >> m1 >> m2 >> r;
    cout << 6 * m1 * m2 / r / r << endl;
}
