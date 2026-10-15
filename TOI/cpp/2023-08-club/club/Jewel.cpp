// 珠寶交易 | 2023/08 新手同好會 | 新手同好會
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202308-OFFLINE/Jewel.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202308-OFFLINE/Jewel.zip
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }
    int max_profit = 0;
    int buy_day = -1, sale_day = -1;
    for(int i = 0; i < n; ++i)
    {
        for(int j = i + 1; j < n; ++j)
        {
            if(v[j]-v[i] > max_profit)
            {
                max_profit = v[j]-v[i];
                buy_day = i+1;
                sale_day = j+1;
            }
        }
    }
    if(buy_day == -1)
        cout << -1 << endl;
    else
        cout << buy_day << " " << sale_day << endl;
    return 0;
}
