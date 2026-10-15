// 2-烤肉 | 2023/10/23~2023/10/27 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202310/BBQ.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202310/BBQ.zip
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    int n, m, x, y;
    cin >> n >> m >> x >> y;

    int A = -1, B = -1;
    for(int a = 0; a <= m; ++a)
    {
        int b = m - a;
        if (a * x + b * y == n)
        {
            A = a;
            B = b;
            break;
        }
    }
    cout << A << " " << B << endl;
    return 0;
}
