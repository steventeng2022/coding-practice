// 3-蟲蟲危機 | 2021/03/22~2021/03/30 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202103/Insect.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202103/Insect.zip
#include <bits/stdc++.h>
#include<iostream>
using namespace std;

int main()
{
    int M, N;
    cin>>M>>N;
    int ant=0, grasshopper=0;
    for(int i=0; i<M; ++i)
    {
        int a;
        cin>>a;
        ant += a;
    }
    for(int j=0; j<N; ++j)
    {
        int g;
        cin>>g;
        grasshopper += g;
    }
    if(ant>grasshopper && M>N)
    {
        cout<<"Yes\n";
    }
    else
    {
        cout<<"No\n";
    }
}
