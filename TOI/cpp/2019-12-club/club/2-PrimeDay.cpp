// 質數日 | 2019/12/14 新手同好會 | 新手同好會
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201912-onsite/2-PrimeDay.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201912-onsite/2-PrimeDay.zip
#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
int main()
{
    int D = 0;
    int N = 0, M = 0;
    scanf("%d", &D);
    for(int i = 0; i < D; i += 1)
    {
        scanf("%d", &N);
        M = N;
        int Digit = 10000000;
        bool Check = true;
        while(M > 0)
        {
            for(int j = 2; j <= sqrt(M); j += 1)
            {
                if(M % j == 0)
                {
                    Check = false;
                    break;
                }
            }
            if(Check == false) break;
            M %= Digit;
            Digit /= 10;
        }
        if(Check == true) printf("%d is a Prime Day!\n", N);
        else printf("%d isn't a Prime Day!\n", N);
    }
}
