// 2-捷運 | 2025/03/17~2025/03/21 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202503/MRT.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202503/MRT.zip
#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    double amount = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        amount += x;
    }
    if (n >= 41)
    {
        amount = amount * 0.85;
    }
    else if (n >= 21)
    {
        amount = amount * 0.9;
    }
    else if (n >= 11)
    {
        amount = amount * 0.95;
    }
    if (amount >= 1200)
    {

        cout << 1200 << endl;
    }
    else
    {
        // 四捨五入到整數
        cout << round(amount) << endl;
    }
    return 0;
}
