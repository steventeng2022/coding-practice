// 3-零 | 2021/06/07~2021/06/11 (原定2021 05 月底進行，因應疫情延後) | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202105/Zero.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202105/Zero.zip
#include <bits/stdc++.h>
//zero.cpp
#include<cstdio>
#include<vector>
const int N = 100, W = 20000, OFFSET = 10000;
const int MIN = -10000, MAX = 10000;

bool dp[N][W+5] = {0};
char op[N][W+5], ans[N];

int main()
{
    int n, val[N];
    scanf("%d", &n);

    for(int i=0; i<n; ++i)
    {
        scanf("%d", &val[i]);
    }

    dp[n-1][val[n-1]+OFFSET] = true;
    op[n-1][val[n-1]+OFFSET] = '+';

    dp[n-1][-val[n-1]+OFFSET] = true;
    op[n-1][-val[n-1]+OFFSET] = '-';

    for(int i=n-2; i>=0; --i)
    {
        for(int j=MIN+val[i]; j<=MAX-val[i]; ++j)
        {
            if(dp[i+1][j-val[i]+OFFSET])
            {
                dp[i][j+OFFSET] = true;
                op[i][j+OFFSET] = '+';
            }
            else if(i!=0 && dp[i+1][j+val[i]+OFFSET])
            {
                dp[i][j+OFFSET] = true;
                op[i][j+OFFSET] = '-';
            }
        }
    }

    if(dp[0][0+OFFSET])
    {
        printf("1\n");
        for(int i=1, cur_val=-val[0]; i<n; ++i)
        {
            ans[i] = op[i][cur_val+OFFSET];

            if(ans[i]=='+') cur_val -= val[i];
            else cur_val += val[i];
        }
        printf("%d", val[0]);
        for(int i=1; i<n; ++i)
        {
            printf("%c%d", ans[i], val[i]);
        }
        printf("\n");
    }
    else
    {
        printf("0\n");
    }
    return 0;
}
