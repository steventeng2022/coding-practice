// 2-刮刮樂 | 2020/05/25~2020/05/29 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202005/Lottery.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202005/Lottery.zip
#include <bits/stdc++.h>
#include<stdio.h>
int main()
{
    int a[3]={},b[5]={},c[5]={};
    for(int i=0;i<3;i+=1)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<5;i+=1)
    {
        scanf("%d",&b[i]);
    }
    for(int i=0;i<5;i+=1)
    {
        scanf("%d",&c[i]);
    }
    int ans=0;
    for(int i=0;i<2;i+=1)
    {
        for(int j=0;j<5;j+=1)
        {
            if(a[i]==b[j])
            {
                ans+=c[j];
            }
        }
    }
    int flag=0;
    for(int i=2;i<3;i+=1)
    {
        for(int j=0;j<5;j+=1)
        {
            if(a[i]==b[j])
            {
                ans-=c[j];
                flag=1;
            }
        }
        if(ans<0)
        {
            ans=0;
        }
    }
    if(flag==0)
    {
        printf("%d\n",ans*2);
    }
    else
    {
        printf("%d\n",ans);
    }
}
