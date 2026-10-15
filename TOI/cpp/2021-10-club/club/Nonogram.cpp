// 簡易數織 | 2021/10/23 新手同好會 | 新手同好會
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202110-OFFLINE/Nonogram.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202110-OFFLINE/Nonogram.zip
#include <bits/stdc++.h>

#include<stdio.h>

int C[3001][501];

int solve(int m, int n)
{
    if(m < 0 || m < n) return 0;
    for(int i = 0; i <= m; ++i)
    {
        for(int j = 0; j <= i && j <= n; ++j)
        {
            if(j == 0 || j == i) C[i][j] = 1;
            else C[i][j] = (C[i-1][j-1] + C[i-1][j]) % 1000000007;
        }
    }
    return C[m][n];
}

int main()
{
    int w, n, sum = 0;
    scanf("%d%d", &w, &n);
    for(int i = 0; i < n; ++i)
    {
        int tmp;
        scanf("%d", &tmp);
        sum += tmp;
    }

    printf("%d\n", solve(w - sum + 1, n));

    return 0;
}
