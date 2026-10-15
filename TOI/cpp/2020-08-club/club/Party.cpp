// 同樂會 | 2020/08/15 新手同好會 | 新手同好會
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202008/Party.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202008/party.zip
#include <bits/stdc++.h>
#include<stdio.h>
using namespace std;
int main()
{
    int N, M;
    scanf("%d%d", &N, &M);
    int pizza = M*8;
    if(pizza < N*2)
    {
        printf("Not enough\n");
    }
    else if(pizza > N*3)
    {
        printf("Too much\n");
    }
    else
    {
        printf("yes\n");
    }
}
