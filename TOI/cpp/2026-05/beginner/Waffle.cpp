// 2-鬆餅 | 2026/05/04~2026/05/08 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202605/Waffle.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202605/Waffle.zip
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
    int m;

    int f[2];
    for (int i = 0; i < 2; i++) {
        cin >> f[i];
    }
    cin >> m;
    int orders[50];
    for (int i = 0; i < m; i++) {
        cin >> orders[i];
    }
    int oven1, oven2;
    oven1 = oven2 = 0;
    for (int i = 0; i < m; i++) {
        int order = orders[i];
        if (oven1 <= oven2) {
            oven1 += f[order - 1];
        } else {
            oven2 += f[order - 1];
        }
    }
    cout << max(oven1, oven2) << endl;
}
