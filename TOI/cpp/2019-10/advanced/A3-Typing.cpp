// 3-猴子打字遊戲 | 2019/10/21~2019/10/31 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201910/A3-Typing.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201910/A3-Typing.zip
#include <bits/stdc++.h>
#include<bits/stdc++.h>
#define infinity 999999
int DP[10005][10005];
int main()
{
    char s[4][10001];
    for(int i=0; i<4; i++)
        scanf("%s",s[i]);
    int L1=strlen(s[0]);
    int win=1;
    int min_d=infinity;
    for(int t=1; t<=3; t++)
    {
        int L2=strlen(s[t]);
        for(int i=0; i<=L1||i<=L2; i++)
            DP[i][0]=DP[0][i]=i*2;
        for(int i=1; i<=L1; i++)
        {
            for(int j=1; j<=L2; j++)
            {
                if(s[0][i-1]==s[t][j-1])
                    DP[i][j]=std::min(DP[i-1][j-1], std::min(DP[i][j-1]+2,DP[i-1][j]+2));
                else
                    DP[i][j]=std::min(DP[i-1][j-1]+3, std::min(DP[i][j-1]+2, DP[i-1][j]+2));
            }
        }
        if (DP[L1][L2]<=min_d)
        {
            min_d=DP[L1][L2];
            win=t;
        }
    }
    printf("%d %d\n",win, min_d);
}
