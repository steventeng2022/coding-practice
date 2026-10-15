// 3-加油 | 2022/05/30~2022/06/05 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202205/Refueling.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202205/Refueling.zip
#include <bits/stdc++.h>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 200 + 5;
const int inf = 0x3f3f3f3f;

void floyd_warshall(int n, int dis[N][N])
{
    for(int k = 0; k < n; ++k)
    {
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(dis[i][k] != inf && dis[k][j] != inf)
                {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
    }
    return;
}

int main()
{
    int n, m, f;
    int t[N];
    int dis1[N][N], dis2[N][N];

    scanf("%d%d%d", &n, &m, &f);

    t[0] = t[n - 1] = 0;
    for(int i = 1; i < n - 1; ++i)
    {
        scanf("%d", &t[i]);
    }

    memset(dis1, 0x3f, sizeof(dis1));
    for(int i = 0; i < m; ++i)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        dis1[a - 1][b - 1] = dis1[b - 1][a - 1] = c;
    }
    floyd_warshall(n, dis1);

    memset(dis2, 0x3f, sizeof(dis2));
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(dis1[i][j] <= f) dis2[i][j] = t[i];
        }
    }
    floyd_warshall(n, dis2);

    if(dis2[0][n - 1] < inf) printf("%d\n", dis2[0][n - 1]);
    else printf("-1\n");

    return 0;
}
