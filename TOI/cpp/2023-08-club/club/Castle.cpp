// 古堡長廊 | 2023/08 新手同好會 | 新手同好會
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202308-OFFLINE/Castle.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202308-OFFLINE/Castle.zip
#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int year[N], num[N];
    string str;
    for (int i = 0; i < N; ++i)
    {
        cin >> str >> year[i];
        if (str == "ONE")
        {
            num[i] = 1;
        }
        else if (str == "TWO")
        {
            num[i] = 2;
        }
        else if (str == "THREE")
        {
            num[i] = 3;
        }
        else if (str == "FOUR")
        {
            num[i] = 4;
        }
        else if (str == "FIVE")
        {
            num[i] = 5;
        }
        else if (str == "SIX")
        {
            num[i] = 6;
        }
        else if (str == "SEVEN")
        {
            num[i] = 7;
        }
        else if (str == "EIGHT")
        {
            num[i] = 8;
        }
        else if (str == "NINE")
        {
            num[i] = 9;
        }
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = i; j < N; ++j)
        {
            int tmp;
            if (year[j] < year[i])
            {
                tmp = year[j];
                year[j] = year[i];
                year[i] = tmp;
                tmp = num[j];
                num[j] = num[i];
                num[i] = tmp;
            }
        }
    }

    for (int i = 0; i < N; ++i)
        cout << num[i];
    cout << endl;
}
