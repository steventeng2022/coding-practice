// 2-梗圖著色 | 2019/04/22~2019/04/26 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201904/B2-Coloring(Q).pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201904/B2-Coloring.zip
#include <bits/stdc++.h>
#include<stdio.h>

int main()
{
    int m = 0, n = 0;
    scanf("%d %d", &m, &n);
    for( int i = 0; i < m; ++i )
    {
        int array[105] = {};
        int colored[105] = {};
        int black = 0;

        int start = -1, end = -1;
        for( int j = 0; j < n; ++j )
        {
            scanf("%d", &array[j]);
            if(array[j] == 1)
            {
                black += 1;
                colored[j] = 1;

                if(start == -1) start = j;
                else if(start != -1)
                {
                    end = j;
                    for( int k = start+1; k < end; ++k )
                    {
                        colored[k] = 1;
                    }

                    start = -1;
                    end = -1;
                }
            }
        }

        for( int j = 0; j < n; ++j )
        {
            if(black < 2)
            {
                printf("%d ", array[j]);
            }
            else if(black >= 2)
            {
                printf("%d ", colored[j]);
            }
        }
        printf("\n");
    }
    return 0;
}
