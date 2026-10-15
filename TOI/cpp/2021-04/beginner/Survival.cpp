// 2-物競天擇 | 2021/04/26~2021/04/30 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202104/Survival.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202104/Survival.zip
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    int N;
    cin>>N;
    int lion_H[2001]={};
    int lion_W[2001]={};
    int min=99999999;
    int idx=0;
    for(int i=0; i<N; ++i)
    {
        cin>>lion_H[i];
    }
    for(int i=0; i<N; ++i)
    {
        cin>>lion_W[i];
        if(lion_H[i]*lion_W[i]<min)
        {
            min = lion_H[i]*lion_W[i];
            idx=i;
        }
    }
    cout<<lion_H[idx]<<" "<<lion_W[idx]<<endl;
}
