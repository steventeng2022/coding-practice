// 2-撲克 | 2024/04/29~2024/05/03 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202404/Poker.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202404/Poker.zip
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >>n;
    vector<int> cards(n);
    // 紀錄各張牌的數量
    vector<int> cardsCounter(53, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> cards[i];
        // 計算各張牌的數量
        ++cardsCounter[cards[i]];
    }

    // 找到數量最多和最少的牌（同花色）
    int maxCount = 0;
    int minCount = 1000;
    for (int i = 1; i <= 52; ++i)
    {
        if (cardsCounter[i] > maxCount)
        {
            maxCount = cardsCounter[i];
        }
        if (cardsCounter[i] < minCount)
        {
            minCount = cardsCounter[i];
        }
    }

    // minCount 是數量最少的花色的牌數，表示最少有 minCount 副牌
    // 要湊成完整的牌至少要 maxCount 副牌，總共會有 maxCount * 52 張
    // 還需要補的牌數量為 maxCount * 52 - n
    cout << minCount << " " << (maxCount * 52) - n << endl;

}
