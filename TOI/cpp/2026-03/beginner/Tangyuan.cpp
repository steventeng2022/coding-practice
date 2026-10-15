// 3-湯圓 | 2026/03/16~2026/03/20 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202603/Tangyuan.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202603/Tangyuan.zip
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    int N, a = 0, b = 0;
    cin >> N;
    int x, y;
    for (int i = 0; i < N; i++)
    {
        cin >> x >> y;
        a += x;
        b += y;
    }
    if (a % 10 == 0)
        cout << a / 10 << " " << 0 << endl;
    else
        cout << (a / 10) + 1 << " " << 10 - (a % 10) << endl;
    if (b % 10 == 0)
        cout << b / 10 << " " << 0 << endl;
    else
        cout << (b / 10) + 1 << " " << 10 - (b % 10) << endl;
}
