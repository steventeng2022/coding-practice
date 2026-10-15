// 3-鑿井取水 | 2023/03/27~2023/03/31 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202303/water.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202303/water.zip
#include <bits/stdc++.h>
#include<stdio.h>

int main()
{
    int day,up;
    scanf("%d%d",&day,&up);
    int ans=0;
    int temp=up;
    bool flag=0;
    for(int i=0;i<day;++i)
    {
        int house,need,cost=0;
        scanf("%d",&house);
        for(int j=0;j<house;++j)
        {
            scanf("%d",&need);
            cost+=need;
        }
        if(temp-cost<0 && flag!=1)
        {
            flag = 1;
            ans = i+1;
        }
        else
        {
            temp-=cost;
        }
        temp+=up;
    }
    if(flag)
        printf("%d\n",ans);
    else
        printf("-1\n");
}
