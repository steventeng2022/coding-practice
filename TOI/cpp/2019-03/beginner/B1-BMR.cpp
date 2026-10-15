// 1-基礎代謝率 | 2019/03/25~2019/03/29 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201903/B1-BMR(Q).pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201903/B1-BMR.zip
#include <bits/stdc++.h>
#include<stdio.h>

int main()
{
    int N = 0;
    scanf("%d",&N);

    for(int i=0; i<N; ++i)
    {
        int Gender = 0, height = 0, weight = 0, age = 0;
        scanf("%d %d %d %d",&Gender, &age, &height, &weight);

        double BMR = 0;
        if(Gender == 0)
        {
            BMR = (double)(9.6*weight + 1.8*height - 4.7*age + 655);
        }
        else if(Gender == 1)
        {
            BMR = (double)(13.7*weight + 5*height - 6.8*age + 66);
        }

        printf("%.2f\n",BMR);
    }

    return 0;
}
