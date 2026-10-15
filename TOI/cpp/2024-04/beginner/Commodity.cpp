// 3-熱門商品 | 2024/04/29~2024/05/03 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202404/Commodity.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202404/Commodity.zip
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    int K, N, R[1001], tmp, most_popular = -1, most_popular_cnt = 0, worst_shop, worst_shop_sells = 10000000;
    cin >> K >> N;
    int M[N], sum[N];
    for (int i = 0; i < 1001; ++i)
    {
        R[i] = 0;
    }
    for (int i = 0; i < K; ++i)
    {
        cin >> tmp;
        R[tmp]++;
    }
    for (int i = 0; i < 1001; ++i)
    {
        if (R[i] > most_popular_cnt)
        {
            most_popular_cnt = R[i];
            most_popular = i;
        }
    }
    for (int i = 0; i < N; ++i)
    {
        cin >> M[i];
    }

    for (int i = 0; i < N; ++i)
    {
        sum[i] = 0;
        for (int j = 0; j < M[i]; ++j)
        {
            cin >> tmp;
            sum[i] += R[tmp];
        }
        if (sum[i] <= worst_shop_sells)
        {
            worst_shop_sells = sum[i];
            worst_shop = i + 1;
        }
    }

    cout << most_popular << " " << worst_shop << endl;
}
