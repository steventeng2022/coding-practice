// 1-雜訊移除 | 2022/01/03~2022/01/07 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202112/Noise.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202112/Noise.zip
#include <bits/stdc++.h>
#include<stdio.h>
#include<string.h>
int main()
{
    char str[350]={};
    int bit=0;
    scanf("%s",str);
    scanf(" %c",&bit);
    int len = strlen(str);
    int j=0;
    for(int i=0;i<len;++i)
    {
        if(str[i]==bit)
        {
            continue;
        }
        str[j]=str[i];
        j+=1;
    }
    str[j]='\0';
    int x,k = strlen(str)-1;
    for(x=0; x<k ; ++x ,--k)
    {
        if(str[x]!=str[k])
        {
            break;
        }
    }
    if(str[x]==str[k])
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
}
