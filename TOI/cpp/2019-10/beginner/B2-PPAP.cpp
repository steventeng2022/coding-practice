// 2-PPAP | 2019/10/21~2019/10/31 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201910/B2-PPAP.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201910/B2-PPAP.zip
#include <bits/stdc++.h>
#include <stdio.h>
int main()
{
    int n=0,k=0,tmp=0;
    scanf("%d",&n);
    while(tmp<n)
    {
        k+=1;
        int s=k*4;
        tmp+=s;
        if(tmp>=n)
        {
            tmp-=s;
            break;
        }
    }
    int ans=n-tmp-1;
    ans/=k;
    if(ans==0) printf("Pen");
    else if(ans==1) printf("Pineapple");
    else if(ans==2) printf("Apple");
    else if(ans==3) printf("Pineapple pen");
}
