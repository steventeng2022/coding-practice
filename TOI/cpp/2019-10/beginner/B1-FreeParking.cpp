// 1-免費停車 | 2019/10/21~2019/10/31 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201910/B1-FreeParking.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201910/B1-FreeParking.zip
#include <bits/stdc++.h>
#include <stdio.h>
int main()
{
    int a,b,c;
    int n=0;
    scanf("%d",&n);
    for(int i=0;i<n;i+=1)
    {
        int k=0;
        scanf("%d %d %d",&a,&b,&c);
        for(int j=a+1;j<b;j+=1)
        {
            if(j%c!=0) printf("%d ",j);
            else k+=1;
        }
        if(k==(b-a-1)) printf("No free parking spaces.");
        printf("\n");
    }
}
