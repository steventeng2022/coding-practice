// 1-降雨量統計 | 2024/04/29~2024/05/03 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202404/Rainfall.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202404/Rainfall.zip
#include <bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int R, C;
    cin >> R >> C;
    vector<vector<int>> diff(R+1, vector<int>(C+1, 0));

    int Q;
    cin >> Q;
    for(int i=0; i<Q; i+=1)
    {
        int data[5];
        for(int j=0; j<5; j+=1)cin >> data[j];
        diff[data[0]][data[1]] += data[4];
        diff[data[0]][data[3]] -= data[4];
        diff[data[2]][data[1]] -= data[4];
        diff[data[2]][data[3]] += data[4];
    }

    int rowsum = 0;
    for(int j=0; j<C; ++j)
    {
        rowsum += diff[0][j];
        diff[0][j] = rowsum;
        cout << diff[0][j] << ' ';
    }
    cout << '\n';
    for(int i=1; i<R; ++i)
    {
        rowsum = 0;
        for(int j=0; j<C; ++j)
        {
            rowsum += diff[i][j];
            diff[i][j] = rowsum + diff[i-1][j];
            cout << diff[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
