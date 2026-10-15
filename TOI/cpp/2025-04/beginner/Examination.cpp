// 2-學測 | 2025/04/28~2025/05/02 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202504/Examination.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202504/Exam.zip
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    int score[6];
    for (int i = 0; i < 6; ++i)
    {
        cin >> score[i];
    }
    int standard[5];
    for (int k = 0; k < 6; ++k)
    {
        for (int i = 0; i < 5; ++i)
        {
            cin >> standard[i];
        }
        if (score[k] == 0)
        {
            cout << "X" << endl;
            continue;
        }
        for (int i = 0; i < 5; ++i)
        {
            if (score[k] >= standard[i])
            {
                cout << char('A' + i) << endl;
                break;
            }
            else if (i == 4)
            {
                cout << "F" << endl;
            }
        }
    }
    return 0;
}
