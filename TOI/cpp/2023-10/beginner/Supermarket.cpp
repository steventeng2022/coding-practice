// 3-超市排隊 | 2023/10/23~2023/10/27 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202310/Supermarket.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202310/Supermarket.zip
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    int A, B, C;
    cin >> A >> B >> C;
    int K, sum, minRoll, minTime, curTime;

    sum = 0;
    for (int i = 0; i < A; ++i)
    {
        cin >> K;
        sum += K;
    }
    minTime = sum * 3 + (A - 1) * 2;
    minRoll = 1;

    sum = 0;
    for (int i = 0; i < B; ++i)
    {
        cin >> K;
        sum += K;
    }
    curTime = sum * 3 + (B - 1) * 2;
    if (curTime < minTime)
    {
        minTime = curTime;
        minRoll = 2;
    }

    sum = 0;
    for (int i = 0; i < C; ++i)
    {
        cin >> K;
        sum += K;
    }
    curTime = sum * 3 + (C - 1) * 2;
    if (curTime < minTime)
    {
        minTime = curTime;
        minRoll = 3;
    }

    cout << minRoll << " " << minTime << endl;
}
