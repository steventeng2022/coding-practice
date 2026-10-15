// 1-實境節目選角 | 2021/11/29~2021/12/03 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202111/Casting.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202111/Casting.zip
#include <bits/stdc++.h>
// selection_loop.cpp
#include<cstdio>
#include<cstring>
const int maxn = 17;

int main()
{
    int n, a[maxn][maxn], ans = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for(int mask = 0; mask < (1 << n); ++mask)
    {
        int cnt = 0;
        int used[maxn];
        bool flag = true;
        memset(used, 0, sizeof(used));
        for(int i = 0; i < n; ++i)
        {
            if((mask >> i) & 1)
            {
                used[i] = 1;
                ++cnt;
                for(int j = 0; j < i; ++j)
                {
                    if(used[j] && a[i][j])
                    {
                        //printf("i = %d, j = %d\n", i, j);
                        flag = false;
                        break;
                    }
                }
                if(flag == false) break;
            }

        }
        //printf("flag = %s, mask = %d, cnt = %d\n", flag?"TRUE":"FALSE", mask, cnt);
        if(flag && ans < cnt) ans = cnt;
    }
    printf("%d\n", ans);
    return 0;
}
