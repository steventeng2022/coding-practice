// 3-情書解密 | 2019/05/27~2019/05/31 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201905/B3-Love(Q).pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201905/B3-Love.zip
#include <bits/stdc++.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
    char str[1005]={};
    fgets(str, 1000, stdin);

    int k = 0;
    bool findlove = 0;
    while(findlove == false)
    {
        char tmp[1005]={};
        for(int i=0;i<strlen(str);i+=1)
        {
            tmp[i] = str[i];
            if(isalpha(tmp[i]))
            {
                char first ='\0';char last ='\0';

                if(isupper(tmp[i])){
                    first = 'A';last = 'Z';
                }
                else if(islower(tmp[i])){
                    first = 'a';last = 'z';
                }

                if((tmp[i] + k) > last) //over z
                    tmp[i] = (k - (last - tmp[i] + 1)) + first;
                else
                    tmp[i] = tmp[i] + k;
            }
        }

        for(int i=0;i<strlen(tmp);i+=1)
        {
            if( (strncmp(&tmp[i], "Love", 4) == 0) || (strncmp(&tmp[i], "love", 4) == 0))
            {
                findlove = true;
                break;
            }
        }

        if(findlove == true)
            break;
        else
            k += 1;
    }
    printf("%d", k);
    return 0;
}
