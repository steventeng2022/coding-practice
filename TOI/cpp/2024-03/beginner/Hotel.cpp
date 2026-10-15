// 2-數字旅館 | 2024/03/18~2024/03/22 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202403/Hotel.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202403/Hotel.zip
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

bool isSquare(int k)
{
    for (int i = 0; i < 10000; ++i)
    {
        if (i * i == k)
        {
            return true;
        }
        else if (i * i > k)
        {
            return false;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int k;
        cin >> k;

        if (k % 6 == 0)
        {
            cout << 1 << " ";
        }
        else if (k % 2 != 0 && k % 3 != 0)
        {
            cout << 2 << " ";
        }
        else if (isSquare(k) || (k % 2 == 0 && k % 7 != 0))
        {
            cout << 3 << " ";
        }
        else
        {
            cout << 0 << " ";
        }
    }
    cout << endl;
}
