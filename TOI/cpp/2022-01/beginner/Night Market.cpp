// 3-夜市 | 2022/01/03~2022/01/07 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202112/Night Market.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202112/Night Market.zip
#include <bits/stdc++.h>
#include<iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;
    bool hit[10] = {};
    int record[10] = {};
    bool perfect;
    for(int i=0;i<T;++i)
    {
        for(int j=1;j<10;++j)
        {
            if(record[j]==i)
            {
                record[j] = 0;
            }
        }
        int target;
        cin >> target;
        if(target!=-1 && record[target]==0)
        {
            record[target] = i+12;
            hit[target] = true;
        }
        perfect = true;
        for(int j=1;j<10;++j)
        {
            perfect = perfect && record[j];
        }
        if(perfect)
        {
            break;
        }
    }
    if(perfect)
    {
        cout << "perfect\n";
    }
    else
    {
        int score = 0;
        for(int i=1;i<10;++i)
        {
            score += (i * hit[i]);
        }
        cout << score << "\n";
    }
    return 0;
}
