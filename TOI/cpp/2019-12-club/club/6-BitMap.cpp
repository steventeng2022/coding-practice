// 資工系的浪漫 | 2019/12/14 新手同好會 | 新手同好會
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201912-onsite/6-BitMap.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201912-onsite/6-BitMap.zip
#include <bits/stdc++.h>
#include <stdio.h>
int main()
{
    int H = 0,W = 0;
    char C = '\0';

    scanf("%d%d %c",&H,&W,&C);
    for(int i = 0; i < H; i += 1)
    {
        long long int S = 0;
        scanf("%lld",&S);
        bool bRow[63] = {false};

        for(int j = 0; j < W; j += 1)
        {
            if(S % 2 == 1) bRow[j] = true;
            S /= 2;
        }

        for(int j = W-1; j >= 0; j -= 1)
        {
            if(bRow[j]) printf("%c ",C);
            else printf(". ");
        }
        printf("\n");
    }
    return 0;
}
