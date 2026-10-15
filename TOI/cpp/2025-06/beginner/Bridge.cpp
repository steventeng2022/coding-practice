// 3-橋牌 | 2025/06/09~2025/06/13 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202506/Bridge.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202506/Bridge.zip
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    // 0: S(Spades), 1: H(Hearts), 2: D(Diamonds), 3: C(Clubs)
    int color[4] = {0, 0, 0, 0};
    int HCP = 0;
    for (int i = 0; i < 13; ++i)
    {
        string card;
        cin >> card;
        int n;
        if (card[0] == 'S')
            ++color[0];
        else if (card[0] == 'H')
            ++color[1];
        else if (card[0] == 'D')
            ++color[2];
        else if (card[0] == 'C')
            ++color[3];

        if (card[1] == 'A')
            HCP += 4;
        else if (card[1] == 'K')
            HCP += 3;
        else if (card[1] == 'Q')
            HCP += 2;
        else if (card[1] == 'J')
            HCP += 1;
    }
    for (int i = 0; i < 4; ++i)
    {
        cout << color[i] << " ";
    }
    cout << endl;

    cout << HCP << endl;
    return 0;
}
