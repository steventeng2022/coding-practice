// 2-比對卡片 | 2022/04/25~2022/04/29 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202204/Match.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202204/Match.zip
#include <bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
//using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int a[500]={},b[500]={};
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
    }
    int ans[500]={};
    for(int i=0;i<n;i++)// initialization
    {
        ans[i]=9999;
    }
    for(int i=0;i<n;i++)// if same
    {
        if(a[i]==b[i])
        {
            ans[i]=0;
        }
    }
    for(int i=0;i<n;i++)// the remain card
    {
        int t=0,x=0;
        for(int j=0;j<n;j++)
        {
            if(a[i]==b[j] && ans[i])
            {
                int temp=0,min=9999999;
                while(temp!=n)
                {
                    if(a[i]==b[temp])
                    {
                        if(abs(temp-i)<min)
                        {
                            min=abs(temp-i);
                        }
                    }
                    temp++;
                }
                ans[i]=min;
                t=1;
            }
        }
        if(t==0 && ans[i])
        {
            ans[i]=-1;
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",ans[i]);
    }
}
