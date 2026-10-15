// 2-分班 | 2023/04/24~2023/04/28 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202304/class.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202304/class.zip
#include <bits/stdc++.h>
#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int score1[1005]={},score2[1005]={};
    for(int i=0;i<n;++i)
    {
        scanf("%d",&score1[i]);
    }
    for(int i=0;i<n;++i)
    {
        scanf("%d",&score2[i]);
    }
    int chinese[1005]={},math[1005]={};
    int cnt_ch=1,cnt_ma=1;
    int cnt=0;
    for(int i=0;i<n;++i)
    {
        if(score2[i]-score1[i]>0)
        {
            math[cnt] = i+1;
            cnt_ma+=1;
        }
        else
        {
            chinese[cnt] = i+1;
            cnt_ch+=1;
        }
        cnt+=1;
    }
    if(cnt_ch==1)
    {
        printf("-1");
    }
    else
    {
        for(int i=0;i<cnt;++i)
        {
            if(chinese[i]!=0)
                printf("%d ",chinese[i]);
        }
    }
    printf("\n");
    if(cnt_ma==1)
    {
        printf("-1\n");
    }
    else
    {
        for(int i=0;i<cnt;++i)
        {
            if(math[i]!=0)
                printf("%d ",math[i]);
        }
    }

}
