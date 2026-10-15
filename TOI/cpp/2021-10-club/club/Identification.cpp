// 辨識碼 | 2021/10/23 新手同好會 | 新手同好會
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202110-OFFLINE/Identification.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202110-OFFLINE/Identification.zip
#include <bits/stdc++.h>
#include<stdio.h>
#include<string.h>
int main()
{
    int a=0,num[500]={};
    scanf("%d",&a);
    char str[500]={};
    scanf("%s",str);
    for(int i=0;i<strlen(str);++i)
    {
        num[i]=str[i]-'0';
    }
    int cnt=strlen(str)-1;
    int check[2000]={};
    while(cnt>=0)
    {
        int sum=0;
        for(int i=cnt;i>cnt-a;--i)
        {
            if(i<0)
            {
                break;
            }
            sum+=num[i];
        }
        check[sum]+=1;
        cnt-=a;
    }
    int flag=0;
    for(int i=0;i<2000;++i)
    {
        if(check[i]>=2)
        {
            flag=1;
        }
    }
    if(flag==1)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
}
