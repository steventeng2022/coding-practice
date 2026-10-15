// 3-紅豆餅 | 2025/11/10~2025/11/14 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202511/RedBeanCake.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202511/RedBeanCake.zip
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int x;
    int cnt[6] = {0};
    int cake = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        ++cnt[x];
        if (x >= 1 && x <= 5) {
            ++cake;
        }
    }
    for (int i = 0; i < 6; ++i)
    {
       cout << cnt[i] << " ";
    }
    int amount = 0;
    if (cnt[0] >= cake)
    {
        amount += cake * 59;
        amount += (cnt[0] - cake) * 50;
    }
    else
    {
        amount += cnt[0] * 59;
        amount += (cake - cnt[0]) * 20;
    }
    cout << amount << endl;
    return 0;
}
