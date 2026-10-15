// 2-洗牌 | 2021/11/29~2021/12/03 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202111/Cards.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202111/Cards.zip
#include <bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    int N, M;
    cin >> N >> M;
    int cards[300]={}, new_cards[300]={};
    for(int i=0; i<N; i++)
    {
        cin >> cards[i];
    }
    for(int i=0; i<M; i++)
    {
        for(int c=0; c<N/2; c++)
        {
            new_cards[c*2] = cards[c];
            new_cards[c*2+1] = cards[c+N/2];
        }
        for(int c=0; c<N; c++)
        {
            cards[c] = new_cards[c];
        }
    }
    for(int i=0; i<N; i++)
    {
        cout << new_cards[i];
        if(i!=N-1) cout << " ";
    }
    cout << endl;

}
