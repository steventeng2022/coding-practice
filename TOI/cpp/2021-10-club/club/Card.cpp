// 卡牌評分 | 2021/10/23 新手同好會 | 新手同好會
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202110-OFFLINE/Card.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202110-OFFLINE/Card.zip
#include <bits/stdc++.h>
#include<stdio.h>

int main()
{
    int n=0;
    scanf("%d",&n);
    int a[50]= {},d[50]= {},h[50]= {};
    for(int i=1; i<=n; ++i)
    {
        scanf("%d %d %d",&a[i],&d[i],&h[i]);
    }
    int max_attack=-1,max_defense=-1,max_health=-1;
    for(int i=1; i<=n; ++i)
    {
        if(a[i]>max_attack)
        {
            max_attack=a[i];
        }
        if(d[i]>max_defense)
        {
            max_defense=d[i];
        }
        if(h[i]>max_health)
        {
            max_health=h[i];
        }
    }
    int cnt[50]= {};
    for(int i=1; i<=n; ++i)
    {
        if(a[i]==max_attack)
        {
            cnt[i]+=1;
        }
        if(d[i]==max_defense)
        {
            cnt[i]+=1;
        }
        if(h[i]==max_health)
        {
            cnt[i]+=1;
        }
    }
    int mx=-1,index=-1;
    for(int i=1; i<=n; ++i)
    {
        if(cnt[i]>mx)
        {
            mx=cnt[i];
            index=i;
        }
    }
    printf("%d\n",index);
}
