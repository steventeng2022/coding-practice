// 1-移動盤面 | 2024/06/17~2024/06/21 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202406/Puzzle.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202406/Puzzle.zip
#include <bits/stdc++.h>
//puzzle.cpp
#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
#include<cmath>
const int maxm = 5, maxn = 5;
const int inf = (1 << 30);
using namespace std;

class Object{
public:
    int r0, c0;
    int r1, c1;
    Object() : r0(inf), c0(inf), r1(-inf), c1(-inf) {}
};

vector<Object> parseObject(const int maze[maxm][maxn], int m, int n, int k)
{
    vector<Object> ret(k);
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int label = maze[i][j];
            if (label > 0)
            {
                ret[label - 1].r0 = min(ret[label - 1].r0, i);
                ret[label - 1].c0 = min(ret[label - 1].c0, j);
                ret[label - 1].r1 = max(ret[label - 1].r1, i);
                ret[label - 1].c1 = max(ret[label - 1].c1, j);
            }
        }
    }
    for (int i = 0; i < k; ++i)
    {
        //printf("color = %d, (%d, %d) to (%d, %d)\n", i + 1, ret[i].r0, ret[i].c0, ret[i].r1, ret[i].c1);
    }
    return ret;
}

int encode(vector<Object>& objs, int m, int n, int k)
{
    int ret = 0;
    for (int i = 0; i < k; ++i)
    {
        int v = objs[i].r0 * n + objs[i].c0;
        ret = ret * m * n + v;
    }
    return ret;
}

vector<Object> moveObject(const vector<Object>& objs, int m, int n, int k, int dir, int idx)
{
    vector<Object> ret = objs;
    const int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};

    ret[idx].r0 += dr[dir];
    ret[idx].c0 += dc[dir];
    ret[idx].r1 += dr[dir];
    ret[idx].c1 += dc[dir];
    if (ret[idx].r0 < 0 || ret[idx].r1 >= m || ret[idx].c0 < 0 || ret[idx].c1 >= n)
    {
        //printf("dir = %d, idx = %d, (%d, %d), (%d, %d) out of range\n", dir, idx, ret[idx].r0, ret[idx].c0, ret[idx].r1, ret[idx].c1);
        return vector<Object> {};
    }
    for (int i = 0; i < k; ++i)
    {
        if (i != idx)
        {
            int nr0 = max(ret[i].r0, ret[idx].r0);
            int nc0 = max(ret[i].c0, ret[idx].c0);
            int nr1 = min(ret[i].r1, ret[idx].r1);
            int nc1 = min(ret[i].c1, ret[idx].c1);
            if (nr0 <= nr1 && nc0 <= nc1)
            {
                //printf("dir = %d, idx = %d, nr0 = %d, nc0 = %d, nr1 = %d, nc1 = %d\n", dir, idx, nr0, nc0, nr1, nc1);
                return vector<Object> {};
            }
        }
    }
    return ret;
}

void printMaze(const vector<Object>& objs, int m, int n, int k)
{
    int maze[maxm][maxn] = {0};

    for (int color = 0; color < k; ++color)
    {
        Object o = objs[color];
        for (int i = o.r0; i <= o.r1; ++i)
        {
            for (int j = o.c0; j <= o.c1; ++j)
            {
                maze[i][j] = color + 1;
            }
        }
    }
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            printf("%d%c", maze[i][j], j == n - 1 ? '\n' : ' ');
        }
    }

    return;
}

int solve(const int maze0[maxm][maxn], const int maze1[maxm][maxn], int m, int n, int k)
{
    vector<Object> src = parseObject(maze0, m, n, k), dst = parseObject(maze1, m, n, k);
    int sid = encode(src, m, n, k), tid = encode(dst, m, n, k);
    queue<pair<vector<Object>, int>> q;
    vector<int> dis((size_t)pow((double)(m * n), (double)k), inf);
    dis[sid] = 0;
    q.push(make_pair(src, sid));
    //printf("dis.size() = %d\n", (int)dis.size());
    //printf("sid = %d, tid = %d\n", sid, tid);
    while (q.size())
    {
        pair<vector<Object>, int> p = q.front(); q.pop();
        vector<Object> u = p.first;
        int uid = p.second;

        if (uid == tid)
        {
            return dis[uid];
        }

        //printf("uid = %d\n", uid);
        //printMaze(u, m, n, k);

        for (int dir = 0; dir < 4; ++dir)
        {
            for (int idx = 0; idx < k; ++idx)
            {
                vector<Object> v = moveObject(u, m, n, k, dir, idx);
                if (v.size())
                {
                    int vid = encode(v, m, n, k);
                    //printf("dir = %d, idx = %d, vid = %d\n", dir, idx, vid);
                    if (dis[vid] == inf)
                    {
                        dis[vid] = dis[uid] + 1;
                        q.push(make_pair(v, vid));
                    }
                }
            }
        }
    }

    return -1;
}

int main()
{
    int m, n, k;
    int maze0[maxm][maxn], maze1[maxm][maxn];
    scanf("%d%d%d", &m, &n, &k);
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            scanf("%d", &maze0[i][j]);
        }
    }
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            scanf("%d", &maze1[i][j]);
        }
    }
    printf("%d\n", solve(maze0, maze1, m, n, k));
    return 0;
}

/*
4 5 4
0 0 0 0 0
0 1 2 3 4
0 0 0 0 0
0 0 0 0 0

0 0 0 0 0
0 1 2 4 3
0 0 0 0 0
0 0 0 0 0

4 5 4
0 0 0 0 4
0 0 2 2 4
0 1 0 3 3
0 1 0 3 3

0 0 4 0 0
2 2 4 0 1
0 3 3 0 1
0 3 3 0 0

3 3 4
4 0 0
3 1 0
0 1 2

0 0 2
4 3 1
0 0 1

*/
