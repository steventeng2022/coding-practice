// 2-年貨大街 | 2024/11/11~2024/11/15 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202411/Market.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202411/Market.zip
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> goods(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> goods[i];
    }
    int X, G;
    int price = 0;
    while(cin >> X >> G)
    {
        if(X == 0 && G == 0)
            break;
        price += goods[X-1] * G;
    }
    cout << price << endl;
    return 0;
}
