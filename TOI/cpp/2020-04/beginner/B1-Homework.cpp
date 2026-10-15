// 1-小豪的回家作業 | 2020/04/27~2020/05/04 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202004/B1-Homework.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202004/B1-Homework.zip
#include <bits/stdc++.h>
#include<stdio.h>
int main()
{
    int R = 0,A = 0;
    scanf("%d %d",&R,&A);
    if( R == A )
    {
        A-=3;
    }
    int temp = R - A;
    if( temp >= A )
    {
        printf("%d+%d=%d\n",A,temp,R);
    }
    else
    {
        printf("%d+%d=%d\n",temp,A,R);
    }
}
