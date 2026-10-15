// 1-駕駛汽車 | 2026/06/8~2026/06/12 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202606/Driving.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202606/Driving.zip
#include <bits/stdc++.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
const int inf = 2147483647;

void input(int &m, int &n, vector<vector<int>> &mat)
{
    scanf("%d%d", &m, &n);
    mat.clear();
    mat.resize(m, vector<int>(n));

    for (vector<int> &row : mat)
    {
        for (int &grid : row)
        {
            scanf("%d", &grid);
        }
    }

    return;
}

class Data {
public:
    Data() {}
    Data(int to, int w) : to(to), w(w) {}
    int to;
    int w;
    bool operator < (const Data &rhs) const {
        return w > rhs.w;
    }
};

bool inRange(int m, int n, int r, int c)
{
    return 0 <= r && r < m && 0 <= c && c < n;
}

int encode(int n, int r, int c, int k)
{
    return r * n * 4 + c * 4 + k;
}

void decode(int id, int n, int &r, int &c, int &k)
{
    k = id % 4;
    id /= 4;
    c = id % n;
    id /= n;
    r = id;
    return;
}

vector<vector<Data>> buildGraph(int m, int n, const vector<vector<int>> &mat)
{
    vector<vector<Data>> g(m * n * 4);

    for (int r = 0; r < m; ++r)
    {
        for (int c = 0; c < n; ++c)
        {
            if (mat[r][c] == -1) continue;

            for (int k = 0; k < 4; ++k)
            {
                int nr = r + dr[k], nc = c + dc[k];

                // Change direction
                for (int nk = 0; nk < 4; ++nk)
                {
                    if (nk == k) continue;
                    g[encode(n, r, c, k)].push_back(Data(encode(n, r, c, nk), 1));
                }

                if (inRange(m, n, nr, nc) && mat[nr][nc] != -1)
                {
                    g[encode(n, r, c, k)].push_back(Data(encode(n, nr, nc, k), mat[nr][nc]));
                }
            }
        }
    }
    return g;
}

int solve_dial(int m, int n, const vector<vector<int>> &mat)
{
    vector<vector<Data>> g = buildGraph(m, n, mat);
    vector<int> dis(m * n * 4, inf);
    vector<queue<Data>> slots;
    int mxDis = 0;
    int pending = 0;
    int ans = -1;

    for (int r = 0; r < m; ++r)
    {
        for (int c = 0; c < n; ++c)
        {
            mxDis = max(mxDis, mat[r][c] + 1);
        }
    }

    slots.resize(mxDis + 1);

    for (int k = 0; k < 4; ++k)
    {
        int id = encode(n, 0, 0, k);
        dis[id] = 0;
        slots[0].push(Data(id, mat[0][0]));
        ++pending;
    }

    for (int curDis = 0; pending; ++curDis)
    {
        while (slots[curDis % slots.size()].size())
        {
            Data cur = slots[curDis % slots.size()].front();
            int curr, curc, curk;

            slots[curDis % slots.size()].pop();
            --pending;

            if (cur.w > dis[cur.to]) continue;

            decode(cur.to, n, curr, curc, curk);

            if (curr == m - 1 && curc == n - 1 && ans == -1)
            {
                ans = cur.w;
            }

            for (const Data &edge : g[cur.to])
            {
                if (dis[edge.to] > dis[cur.to] + edge.w)
                {
                    dis[edge.to] = dis[cur.to] + edge.w;
                    slots[dis[edge.to] % slots.size()].push(Data(edge.to, dis[edge.to]));
                    ++pending;
                }
            }
        }

    }

    return ans;
}

int main()
{
    int m, n;
    vector<vector<int>> mat;
    input(m, n, mat);
    printf("%d\n", solve_dial(m, n, mat));
    return 0;
}
