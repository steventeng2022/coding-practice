// 2-完美數 | 2025/09/29~2025/10/03 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202509/perfect.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202509/perfect.zip
#include <bits/stdc++.h>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int N;
    long long sum = 1;
    cin >> N;
    for (int i = 2; i * i <= N; ++i)
    {
        if (N % i == 0)
        {
            sum += i;
            if (N / i != i)
                sum += N / i;
        }
    }

    if (sum == N)
        cout << sum << "\nperfect" << endl;
    else
        cout << sum << "\nnot perfect" << endl;
}
