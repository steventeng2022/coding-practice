// 站牌廣告 | 2019/12/14 新手同好會 | 新手同好會
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201912-onsite/3-BusStop.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201912-onsite/3-BusStop.zip
#include <bits/stdc++.h>
#include <stdio.h>
int main()
{
    int B,P;
    scanf("%d %d",&B, &P);
    int Stop[1001] = {0};
    for(int i=1;i<=P;i+=1)
    {
        int X, Y;
        scanf("%d %d",&X, &Y);
        if(X > Y)
        {
            int tmp = X;
            X = Y;
            Y = tmp;
        }
        for(int j=X;j<=Y;j+=1)
        {
            Stop[j] += 1;
        }
    }

    int MinS = 1000, MaxS = 1;
    int MinS_Index = 1000, MaxS_Index = 1;
    for(int i=1;i<=B;i+=1)
    {
        if(Stop[i] < MinS)
        {
            MinS = Stop[i];
            MinS_Index = i;
        }

        if(Stop[i] >= MaxS)
        {
            MaxS = Stop[i];
            MaxS_Index = i;
        }
    }

    printf("%d %d",MinS_Index, MaxS_Index);
    return 0;
}
