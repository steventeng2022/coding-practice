// 閱讀順序 | 2020/08/15 新手同好會 | 新手同好會
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202008/Reading.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202008/ReadingOrder.zip
#include <bits/stdc++.h>
#include<stdio.h>
#include<string.h>
int main()
{
    char str[100]={},substr[100]={};
    scanf("%s",str);
    scanf("%s",substr);
    char *loc = strstr(str,substr);
    int position = loc-str;
    int substr_len = strlen(substr),whole_len=strlen(str);
    char left[100]={},right[100]={};
    //get left hand side to the axis
    strncpy(left,str,position);
    //get right hand side to the axis
    strncpy(right,str+position+substr_len,whole_len-substr_len-position);
    for(int j=strlen(right)-1;j>=0;--j)
    {
        printf("%c",right[j]);
    }
    printf("%s",substr);
    for(int j=strlen(left)-1;j>=0;--j)
    {
        printf("%c",left[j]);
    }
    printf("\n");
}
