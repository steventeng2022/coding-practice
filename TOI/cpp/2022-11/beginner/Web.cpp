// 2-瀏覽網站 | 2022/11/28~2022/12/02 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202211/Web.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202211/Web.zip
#include <bits/stdc++.h>
#include<stdio.h>

int main()
{
    int type,number,ans = 0,id=0;
    int showup[1005]={};
    while(scanf("%d%d",&type,&number)==2 && (type!=-1&&number!=-1) )
    {
        if(type == 1)
        {
            showup[number] += 1;
            ans+=1;
        }
        else
        {
            ans -= showup[number];
            showup[number] = 0;
        }
    }
    printf("%d\n",ans);
}
