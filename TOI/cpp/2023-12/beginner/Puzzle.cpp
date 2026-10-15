// 3-填字遊戲 | 2023/12/25~2023/12/29 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202312/Puzzle.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202312/Puzzle.zip
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<char>> table(N, vector<char>(N, ' '));

    bool isValid = true;
    for (int i = 0; i < M; ++i)
    {
        char c;
        string s;
        int x, y;
        cin >> c >> s >> x >> y;
        if (c == 'V')
        {
            for (int j = 0; j < s.size(); ++j)
            {
                if ((y + j) >= N || (table[x][y + j] != ' ' && table[x][y + j] != s[j]))
                {
                    isValid = false;
                }
                else
                    table[x][y + j] = s[j];
            }
        }
        else
        {
            for (int j = 0; j < s.size(); ++j)
            {
                if ((x + j) >= N || (table[x + j][y] != ' ' && table[x + j][y] != s[j]))
                {
                    isValid = false;
                }
                else
                    table[x + j][y] = s[j];
            }
        }
    }
    if (isValid)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
