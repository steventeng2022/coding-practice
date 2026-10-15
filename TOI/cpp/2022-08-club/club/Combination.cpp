// 數字結合 | 2022/08 新手同好會 | 新手同好會
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202208-OFFLINE/Combination.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202208-OFFLINE/Combination.zip
#include <bits/stdc++.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char num1[90]= {},num2[90]= {};
    scanf("%s%s",num1,num2);
    int odd=0,even=0;
    bool flag=false;
    for(int i=0; i<strlen(num1); ++i)
    {
        if(flag==false)
        {
            odd+=(num1[i]-'0');
            flag = !flag;
        }
        else
        {
            even+=(num1[i]-'0');
            flag = !flag;
        }
    }
    flag=false;
    for(int i=0; i<strlen(num2); ++i)
    {
        if(strlen(num1)%2==1 && strlen(num2)%2==1  || strlen(num1)%2==1 && strlen(num2)%2==0)
        {
            if(flag==false)
            {
                even+=(num2[i]-'0');
                flag = !flag;
            }
            else
            {
                odd+=(num2[i]-'0');
                flag = !flag;
            }
        }
        else if(strlen(num1)%2==0 && strlen(num2)%2==0  || strlen(num1)%2==0 && strlen(num2)%2==1)
        {
            if(flag==false)
            {
                odd+=(num2[i]-'0');
                flag = !flag;
            }
            else
            {
                even+=(num2[i]-'0');
                flag = !flag;
            }
        }
    }
    if(abs(odd-even)%11==0)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}
