// 2-選舉 | 2026/03/16~2026/03/20 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202603/Election.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202603/Election.zip
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
    int k;
    cin >> k;
    int a = 0, b = 0;
    for (int i = 0; i < k; ++i)
    {
        int n, m, x;
        cin >> n >> m >> x;
        if (n > m)
        {
            a += x;
        }
        else if (n < m)
        {
            b += x;
        }
    }
    if(a > b)
    {
        cout << "1 " << a << endl;
    }
    else if (a < b)
    {
        cout << "2 " << b << endl;
    }
}
