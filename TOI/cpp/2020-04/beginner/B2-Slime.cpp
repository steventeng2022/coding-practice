// 2-史萊姆生態區 | 2020/04/27~2020/05/04 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202004/B2-Slime.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202004/B2-Slime.zip
#include <bits/stdc++.h>
#include<stdio.h>

int main()
{
    int N=0,T=0;
    scanf("%d%d",&N,&T);
    int ans=0;
    if(N!=1)
    {
        T/=N;
        N/=N;
    }
    int temp=T+N;
    while(temp!=1)
    {
        temp/=2;
        ans+=1;
    }
    printf("%d\n",ans);
}
