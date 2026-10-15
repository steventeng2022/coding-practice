// 3-營火晚會 | 2024/03/18~2024/03/22 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202403/CampfireParty.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202403/CampfireParty.zip
#include <bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;

int main()
{
    int N;
    cin >> N;
    N *= 2;
    string circle;
    cin >> circle;
    int count = 0;
    for(int i=0; i<N; ++i)
    {
        int flg = 0;
        for(int j=0; j<N; ++j)
        {
            int index = (i+j)%N;
            if(circle[index]=='W')
            {
                flg += 1;
            }
            else
            {
                flg -= 1;
                if(flg==0)
                {
                    count +=1;
                }
                if(flg<0)
                {
                    i = (i+j)%N;
                    count = 0;
                    break;
                }
            }
        }
        if(flg==0)
        {
            break;
        }
    }
    cout << count << endl;
    return 0;
}
