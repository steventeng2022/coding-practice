// 3-高級料理 | 2020/06/29~2020/07/03 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202006/Cuisine.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202006/Cuisine.zip
#include <bits/stdc++.h>
#include<stdio.h>
long long box[200005]= {};
void upgrade(int x,const long long &d,const int &limit)
{
    while(x<=limit)
    {
        box[x]+=d;
        x+=(x&-x);
    }
    return;
}
long long query(int x)
{
    long long sum=0;
    while(x)
    {
        sum+=box[x];
        x-=(x&-x);
    }
    return sum;
}
int main()
{
    int N,Q,A;
    scanf("%d%d%d",&N,&Q,&A);
    for(int i=1; i<=N; i+=1)
    {
        long long x;
        scanf("%lld",&x);
        upgrade(i,x,N);
    }
    for(int i=0; i<Q; i+=1)
    {
        int t;
        scanf("%d",&t);
        if(t==0)
        {
            int cnt=0;
            int take=0;
            while(take!=N)
            {
                int l=take+1,r=N;
                long long sub=query(take);

                while(l!=r)
                {
                    int mid=(l+r)/2;
                    long long re=query(mid)-sub;
                    long long re2=query(mid+1)-sub;
                    if(re>A)
                    {
                        r=mid-1;
                    }
                    else if(re<=A && re2>A)
                    {
                        l=mid;
                        r=mid;
                    }
                    else if(re<A)
                    {
                        l=mid+1;
                    }
                    if(r<l)
                    {
                        l=r;
                    }
                }
                take=l;
                cnt++;
            }
            printf("%d\n",cnt);
        }
        else if(t==1 || t==2)
        {
            int base= t==1?1:-1;
            int ind,w;
            scanf("%d%d",&ind,&w);
            upgrade(ind,w*base,N);
        }
    }
}
