// 1-手遊廣告 | 2022/10/24~2022/10/28 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202210/Advertisement.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202210/Advertisement.zip
#include <bits/stdc++.h>
#include<stdio.h>

int main()
{
    int m,att,enemy;
    scanf("%d",&m);
    scanf("%d",&att);
    for(int i=0;i<m;++i)
    {
        scanf("%d",&enemy);
        if(att>enemy)
        {
            att+=enemy;
        }
        else
        {
            break;
        }
    }
    printf("%d\n",att);
}
