// 1-多項式計算 | 2019/11/25~2019/11/29 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201911/B1-Polynomial.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201911/B1-Polynomial.zip
#include <bits/stdc++.h>
#include <stdio.h>
int main()
{
    int Sum[1001] = {0};
    int maxPower = 0;  //record the max power in input
    for(int i=0;i<2;i+=1)
    {
        int N;
        scanf("%d",&N);
        for(int j=0;j<N;j+=1)
        {
            int Power,Coef;
            scanf("%d %d",&Power, &Coef);
            Sum[Power] += Coef;
            if(Power > maxPower) maxPower = Power;
        }
    }
    bool Check = false; //check if there is no item
    for(int i=maxPower;i>=0;i-=1)
    {
        if(Sum[i] != 0)
        {
            printf("%d:%d\n",i,Sum[i]);
            Check = true;
        }
    }
    if(Check == false) printf("NULL!");

    return 0;
}
