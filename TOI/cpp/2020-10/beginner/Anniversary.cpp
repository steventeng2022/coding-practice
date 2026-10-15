// 3-週年慶 | 2020/10/26~2020/10/30 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202010/Anniversary.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202010/Anniversary.zip
#include <bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    int price;
    cin>>price;
    int two = price/2000;
    int one = price/1000;
    int discountA = price-two*200;
    int discountB = price-one*100;
    if(discountA<=discountB)
    {
        cout<<discountA<<" "<<0<<endl;
    }
    else
    {
        cout<<discountB<<" "<<1<<endl;
    }
}
