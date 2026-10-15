// 1-紅包 | 2026/03/16~2026/03/20 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202603/RedEnvelope.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202603/RedEnvelope.zip
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    int N, a, b, c, sum = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> a >> b >> c;
        sum += a * 100 + b * 500 + c * 1000;
    }
    cout << sum << endl;
}
