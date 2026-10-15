// 1-旅遊計畫 | 2024/12/23~2024/12/27 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202412/Travel.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202412/Travel.zip
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    int M[10], N[10];
    for (int i = 0; i < 10; ++i)
    {
        cin >> M[i];
    }
    for (int i = 0; i < 10; ++i)
    {
        cin >> N[i];
    }

    int S = 2147483647, A, B, now;

    for (int i = 0; i < 10; ++i)
    {
        for (int j = i; j < 10; ++j)
        {
            now = M[i] + N[j] + (j - i) * 1000;
            if (now < S)
            {
                S = now;
                A = i;
                B = j;
            }
        }
    }

    cout << A + 1 << " " << B + 1 << " " << S << endl;
}
