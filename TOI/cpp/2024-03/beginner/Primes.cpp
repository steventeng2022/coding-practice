// 3-質數遊戲 | 2024/03/18~2024/03/22 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202403/Primes.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202403/Primes.zip
#include <bits/stdc++.h>
#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int n)
{
    if (n % 2 == 0 && n != 2)
    {
        return false;
    }

    if (n > 3)
    {
        for (int i = 3; i <= sqrt(n); i += 2)
        {
            if (n % i == 0)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int N, a = 0, b = 0;
    cin >> N;
    for (int i = 2; i <= sqrt(N); ++i)
    {
        if (N % i == 0)
        {
            a = i;
            b = N / i;
        }
    }

    if (isPrime(a) && isPrime(b))
    {
        cout << a << " " << b << endl;
    }
    else
    {
        cout << "0 0" << endl;
    }
}
