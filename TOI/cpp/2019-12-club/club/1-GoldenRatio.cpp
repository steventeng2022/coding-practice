// 黃金比例 | 2019/12/14 新手同好會 | 新手同好會
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201912-onsite/1-GoldenRatio.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201912-onsite/1-GoldenRatio(for).zip
#include <bits/stdc++.h>
#include<stdio.h>

int main()
{
    int N = 0;
    int h = 0, w = 0;
    scanf("%d", &N);

    int num1 = 0,num2 = 1;
    int num3 = 0;
    for(int i=2;i<=N;i+=1)
    {
        num3 = num1 + num2;
        if( i == N )
            break;
        num1 = num2;
        num2 = num3;
    }

    if( N == 1 ){
        h = 1;
        w = 1;
    }
    else{
        h = num3;
        w = num3 + num2;
    }

    printf("%d:%d\n", h, w);
    return 0;
}
