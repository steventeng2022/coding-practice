// 1-煲仔飯 | 2023/10/23~2023/10/27 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202310/ClayPotRice.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202310/ClayPotRice.zip
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    int T, G, W, E, B;
    cin >> T >> G >> W >> E >> B;
    int sum = G + W + E + B;
    if (sum > T)
        cout << "-1" << endl;
    else
        cout << sum << endl;
}
