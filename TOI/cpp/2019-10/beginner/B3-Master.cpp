// 3-虛擬寵物大師 | 2019/10/21~2019/10/31 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201910/B3-Master.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201910/B3-Master.zip
#include <bits/stdc++.h>
#include<stdio.h>

int main()
{
    int n = 0, S = 0;
    scanf("%d %d", &n, &S);

    int BestCp = 0, BestCp_No = 0;
    for(int i=1; i<=n; i+=1)
    {
        int resultCP = 0;
        int cp = 0, iv = 0;
        scanf("%d %d", &cp, &iv);

        int tmpS = S;
        if( iv >= 40 )
            resultCP = cp + (tmpS/1000)*100;
        else if( iv >= 30 )
            resultCP = cp + (tmpS/1000)*50;
        else if( iv >= 0 )
            resultCP = cp + (tmpS/1000)*10;

        if( resultCP > BestCp ){
            BestCp = resultCP;
            BestCp_No = i;
        }
    }

    printf("%d %d\n", BestCp_No, BestCp);
    return 0;
}
