// 3-找數字 | 2025/03/17~2025/03/21 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202503/Numbers.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202503/Numbers.zip
#include <bits/stdc++.h>
#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int n, cur;
    cin >> n;
    // prime
    cur = n;
    while (cur++)
    {
        if (isPrime(cur))
        {
            cout << cur << " ";
            break;
        }
    }

    // ^2
    cur = 1;
    while (cur++)
    {
        if (cur * cur > n)
        {
            cout << cur * cur << " ";
            break;
        }
    }

    // ^3
    cur = 1;
    while (cur++)
    {
        if (cur * cur * cur > n)
        {
            cout << cur * cur * cur << endl;
            break;
        }
    }
}
