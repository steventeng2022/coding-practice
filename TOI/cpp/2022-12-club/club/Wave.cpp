// 波動 | 2022/12 新手同好會 | 新手同好會
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202212-OFFLINE/Wave.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202212-OFFLINE/Wave.zip
#include <bits/stdc++.h>
#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;

int cmp(pair<double,int>x,pair<double,int>y)
{
    if(x.first!=y.first)
        return x.first < y.first;
    else
        return x.second < y.second;
}

int main()
{
    pair<double,int>pa[205];
    int n;
    scanf("%d",&n);
    char dir;
    double D,V,time;
    int temp;
    for(int i=0;i<n;++i)
    {
        scanf(" %c%lf%lf",&dir,&D,&V);
        time = D/V;
        if(dir=='W')
            temp=1;
        else if(dir=='S')
            temp=2;
        else if(dir=='E')
            temp=3;
        else if(dir=='N')
            temp=4;
        pa[i] = make_pair(time,temp);
    }
    sort(pa,pa+n,cmp);
    for(int i=0;i<n;++i)
    {
        if(pa[i].second==1)
            printf("W");
        else if (pa[i].second==2)
            printf("S");
        else if (pa[i].second==3)
            printf("E");
        else if (pa[i].second==4)
            printf("N");
    }
}
