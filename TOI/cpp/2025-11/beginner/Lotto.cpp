// 1-樂透 | 2025/11/10~2025/11/14 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202511/Lotto.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202511/Lotto.zip
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    int ticket[6];
    for (int i = 0; i < 6; i++) {
        cin >> ticket[i];
    }
    int number[6];
    int special;
    for (int i = 0; i < 6; i++) {
        cin >> number[i];
    }
    cin >> special;
    int match_count = 0;
    bool special_match = false;
    for (int i = 0; i < 6; i++) {
        if (ticket[i] == special) {
            special_match = true;
        }
        for (int j = 0; j < 6; j++) {
            if (ticket[i] == number[j]) {
                match_count++;
                break;
            }
        }
    }
    if (match_count == 6) {
        cout << "A" << endl;
    } else if (match_count == 5 && special_match) {
        cout << "B" << endl;
    } else if (match_count == 5) {
        cout << "C" << endl;
    } else if (match_count == 4 && special_match) {
        cout << "D" << endl;
    } else if (match_count == 4) {
        cout << "E" << endl;
    } else if (match_count == 3 && special_match) {
        cout << "F" << endl;
    } else if (match_count == 2 && special_match) {
        cout << "G" << endl;
    } else if (match_count == 3) {
        cout << "H" << endl;
    } else {
        cout << "X" << endl;
    }

    return 0;
}
