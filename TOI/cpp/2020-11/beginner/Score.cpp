// 1-評分系統 | 2020/11/23~2020/11/27 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202011/Score.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202011/Score.zip
#include <bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    int N, S;
    cin>>N>>S;
    int ans[25]={};
    for(int i=0;i<N;++i)
    {
        cin>>ans[i];
    }
    int M;
    cin>>M;
    for(int i=0;i<M;++i)
    {
        int score=0;
        for(int j=0;j<N;++j)
        {
            int X;
            cin>>X;
            if(X==ans[j])
            {
                score+=S;
            }
        }
        cout<<score<<endl;
    }
}
