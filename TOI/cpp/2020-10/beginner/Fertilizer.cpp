// 2-神奇肥料 | 2020/10/26~2020/10/30 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202010/Fertilizer.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202010/Fertilizer.zip
#include <bits/stdc++.h>
#include<stdio.h>

int main()
{
    int S=0,E=0,A=0;
    scanf("%d%d%d",&S,&E,&A);
    int count=1;
    for(int i=S;i<=E;++i)
    {
        if(S==E)
        {
            printf("1\n");
            break;
        }
        if(count%10==1&&count!=1)
        {
            A-=1;
        }
        if(A==0)
        {
            printf("unsalable\n");
            break;
        }
        if(count%3==0&&count%10!=9)
        {
            S+=S/3;
        }
        else if(count%10!=9&&count%10!=0)
        {
            S+=S/10;
        }
        if(S>=E)
        {
            printf("%d\n",count+1);
            break;
        }
        count+=1;
    }
}
