// 2-吃自助餐 | 2026/05/04~2026/05/08 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202605/Buffet.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202605/Buffet.zip
#include <bits/stdc++.h>

#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

int solve(int n, int p, int r, const vector<vector<vector<int>>> &tab) {
    int ans = 0;
    vector<int> globalDP(p + 1, 0);

    for (int i = 0; i < n; ++i) {
        int mi = (int)tab[i].size();
        vector<vector<int>> localDP(r + 1, vector<int>(p + 1, 0));

        copy(globalDP.begin(), globalDP.end(), localDP[0].begin());

        for (int j = 0; j < mi; ++j) {
            int c = tab[i][j][0], d = tab[i][j][1];
            for (int k = min(j, r - 1); k >= 0; --k) {
                for (int l = p; l > 0; --l) {
                    if (l >= c) {
                        localDP[k + 1][l] = max(max(localDP[k + 1][l], localDP[k][l]), localDP[k][l - c] + d);
                    } else {
                        localDP[k + 1][l] = max(localDP[k + 1][l], localDP[k][l]);
                    }
                    ans = max(ans, localDP[k + 1][l]);
                }
            }
        }

        copy(localDP[min(mi, r)].begin(), localDP[min(mi, r)].end(), globalDP.begin());

    }

    return ans;
}

int main() {
    int n, p, r;
    vector<vector<vector<int>>> tab;
    scanf("%d%d%d", &n, &p, &r);
    tab.resize(n);
    for (int i = 0; i < n; ++i) {
        int m;
        scanf("%d", &m);
        tab[i].resize(m, vector<int>(2));
        for (int j = 0; j < m; ++j) {
            scanf("%d%d", &tab[i][j][0], &tab[i][j][1]);
        }
    }

    printf("%d\n", solve(n, p, r, tab));

    return 0;
}
