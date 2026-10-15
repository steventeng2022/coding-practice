// 2-計程車 | 2022/03/28~2022/04/01 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202203/Taxi.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202203/Taxi.zip
#include <bits/stdc++.h>
#include<stdio.h>

int main()
{
    int k,w,s,e;
    scanf("%d%d%d%d",&k,&w,&s,&e);
    int sum=0;
    if(k>=2)
    {
        sum += 20+(k-2)*5;
    }
    else
    {
        sum += 20;
    }
    sum += w*60/120*5;
    while(e>=19 && e<=23 && e>s)
    {
        sum+=(e+e-1)/(2*1.0)*10; // integer
        e-=1;
    }
    printf("%d\n",sum);
}
