// 批發出貨 | 2019/08/16 新手同好會 | 新手同好會
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201908-onsite/1-Wholesale.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201908-onsite/1-Wholesale.zip
#include <bits/stdc++.h>
#include <stdio.h>
int main()
{
    int M=0,T=0;
    scanf("%d",&M);
    while(scanf("%d",&T) && T!=0)
    {
        if(T%M==0) printf("%d\n",T/M);
        else printf("%d\n",M-(T%M));
    }
}
