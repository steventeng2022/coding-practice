// 彈珠汽水 | 2023/08 新手同好會 | 新手同好會
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202308-OFFLINE/Soda.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202308-OFFLINE/Soda.zip
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    int M, N, K, num = 0;

    cin >> M >> N >> K;

    if (N == 1)
    {
        cout << "YES" << endl;
    }
    else
    {
        num += M;
        while (M >= N)
        {
            num += M / N;
            M = M % N + M / N;
        }
        if (num >= K)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
