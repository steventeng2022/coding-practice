// 3-躲避球 | 2022/03/28~2022/04/01 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202203/DodgeBall.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202203/DodgeBall.zip
#include <bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    int X, R, V;
    cin >> X >> R >> V;
    int N;
    cin >> N;
    int P, S;

    for(int i=0; i<N; i++)
    {
        cin >> P >> S;
        if(abs(X - P) <= R)
        {
            if(S <= V) X = P;
            else
            {
                if(X - P > 0) X += 15;
                else X -= 15;
            }
        }
    }
    cout << X << endl;
}
