// 建築倒塌 | 2023/08 新手同好會 | 新手同好會
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202308-OFFLINE/Collapse.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202308-OFFLINE/Collapse.zip
#include <bits/stdc++.h>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    string cur, next;
    cin >> cur;
    next = cur;
    while (1)
    {
        for (int i = 0; i < cur.length(); ++i)
        {
            if (cur[i] != 'X')
            {
                next[i] = cur[i];
            }
            else if (i == 0)
            {
                if (cur[i + 1] == 'L')
                    next[i] = 'L';
                else
                    next[i] = cur[i];
            }
            else if (i == cur.length() - 1)
            {
                if (cur[i - 1] == 'R')
                    next[i] = 'R';
                else
                    next[i] = cur[i];
            }
            else
            {
                if (cur[i - 1] == 'R' && cur[i + 1] != 'L')
                    next[i] = 'R';
                else if (cur[i + 1] == 'L' && cur[i - 1] != 'R')
                    next[i] = 'L';
                else
                    next[i] = 'X';
            }
        }
        if (next == cur)
            break;
        cur = next;
    }

    cout << cur << endl;
}
