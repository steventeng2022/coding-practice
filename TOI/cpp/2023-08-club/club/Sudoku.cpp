// 拼圖數獨 | 2023/08 新手同好會 | 新手同好會
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202308-OFFLINE/Sudoku.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202308-OFFLINE/Sudoku.zip
#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

void printPuzzle(int puzzle[9][9])
{
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            cout << puzzle[i][j];
            if (j != 8)
                cout << " ";
        }
        cout << endl;
    }
}

bool check(int puzzle[9][9], int num, int i, int j, vector<pair<int, int>> piece[9], char region)
{
    for (int k = 0; k < 9; ++k)
    {
        if (puzzle[i][k] == num || puzzle[k][j] == num)
            return false;
    }

    int now_piece = int(region - 'A');

    for (int i = 0; i < 9; ++i)
    {
        if (puzzle[piece[now_piece][i].first][piece[now_piece][i].second] == num)
            return false;
    }

    return true;
}

pair<int, int> isSolve(int puzzle[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (puzzle[i][j] == 0)
            {
                return make_pair(i, j);
            }
        }
    }
    return make_pair(-1, -1);
}

bool dfs(int puzzle[9][9], char jigsaw[9][9], vector<pair<int, int>> piece[9])
{
    int now[9][9];
    pair<int, int> cur = isSolve(puzzle);

    if (cur.first == -1)
    {
        return true;
    }
    else
    {
        copy(&puzzle[0][0], &puzzle[0][0] + 81, &now[0][0]);
        for (int num = 1; num <= 9; ++num)
        {
            if (check(now, num, cur.first, cur.second, piece, jigsaw[cur.first][cur.second]))
            {
                now[cur.first][cur.second] = num;
                if (dfs(now, jigsaw, piece))
                {
                    copy(&now[0][0], &now[0][0] + 81, &puzzle[0][0]);
                    return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    int puzzle[9][9];
    char jigsaw[9][9];
    vector<pair<int, int>> piece[9];
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            cin >> puzzle[i][j];
        }
    }

    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            char region;
            cin >> region;
            jigsaw[i][j] = region;
            piece[int(region - 'A')].push_back(make_pair(i, j));
        }
    }

    dfs(puzzle, jigsaw, piece);

    printPuzzle(puzzle);
}
