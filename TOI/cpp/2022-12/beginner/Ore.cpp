// 1-不穩定的礦石 | 2022/12/26~2022/12/30 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202212/Ore.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202212/Ore.zip
#include <bits/stdc++.h>
#include<stdio.h>

int main()
{
    int n,a;
    int t[505]= {};
    scanf("%d%d",&n,&a); // a is even number
    int mx=-1,index=-1;
    for(int i=0; i<n; ++i)
    {
        scanf("%d",&t[i]);
        if(t[i]>mx)
        {
            mx=t[i];
            index=i;
        }
    }
    int fn_ore=0,remain=0;
    if(a>=n)
    {
        for(int i=0;i<n;++i)
        {
            fn_ore += t[i];
        }
        remain = 0;
    }
    else
    {
        int left = index - (a/2), right = index + (a/2);
        if(left<0)// left is not enough , need some ore from right
        {
            right = a/2;
            right += (-left);
            left = index;
        }
        else if (right >= n) // right is not enough , need some ore from left
        {
            left = a/2;
            left += right-n+1;
            right = n-index-1;
        }
        else if (left >=0 && right >=0) // balance
        {
            left = a/2;
            right = a/2;
        }
        fn_ore = t[index],remain=0;
        t[index] = -1;
        for(int i=index-left; i<index; ++i)
        {
            fn_ore+=t[i];
            t[i]=-1;
        }
        for(int i=index+1; i<index+right+1; ++i)
        {
            fn_ore+=t[i];
            t[i]=-1;
        }
        for(int i=0; i<n; ++i)
        {
            if(t[i]!=-1)
            {
                remain+=t[i];
            }
        }
    }
    printf("%d %d\n",fn_ore,remain);
}
