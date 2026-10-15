// 蛋糕切塊 | 2022/12 新手同好會 | 新手同好會
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202212-OFFLINE/Cake.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202212-OFFLINE/Cake.zip
#include <bits/stdc++.h>
#include<stdio.h>
#include<string.h>
int dp[1005]={};
bool canpull(const char str[],const char flavor[],int fla_len,int ind_len)
{
    if(fla_len>ind_len)
    {
        return false;
    }
    else
    {
        for(int i=0;i<fla_len;++i)
        {
            if(flavor[i]!=str[i])
            {
                return false;
            }
        }
    }
    return true;
}

bool dpp(const char str[],const char flavor[][22],int ind_len,int n,int str_len ,const int len_list[])
{
    if(ind_len == 0)
    {
        return true;
    }
    if(dp[ind_len]==1)
    {
        return true;
    }
    else if (dp[ind_len]==-1)
    {
        return false;
    }
    else
    {
        for(int i=0;i<n;++i)
        {
            if(canpull(str+(str_len-ind_len),flavor[i],len_list[i],ind_len)) // can pull out
            {
                if(dpp(str,flavor,ind_len-len_list[i],n,str_len,len_list))
                {
                    dp[ind_len] = 1;
                    return true;
                }
            }
        }
    }
    dp[ind_len] = -1;
    return false;
}
int main()
{
    char str[1005]={};
    scanf("%s",str);
    int n=0;
    scanf("%d",&n);
    char flavor[1005][22]={};
    int len_list[1005]={};
    for(int i=0;i<n;++i)
    {
        scanf("%s",flavor[i]);
        len_list[i] = strlen(flavor[i]);
    }
    int len = strlen(str);
    if(dpp(str,flavor,len,n,len,len_list))
        printf("yes\n");
    else
        printf("no\n");
}
