// 3-垂直對稱 | 2022/05/30~2022/06/05 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202205/Symmetry.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202205/Symmetry.zip
#include <bits/stdc++.h>
#include<stdio.h>

int main()
{
    int n=0;
    int x[1050],y[1050]= {};
    int t;
    int lb=0,rb=0;
    scanf("%d",&n);
    for(int i=0; i<n; ++i)
    {
        scanf("%d%d",&x[i],&t);
        y[i] = t*2;
        if(y[lb] > y[i])
        {
            lb = i;
        }
        if(y[rb] < y[i])
        {
            rb = i;
        }
    }
    int middle_y = (y[lb] + y[rb]) / 2;
    int flag=0;
    for(int i=0; i<n; ++i)
    {
        bool valid = false;
        for(int j=0; j<n; ++j)
        {
            if(x[i] == x[j] && y[i] + y[j] == middle_y *2 )
            {
               valid = true;
            }
        }
        if(valid == false)
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        printf("failure\n");
    }
    else
    {
        printf("success\n");
    }
}
