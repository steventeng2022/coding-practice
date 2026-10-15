// 3-極限運動 | 2021/04/26~2021/04/30 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202104/Sports.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202104/Sports.zip
#include <bits/stdc++.h>
#include<stdio.h>

int main()
{
    int a=0;
    scanf("%d",&a);
    int height[500]={};
    for(int i=1;i<=a;++i)
    {
        scanf("%d",&height[i]);
    }
    int drop_point=0;
    scanf("%d",&drop_point);
    int l_min=-777,r_min=-777,l_index=-1,r_index=-1;
    int l_temp=drop_point,r_temp=drop_point;
    while(height[r_temp]>=height[r_temp+1]&&r_temp+1<a+1)
    {
        r_min = height[r_temp];
        if(r_min >= height[r_temp+1])
        {
            r_min=height[r_temp+1];
            r_index=r_temp+1;
        }
        r_temp+=1;
    }
    if(r_min<0)
    {
        r_min=5000000;
    }
    while(height[l_temp]>=height[l_temp-1]&&l_temp-1>0)
    {
        l_min = height[l_temp];
        if(l_min >= height[l_temp-1])
        {
            l_min=height[l_temp-1];
            l_index=l_temp-1;
        }
        l_temp-=1;
    }
    if(l_min<0)
    {
        l_min=5000000;
    }
    if(r_min<l_min)
    {
        printf("%d\n",r_index);
    }
    else if (r_min>l_min)
    {
        printf("%d\n",l_index);
    }
}
