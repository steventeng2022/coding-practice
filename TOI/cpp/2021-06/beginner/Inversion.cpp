// 2-倒置文章 | 2021/06/07~2021/06/11 (原定2021 05 月底進行，因應疫情延後) | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202105/Inversion.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202105/Inversion.zip
#include <bits/stdc++.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
    char str[5000]={};
    scanf("%s",str);
    for(int i=0;i<strlen(str);++i)
    {
        int cnt=0;
        if(str[i]=='+')
        {
            continue;
        }
        else if (str[i]=='-')
        {
            int temp=i+1;
            while(isalnum(str[temp]) || isalpha(str[temp]))
            {
                temp+=1;
                cnt+=1;
            }
            for(int j=i+cnt;j>i;j--)
            {
                printf("%c",str[j]);
            }
            i+=cnt;
        }
        else if (isalnum(str[i]) || isalpha(str[i]))
        {
            printf("%c",str[i]);
        }
    }
    printf("\n");
}
