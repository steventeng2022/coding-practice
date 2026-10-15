// 2-午餐 | 2025/06/09~2025/06/13 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202506/Lunch.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202506/Lunch.zip
#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int r, c;
    string seats[100][100];
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> seats[i][j];
        }
    }
    string find;
    cin >> find;
    bool found = false;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (seats[i][j] == find) {
                found = true;
                cout << i + 1 << " " << j + 1 << endl;
            }
        }
    }
    if (!found) {
        cout << "0 0" << endl;
    }
    return 0;
}
