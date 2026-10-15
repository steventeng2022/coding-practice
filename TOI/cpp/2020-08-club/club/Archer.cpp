// 后羿射日 | 2020/08/15 新手同好會 | 新手同好會
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202008/Archer.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202008/Archer.zip
#include <bits/stdc++.h>
#include<stdio.h>
using namespace std;
int main()
{
    int archerX, archerY, archerlevel, range;
    scanf("%d%d%d%d", &archerX, &archerY, &archerlevel, &range);
    int num;
    scanf("%d", &num);
    int sum=0;
    for(int i=0; i<num; ++i)
    {
        int x, y, level;
        scanf("%d%d%d", &x, &y, &level);
        int distance = (archerX-x)*(archerX-x)+(archerY-y)*(archerY-y);
        if(distance <= range*range)
        {
            if(level <= archerlevel)
            {
                sum+=1;
            }
        }
    }
    printf("%d\n", sum);
}
