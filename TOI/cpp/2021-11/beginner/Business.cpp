// 3-帶動商機 | 2021/11/29~2021/12/03 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202111/Business.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202111/Business.zip
#include <bits/stdc++.h>
#include<stdio.h>

int main()
{
    int a[500]={},i=0,len=0,day=0;
    while(scanf("%d",&a[i])==1&&a[i])
    {
        len+=1;
        i+=1;
    }
    scanf("%d",&day);
    for(int k=0;k<day;++k)
    {
        int nextday[31]={};
        for(int i=0; i<len; ++i)
        {
            nextday[i]=a[i];
        }
        for(int i=0; i<len; ++i)
        {
            if(i==0)
            {
                if(a[i]>a[i+1])
                {
                    nextday[i+1]+=int(a[i]*0.1);
                }
            }
            else if(i==len-1)
            {
                if(a[i]>a[i-1])
                {
                    nextday[i-1]+=int(a[i]*0.1);
                }
            }
            else
            {
                if(a[i]>a[i-1])
                {
                    nextday[i-1]+=int(a[i]*0.05);
                }
                if(a[i]>a[i+1])
                {
                    nextday[i+1]+=int(a[i]*0.05);
                }
            }
        }
        for(int i=0; i<len; ++i)
        {
            a[i]=nextday[i];
        }
    }
    for(int i=0;i<len;++i)
    {
        if(i==len-1)
            printf("%d\n",a[i]);
        else
            printf("%d ",a[i]);
    }
}
