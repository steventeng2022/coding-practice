// 1-貨幣轉換 | 2019/05/27~2019/05/31 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201905/B1-Currency(Q).pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201905/B1-Currency.zip
#include <bits/stdc++.h>
#include<stdio.h>
#include<string.h>

int main()
{
    int n = 0, m = 0;
    char cur = '\0';
    scanf("%d",&n);
    scanf("%d %c", &m, &cur);

    double HaveMoney = 0;
    if( cur == 'T'){
        HaveMoney = n * 1.0;
    }
    else if( cur == 'U' ){
        HaveMoney = n / 30.9;
    }
    else if( cur == 'J' ){
        HaveMoney = n / 0.28;
    }
    else if( cur == 'E' ){
        HaveMoney = n / 34.5;
    }

    if(HaveMoney < m)
        printf("No Money\n");
    else
    {
        double remain = HaveMoney - m;
        printf("%c %.2f\n", cur, remain);
    }
}
