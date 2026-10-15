// 幽靈寶藏 | 2019/08/16 新手同好會 | 新手同好會
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201908-onsite/8-Treasure.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201908-onsite/8-Treasure.zip
#include <bits/stdc++.h>
#include<bits/stdc++.h>
int multi[10000005]={};
int add[10000005]={};
int divi[10000005]={};
int main()
{
    for(int i=0;i<10000005;i+=1)
    {
        multi[i]=1;
        divi[i]=1;
    }
    int N,M;
    scanf("%d%d",&N,&M);
    for(int i=0;i<M;i+=1)
    {
        int p,q,r,s;
        scanf("%d%d%d%d",&p,&q,&r,&s);
        if(r==1)
        {
            add[p]+=s;
            add[q+1]-=s;
        }
        else if(r==2)
        {
            multi[p]*=s;
            divi[q+1]*=s;
        }
    }
    int big=0,bigind=1;
    int base=1,x=0;
    for(int i=1;i<=N;i+=1)
    {

        base*=multi[i];
        base/=divi[i];
        x+=add[i];
        //printf("%d %d\n",base,x);
        if(big<x*base)
        {
            big=x*base;
            bigind=i;
        }
    }
    printf("%d %d\n",bigind,big);
}
