// 2-尋寶地圖 | 2019/12/23~2019/12/27 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201912/B2-Map.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201912/B2-Map.zip
#include <bits/stdc++.h>
#include <stdio.h>
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);

    int arr1[101][101]={};
    for(int i=0;i<n;i+=1)
    {
        for(int j=0;j<m;j+=1)
        {
            scanf("%d",&arr1[i][j]);
        }
    }
    int arr2[101][101]={};
    for(int i=0;i<n;i+=1)
    {
        for(int j=0;j<m;j+=1)
        {
            scanf("%d",&arr2[i][j]);
        }
    }

    int sum=0;
    for(int i=0;i<n;i+=1)
    {
        for(int j=0;j<m;j+=1)
        {
            sum=0;
            for(int a=0;a<n;a+=1)
            {
                sum+=arr2[a][j];
            }
            for(int b=0;b<m;b+=1)
            {
                sum+=arr2[i][b];
            }
            sum-=arr2[i][j];
            if(sum%2!=0)
            {
                if(arr1[i][j]==0) arr1[i][j]=1;
                else if(arr1[i][j]==1) arr1[i][j]=0;
            }
        }
    }

    for(int i=0;i<n;i+=1)
    {
        for(int j=0;j<m;j+=1)
        {
            printf("%d ",arr1[i][j]);
        }
        printf("\n");
    }
}
