// 1-不便利指數 | 2024/03/18~2024/03/22 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202403/Index%20.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202403/Index%20.zip
#include <bits/stdc++.h>
#include<cstdio>
#include<queue>
using namespace std;

int encode(int n, int r, int c)
{
    return r * n + c;
}

void decode(int n, int id, int& r, int& c)
{
    r = id / n;
    c = id % n;
    return;
}

int solve(int n, int **maze)
{
    int ret = 0;
    queue<int> q;
    int *dis = new int [n * n];
    const int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (maze[i][j] == 1)
            {
                q.push(encode(n, i, j));
                dis[encode(n, i, j)] = 0;
            }
            else
            {
                dis[encode(n, i, j)] = -1;
            }
        }
    }

    while (q.size())
    {
        int u = q.front(); q.pop();
        int r, c;

        decode(n, u, r, c);

        ret = max(ret, dis[u]);

        for (int k = 0; k < 4; ++k)
        {
            int nr = r + dr[k], nc = c + dc[k];
            if (0 <= nr && nr < n && 0 <= nc && nc < n && maze[nr][nc] != -1 && dis[encode(n, nr, nc)] == -1)
            {
                q.push(encode(n, nr, nc));
                dis[encode(n, nr, nc)] = dis[encode(n, r, c)] + 1;
            }
        }
    }

    delete [] dis;

    return ret;
}

int main()
{
    int n;

    scanf("%d", &n);

    int **maze = new int* [n];

    for (int i = 0; i < n; ++i)
    {
        maze[i] = new int[n];
        for (int j = 0; j < n; ++j)
        {
            scanf("%d", &maze[i][j]);
        }
    }

    int ans = solve(n, maze);

    printf("%d\n", ans);

    for (int i = 0; i < n; ++i)
    {
        delete [] maze[i];
    }
    delete [] maze;

    return 0;
}
