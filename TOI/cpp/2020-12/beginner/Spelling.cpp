// 1-拼字遊戲 | 2020/12/28~2021/01/01 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202012/Spelling.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202012/Spelling.zip
#include <bits/stdc++.h>
#include<stdio.h>
#include<string.h>
int main()
{
    char input[105]={},word[30]={};
    int ans[150]={};
    for(int i=0;i<150;++i)
    {
        ans[i]=-1;
    }
    scanf("%s %s",input,word);
    int zero_flag=0,index=0;
    for(int i=0;i<strlen(word);++i)
    {
        for(int j=0;j<strlen(input);++j)
        {
            if(word[i]==input[j])
            {
                ans[i]=j;
                input[j]='.';
                break;
            }
        }
    }
    for(int i=0;i<strlen(word);++i)
    {
        if(ans[i]!=-1)
        {
            printf("%d ",ans[i]+1);
        }
        else
        {
            printf("X ");
        }
    }
}
