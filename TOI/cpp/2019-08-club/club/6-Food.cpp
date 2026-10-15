// 飲食分類 | 2019/08/16 新手同好會 | 新手同好會
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201908-onsite/6-Food.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201908-onsite/6-Food.zip
#include <bits/stdc++.h>
#include<stdio.h>
#include<string.h>

int main()
{
    int N=0;
    scanf("%d",&N);
    char food[51][16]= {};
    char sort[51][16]= {};
    for(int i=0; i<N; i++)
    {
        scanf("%s %s",food[i],sort[i]);
    }

    char chose[16]= {};
    scanf("%s",chose);

    char ans[51][16]= {};
    int count = 0;
    bool search = false;
    for(int i=0; i<N; i++)
    {
        if(strcmp(chose,sort[i])==0)
        {
            strcpy(ans[count],food[i]);
            count += 1;
            search = true;
            //printf("%s\n",food[i]);
        }
    }

    if(search == false)
        printf("No\n");
    else
    {
        for(int i=0; i<count; i++)
        {
            for(int j=i+1; j<count; j++)
            {
                if(strcmp(ans[i],ans[j])>0)
                {
                    char tmp[16]= {};
                    strcpy(tmp,ans[i]);

                    for(int k=0; k<strlen(ans[i]); k++)
                    {
                        ans[i][k]='\0';
                    }
                    strcpy(ans[i],ans[j]);

                    for(int k=0; k<strlen(ans[j]); k++)
                    {
                        ans[j][k]='\0';
                    }
                    strcpy(ans[j],tmp);
                }
            }
        }
        for(int i=0; i<count; i++)
        {
            printf("%s\n",ans[i]);
        }
    }
}
