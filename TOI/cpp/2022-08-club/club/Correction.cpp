// 錯字校正 | 2022/08 新手同好會 | 新手同好會
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202208-OFFLINE/Correction.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202208-OFFLINE/Correction.zip
#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str, ans;
    cin >>  str >> ans;
    int N;
    cin >> N;
    for(int i=0; i<N; i++)
    {
        char src, trg;
        cin >> src >> trg;
        for(int j=0; j<str.size(); j++)
        {
            if(str[j] == src) str[j] = trg;
        }
    }
    int dis = 0;
    for(int i=0; i<str.size(); i++)
    {
        if(str[i] != ans[i]) dis++;
    }
    cout << dis << endl;
}
