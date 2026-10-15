// 3-地底寶藏 | 2025/04/28~2025/05/02 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202504/TreasureBox.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202504/TreasureBox.zip
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    int n, min = 10010, idx, repeat = 0;
    cin >> n;
    int num[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> num[i];
    }

    for (int i = 0; i < n; ++i)
    {
        if (num[i] < min)
        {
            repeat = 0;
            min = num[i];
            idx = i;
        }
        else if (num[i] == min)
        {
            repeat = 1;
            idx = i;
        }
    }

    int Y;
    if (repeat)
    {
        Y = num[idx - min];
    }
    else
    {
        Y = num[idx + min];
    }

    cout << num[Y - 1] << endl;
}
