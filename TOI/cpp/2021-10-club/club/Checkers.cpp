// 跳棋 | 2021/10/23 新手同好會 | 新手同好會
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202110-OFFLINE/Checkers.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202110-OFFLINE/Checkers.zip
#include <bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    int N;
    cin >> N;
    int checkers[105][105] = {};
    for(int i = 0; i < 105; i++)
    {
        for(int j = 0; j < 105; j++)
        {
            checkers[i][j] = -1;
        }
    }
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            cin >> checkers[i][j];
        }
    }
    int x, y, d;
    int dir[3][2] = {{1, 0}, {1, 1}, {0, 1}};
    bool ans = true;
    cin >> x >> y >> d;
    if(checkers[x + dir[d][0]][y + dir[d][1]] == 0)  //平移
    {
        checkers[x + dir[d][0]][y + dir[d][1]] = 1;
        checkers[x][y] = 0;
    }
    else if(checkers[x + dir[d][0]][y + dir[d][1]] == -1)
    {
        cout << "Impossible" << endl;
        ans = false;
    }
    else
    {
        if(checkers[x + dir[d][0] * 2][y + dir[d][1] * 2] == 0) //跳躍
        {
            checkers[x][y] = 0;
            while(checkers[x + dir[d][0] * 2][y + dir[d][1] * 2]==0)
            {
                x = x + dir[d][0] * 2;
                y = y + dir[d][1] * 2;
            }
            checkers[x][y] = 1;

        }
        else
        {
            cout << "Impossible" << endl;
            ans = false;
        }
    }
    if(ans)
    {
        for(int i = 1; i <= N; i++)
        {
            for(int j = 1; j <= N; j++)
            {
                cout << checkers[i][j];
                if(j != N) cout << " ";
            }
            cout << "\n";
        }
    }

}
