// 1-作物種植 | 2020/06/29~2020/07/03 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202006/Plant.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202006/Plant.zip
#include <bits/stdc++.h>
#include<stdio.h>
#include<algorithm>
struct plant
{
    int s,e;
};
bool cmp(plant a,plant b)
{
    return a.s<b.s;
}
int main()
{
    int M,T;
    scanf("%d%d",&M,&T);
    plant P[10005];
    int DP[10005]={};
    for(int i=0;i<T;i+=1)
    {
        scanf("%d %d",&P[i].s,&P[i].e);
    }
    std::sort(P,P+T,cmp);
    for(int i=0;i<T;i+=1)
    {
        int dis=P[i].e-P[i].s;
        int len=DP[P[i].s]+dis;
        for(int j=P[i].e;j<=M;j+=1)
        {
            if(len<=DP[j]) break;
            DP[j]=len;
        }
    }
    printf("%d\n",DP[M]);
}
