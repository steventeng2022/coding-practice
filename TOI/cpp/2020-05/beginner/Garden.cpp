// 3-家裡的後花園 | 2020/05/25~2020/05/29 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202005/Garden.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202005/Garden.zip
#include <bits/stdc++.h>
#include<stdio.h>
int main()
{
    int N = 0;
    scanf("%d",&N);
    int a[30] = {};
    for(int i=0; i<N; i+=1)
    {
        scanf("%d",&a[i]);
    }
    int fpos = 35, bpos = 35, flag = 0;
    for(int i=0; i<N; i+=1)
    {
        if(a[i]==1&&flag!=1)
        {
            fpos=i;
            flag=1;
        }
        if(a[i]==1)
        {
            bpos=i;
        }
    }

    int ans=0;
    for(int i=0; i<N; i+=1)
    {
        if(i>=fpos&&i<=bpos)
        {
            if(i==0 || i==N-1)
            {
                continue;
            }
            else if(i!=N-1)
            {
                if(a[i]==0&&a[i-1]!=9&&a[i+1]!=9)
                {
                    ans+=1;
                }
            }
        }
    }
    printf("%d\n",ans);

}
