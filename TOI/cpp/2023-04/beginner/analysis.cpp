// 1-成績分析 | 2023/04/24~2023/04/28 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202304/analysis.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202304/analysis.zip
#include <bits/stdc++.h>
#include<stdio.h>

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int worst=501,best=-1;
    int score[130]={};
    int care=-1,ncare=-1;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            scanf("%d",&score[j]);
        }
        int mins=0,plu=0;
        for(int j=0;j<m-1;++j)
        {
            int ans=score[j+1]-score[j];
            if(ans<0)
                mins+=ans;
            else
                plu+=ans;
        }
        if(mins<worst)
        {
            worst=mins;
            care=i+1;
        }
        if(plu>best)
        {
            best=plu;
            ncare=i+1;
        }
    }
    printf("%d\n%d",ncare,care);

}
