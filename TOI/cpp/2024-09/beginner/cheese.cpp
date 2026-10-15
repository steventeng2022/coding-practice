// 1-起司 | 2024/09/30~2024/10/04 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202410/cheese.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202410/cheese.zip
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    int L, W, T, K, ans = 0;
    cin >> L >> W >> T >> K;

    if (L % K == 0 && W % K == 0 && T % K == 0) // 確認是否可以整除
    {
        ans = (L / K) * (W / K) * (T / K);
    }

    cout << ans << endl;
}
