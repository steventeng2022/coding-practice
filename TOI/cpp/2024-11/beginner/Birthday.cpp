// 1-生日快樂 | 2024/11/11~2024/11/15 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202411/Birthday.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202411/Birthday.zip
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    int cur_MM, cur_DD;
    int birth_MM, birth_DD;
    cin >> cur_MM >> cur_DD;
    cin >> birth_MM >> birth_DD;
    int months[] = {0, 31, 28 ,31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days = 0;
    // if birthday of this year not yet
    if ( cur_MM < birth_MM )
    {
        days += months[cur_MM] - cur_DD;
        for (int i = cur_MM+1; i < birth_MM; ++i)
        {
            days += months[i];
        }
        days += birth_DD;
    }
    else if (cur_MM == birth_MM && cur_DD <= birth_DD)
    {
        days += birth_DD - cur_DD;
    }
    else
    {
        days += months[cur_MM] - cur_DD;
        for (int i = cur_MM+1; i < 13; ++i)
        {
            days += months[i];
        }
        for (int i = 1; i < birth_MM; ++i)
        {
            days += months[i];
        }
        days += birth_DD;
    }
    cout << days << endl;
    return 0;
}
