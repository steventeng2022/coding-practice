// 3-身分驗證機制 | 2020/04/27~2020/05/04 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202004/B3-Verification.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202004/B3-Verification.zip
#include <bits/stdc++.h>
#include<stdio.h>
int main()
{
    int	id = 0;
    scanf("%d",&id);
    int temp = 0,max1 = -1,flag = 0,max2 = -1,digit = 0;
    temp = id;
    for ( int i = 0 ; i < 9 ; i+=1 )
    {
        digit = temp%10;
        if ( digit > max1 )
        {
            max1 = digit;
            flag = i;
        }
        temp = temp / 10;
    }
    temp = id;
    for ( int i = 0 ; i < 9 ; i+=1 )
    {
        digit = temp%10;
        if ( (digit > max2) && (i != flag) )
        {
            max2 = digit;
        }
        temp = temp / 10;
    }
    int check = 0;
    check = id%1000;
    if ( (max1*max1+max2*max2) == check )
    {
        printf( "Good Morning!\n" );
    }
    else
    {
        printf( "SPY!\n" );
    }
}
