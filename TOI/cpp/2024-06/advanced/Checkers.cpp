// 3-跳棋問題 | 2024/06/17~2024/06/21 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202406/Checkers.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202406/Checkers.zip
#include <bits/stdc++.h>
#include<iostream>
using namespace std;

int main()
{
    long long int L, R;
    cin >> L >> R;
    cout << (L * R + L + R) << endl;
    return 0;
}
