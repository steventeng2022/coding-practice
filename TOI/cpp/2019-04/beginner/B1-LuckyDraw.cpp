// 1-粉專抽獎 | 2019/04/22~2019/04/26 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201904/B1-LuckyDraw(Q).pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201904/B1-LuckyDraw.zip
#include <bits/stdc++.h>

#include <iostream>
using namespace std;
int main()
{
    int n=0;
    cin>>n;
    int num[10005]={};
    for(int i=0;i<n;i+=1){
        cin>>num[i];
    }
    int B=num[n-1];
    int total=0;
    for(int i=0;i<n;i+=1){
        if((i+1)% B==1){
            total += num[i];
        }
    }
    int m=total%n;
    if(m==0) m=n;
    cout<<m<<' '<<num[m-1];
}
