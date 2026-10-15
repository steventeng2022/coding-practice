// 3-茶店 | 2025/09/29~2025/10/03 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202509/tea.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202509/tea.zip
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
    int p, d, t, c;
    cin >> p >> d >> t >> c;
    if ( d <= 15 && c == 1)
        p -= 5;
    else if ( d >= 30 && c == 0)
        p -= 5;

    if (t >= 7 && t < 10)
        p -= 5;
    else if (t >= 14 && t < 16)
        p -= 5;

    cout << p << endl;
    return 0;
}
