// 表演座位 | 2019/08/16 新手同好會 | 新手同好會
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201908-onsite/2-Seats.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201908-onsite/2-Seats.zip
#include <bits/stdc++.h>
#include<stdio.h>

int main()
{
    int N = 0;

    scanf("%d",&N);
    int area = 0, row = 0, num = 0;
    if(N >= 1 && N <= 2500)
    {
        area = 1;

        if(N%25 == 0)
        {
            row = N/25;
            num = 25;
        }
        else
        {
            row = N/25 + 1;
            num = N % 25;
        }
    }
    else if(N > 2500 && N <= 7500)
    {
        area = 2;

        if((N-2500)%50 == 0)
        {
            row = (N-2500)/50;
            num = 50;
        }
        else
        {
            row = (N-2500)/50 + 1;
            num = N % 50;
        }
    }
    else if(N > 7500 && N <= 10000)
    {
        area = 3;

        if((N-7500)%25 == 0)
        {
            row = (N-7500)/25;
            num = 25;
        }
        else
        {
            row = (N-7500)/25 + 1;
            num = N % 25;
        }
    }

    printf("%d %d %d\n", area, row, num);

    return 0;
}
