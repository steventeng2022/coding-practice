// 2-電動滑板車 | 2024/09/30~2024/10/04 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202410/eScooter.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202410/eScooter.zip
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    // 每分鐘 3 元計算
    int ori_price = t * 3;

    int standard = 299 + (t-300>0? (t-300)*3: 0);
    // 以上等同於
    // if (t < 300)
    // {
    //     standard = 299;
    // }
    // else
    // {
    //     standard = 299 + (t-300)*3;
    // }
    int plus = 699 + (t-750>0? (t-750)*3: 0);
    // 以上等同於
    // if (t < 750)
    // {
    //     plus = 699;
    // }
    // else
    // {
    //     plus = 699 + (t-750)*3;
    // }
    if (t < 100)
    {
        cout << ori_price << endl;
    }
    else if (plus < standard)
    {
        cout << plus << endl;
    }
    else
    {
        cout << standard << endl;
    }
}
