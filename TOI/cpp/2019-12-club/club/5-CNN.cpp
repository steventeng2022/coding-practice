// 卷積神經網路 | 2019/12/14 新手同好會 | 新手同好會
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201912-onsite/5-CNN.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201912-onsite/5-CNN.zip
#include <bits/stdc++.h>
#include<stdio.h>

int main()
{
    int n = 0;
    scanf("%d", &n);

    int Image[25][25]={};
    for( int i=0; i<n; i+=1 )
    {
        for( int j=0; j<n; j+=1 )
        {
            scanf("%d",&Image[i][j]);
        }
    }

    int Max_Pooling[25][25]={};
    for( int i=0; i<n; i+=2 )
    {
        for( int j=0; j<n; j+=2 )
        {
            int Max = 0;

            if( Image[i][j] > Max )
                Max = Image[i][j];
            if( Image[i][j+1] > Max )
                Max = Image[i][j+1];
            if( Image[i+1][j] > Max )
                Max = Image[i+1][j];
            if( Image[i+1][j+1] > Max )
                Max = Image[i+1][j+1];

            Max_Pooling[i/2][j/2] = Max;
        }
    }

    for( int i=0; i<n/2; i+=1 )
    {
        for( int j=0; j<n/2; j+=1 )
        {
            printf("%d ", Max_Pooling[i][j]);
        }
        printf("\n");
    }

    return 0;
}
