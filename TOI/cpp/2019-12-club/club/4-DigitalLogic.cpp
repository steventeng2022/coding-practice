// 數位邏輯 | 2019/12/14 新手同好會 | 新手同好會
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201912-onsite/4-DigitalLogic.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201912-onsite/4-DigitalLogic.zip
#include <bits/stdc++.h>
#include<stdio.h>

int main()
{
    int input = 0, time = 0;
    scanf("%d %d", &input, &time);

    int logic[101] = {};
    for( int i=1; i<=input*time; i+=1 ){
        scanf("%d", &logic[i]);
    }

    printf("input = %d\n", input);
    int AND[11]={}, OR[11]={}, XOR[11]={};
    for( int i=1; i<=time; i+=1 )
    {
        int num_1 = 0;
        for( int j=0; j<input; j+=1 )
        {
            if( logic[i + j*time] == 1 )
            {
                OR[i] = 1;
                num_1 += 1;
            }
        }

        printf("num 1: %d\n",num_1 );
        if( num_1 % 2 == 1 )
            XOR[i] = 1;
        if( num_1 == input )
            AND[i] = 1;
    }

    printf("AND:");
    for( int i=1; i<=time ; i+=1){
        printf(" %d", AND[i]);
    }
    printf("\n");

    printf(" OR:");
    for( int i=1; i<=time ; i+=1){
        printf(" %d", OR[i]);
    }
    printf("\n");

    printf("XOR:");
    for( int i=1; i<=time ; i+=1){
        printf(" %d", XOR[i]);
    }
    printf("\n");
}
