// 3-三仙鬥法 | 2026/03/16~2026/03/20 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202603/Competition.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202603/Competition.zip
#include <bits/stdc++.h>
#include<iostream>
using namespace std;

int main()
{
    int R;
    cin >> R;
    for(int i=0; i<R; ++i)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        if( (a&1) == (b&1) && (b&1) == (c&1) )
        {
            cout << "A B C";
        }
        else if( (a&1) == (b&1) )
        {
            cout << "C";
        }
        else if( (b&1) == (c&1) )
        {
            cout << "A";
        }
        else
        {
            cout << "B";
        }
        cout << endl;
    }
}
