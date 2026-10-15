// 1-數織 | 2024/06/17~2024/06/21 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202406/Nonogram.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202406/Nonogram.zip
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

// nonogram
int main()
{
    int n;
    cin >> n;
    vector<vector<bool>> grid(n, vector<bool>(n));
    for (int r = 0; r < n; ++r)
    {
        for (int c = 0; c < n; ++c)
        {
            bool b;
            cin >> b;
            grid[r][c] = b;
        }
    }
    // check columns
    for (int c = 0; c < n; ++c)
    {
        bool isEmpty = true;
        int count = 0;
        for (int r = 0; r < n; ++r)
        {
            if (grid[r][c])
            {
                ++count;
                isEmpty = false;
            }
            else if (count > 0)
            {
                cout << count << " ";
                count = 0;
            }
        }
        if (count > 0)
        {
            cout << count << " ";
        }
        else if (isEmpty)
        {
            cout << "0";
        }
        cout << endl;
    }
    // check rows
    for (int r = 0; r < n; ++r)
    {
        bool isEmpty = true;
        int count = 0;
        for (int c = 0; c < n; ++c)
        {
            if (grid[r][c])
            {
                ++count;
                isEmpty = false;
            }
            else if (count > 0)
            {
                cout << count << " ";
                count = 0;
            }
        }
        if (count > 0)
        {
            cout << count << " ";
        }
        else if (isEmpty)
        {
            cout << "0";
        }
        cout << endl;
    }
}
