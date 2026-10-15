// 2-老鷹抓小雞 | 2020/11/23~2020/11/27 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202011/Eagle.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202011/Eagle.zip
#include <bits/stdc++.h>
#include<stdio.h>
int main()
{
    int N;
    scanf("%d", &N);
    int sequence[2001]={};
    for(int i=0;i<N;++i)
    {
        scanf("%d", &sequence[i]);
    }
    int eagle;
    scanf("%d", &eagle);
    int Q;
    scanf("%d", &Q);
    for(int i=0;i<Q;++i)
    {
        int chick;
        scanf("%d", &chick);
        for(int j=0;j<N;++j)
        {
            if(sequence[j]==chick)
            {
                sequence[j]=eagle;
                eagle=chick;
            }
        }
    }
    for(int i=0;i<N;++i)
    {
        printf("%d ", sequence[i]);
    }
    printf("\n");
}
