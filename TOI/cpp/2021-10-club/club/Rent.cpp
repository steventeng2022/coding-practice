// 租車費用 | 2021/10/23 新手同好會 | 新手同好會
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202110-OFFLINE/Rent.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202110-OFFLINE/Rent.zip
#include <bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    int m1, d1, m2, d2;
    cin>>m1>>d1>>m2>>d2;
    int month[13]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int day=0;
    for(int i=m1+1; i<m2; i++)
    {
        day += month[i];
    }
    if(m1==m2) day += (d2-d1+1);
    else
    {
        day += month[m1]-d1+1;
        day += d2;
    }
    day = day-(day/10);
    int price=day*100;

    cout<<price<<endl;

}
