// 2-幸運7 | 2021/03/22~2021/03/30 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202103/Lucky Seven.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202103/Lucky Seven.zip
#include <bits/stdc++.h>
#include<stdio.h>

int main()
{
    int num=0;
    int maximum=-10,ans=0;
    scanf("%d",&num);
    while(num)
    {
        int temp=num;
        if(temp%7==0)
        {
            temp=temp%70+5000000;
        }
        else
        {
            temp=77-temp%77;
        }
        if(temp>maximum&&temp!=0)
        {
            maximum=temp;
            ans=num;
        }
        scanf("%d",&num);
    }
    printf("%d\n",ans);
}
