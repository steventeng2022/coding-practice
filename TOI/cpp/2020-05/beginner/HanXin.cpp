// 1-韓信點兵 | 2020/05/25~2020/05/29 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202005/HanXin.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202005/HanXin.zip
#include <bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    int a1,a2,a3;
    int b1,b2,b3;
    cin >> a1 >> b1;
    cin >> a2 >> b2;
    cin >> a3 >> b3;

    int ans = 1;
    while(true)
    {
        if(ans%a1 == b1 && ans%a2 == b2 && ans%a3 == b3)
        {
            cout << ans  << endl;
            return 0;
        }
        ans++;
    }
    return 0;
}
