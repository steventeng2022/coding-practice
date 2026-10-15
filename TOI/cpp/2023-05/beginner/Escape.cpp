// 2-密室逃脫 | 2023/05/29~2023/06/02 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202305/Escape.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202305/Escape.zip
#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int main()
{
    int R, C;
    cin >> R >> C;
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    char mat[101][101] = {};
    memset(mat, '.', sizeof(mat));
    string str;
    cin >> str;
    int x = 0, y = 0, d = 0;
    mat[x][y] = '*';
    for(int i=0; i<str.size(); i++) {
        int cnt = str[i] - '0';
        for(int j=0; j<cnt; j++) {
            x += dir[d][0];
            y += dir[d][1];
            if(x < 0 || x >= R) {
                x -= dir[d][0];
            }
            if(y < 0 || y >= C) {
                y -= dir[d][1];
            }
            mat[x][y] = '*';
        }
        d = (d + 1) % 4;
    }
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            cout << mat[i][j];
        }
        cout << endl;
    }
 }
