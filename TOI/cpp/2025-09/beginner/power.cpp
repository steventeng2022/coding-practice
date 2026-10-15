// 1-指數 | 2025/09/29~2025/10/03 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202509/power.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202509/power.zip
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    int limit = M / N, cur = N;
    while (1)
    {
        cout << cur << endl;
        if (cur > limit)
            break;
        cur *= N;
    }
}
