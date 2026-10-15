// 1-彗星列車 | 2021/10/25~2021/10/29 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202110/Comet.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202110/Comet.zip
#include <bits/stdc++.h>
#include<iostream>
using namespace std;

int main()
{
    int a=0,s=0;
    cin >> a >> s;
    if(s%a==0)
    {
        printf("%d\n",s/a);
    }
    else if (s%a)
    {
        printf("%d\n",(s/a)+1);
    }
}
