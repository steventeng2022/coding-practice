// 標題 | 2022/12 新手同好會 | 新手同好會
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202212-OFFLINE/Title.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202212-OFFLINE/Title.zip
#include <bits/stdc++.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
    char limit[13][5]={"the","a","an","in","on","at","of","for","by","to","and","or","but"};
    char str[550]={},temp[550]={};
    fgets(str,520,stdin);
    int le = strlen(str);
    if(str[le-1] == '\n')
    {
        str[le-1] = '\0';
    }
    int flag=0,flag2=0,index=0,check_s=0,last=0;
    int len = strlen(str);
    for(int i=0;i<len;++i)
    {
        if( str[i] != ' ' && str[i] != '\0' )
        {
            last = i;
            if(flag==0)
            {
                index = i;
                flag = 1;
            }
        }
        else
        {
            if(flag2==0)
            {
                check_s = i+1;
                flag2=1;
            }
            str[index] = toupper(str[index]);
            for(int j=index+1;j<=last;++j)
            {
                str[j] = tolower(str[j]);
            }
            flag = 0;
        }
    }
    str[index] = toupper(str[index]);
    for(int j=index+1;j<=last;++j)
    {
        str[j] = tolower(str[j]);
    }
    flag = 0;
    int z_dex = 0, id = 0;
    for(int i=check_s;i<index;++i)
    {
        if( str[i] != ' ' && str[i] != '\0' )
        {
            temp[z_dex] = str[i];
            if(flag==0)
            {
                id = i;
                flag = 1;
            }
            z_dex+=1;

        }
        else
        {
            temp[z_dex] = '\0';
            temp[0] = tolower(temp[0]);
            for(int j=0;j<13;++j)
            {
                if(strcmp(temp,limit[j])==0)
                {
                    str[id] = tolower(str[id]);
                    break;
                }
            }
            temp[0] = '\0';
            z_dex = 0;
            flag = 0;
        }
    }
    printf("%s",str);
}
