// 1-修辭迴文 | 2019/12/23~2019/12/27 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201912/B1-Palindrome.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201912/B1-Palindrome.zip
#include <bits/stdc++.h>
#include<stdio.h>
#include<string.h>

int main()
{
    char str[501]={};
    scanf("%s",str);

    int length = strlen(str);

    if( length % 2 != 0 ){
        printf("NO\n");
        return 0;
    }

    char front_str[251]={};
    strncpy( front_str, str, length/2 );

    char back_str[251]={};
    for(int i=0; i<length/2; i+=1)
    {
        back_str[i] = str[ (length - 1) - i ];
    }

    if( strncmp( front_str, back_str, length/2 ) == 0){
        printf("YES\n");
        printf("%s\n",front_str );
    }
    else
        printf("NO\n");

}
