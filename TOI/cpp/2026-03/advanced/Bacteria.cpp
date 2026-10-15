// 1-細菌繁殖 | 2026/03/16~2026/03/20 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202603/Bacteria.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202603/Bacteria.zip
#include <bits/stdc++.h>

#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

void solve(int m, int n, int k, int t, vector<vector<int>> mat) {
    const int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
    vector<vector<int>> pos(k);
    queue<vector<int>> q;
    vector<int> ans(k, 1);

    for (int r = 0; r < m; ++r) {
        for (int c = 0; c < n; ++c) {
            if (1 <= mat[r][c] && mat[r][c] <= k) {
                pos[mat[r][c] - 1] = vector<int>{r, c};
            }
        }
    }

    for (const auto &v : pos) {
        q.push(v);
    }

    for (int e = 0; e < t && q.size(); ++e) {
        int sz = (int)q.size();
        for (int i = 0; i < sz; ++i) {
            vector<int> v = q.front(); q.pop();
            int r = v[0], c = v[1];
            int who = mat[r][c];

            for (int d = 0; d < 4; ++d) {
                int nr = r + dr[d], nc = c + dc[d];
                if (0 <= nr && nr < m && 0 <= nc && nc < n && mat[nr][nc] == 0) {
                    q.push(vector<int>{nr, nc});
                    mat[nr][nc] = who;
                    ++ans[who - 1];
                }
            }
        }
    }

    for (int i = 0; i < k; ++i) {
        printf("%d%c", ans[i], i == k - 1 ? '\n' : ' ');
    }

    return;
}

int main() {
    int m, n, k, t;
    vector<vector<int>> mat;
    scanf("%d%d%d%d", &m, &n, &k, &t);
    mat.resize(m, vector<int>(n));
    for (auto &col : mat) {
        for (auto &grid : col) {
            scanf("%d", &grid);
        }
    }

    solve(m, n, k, t, mat);
    return 0;
}
