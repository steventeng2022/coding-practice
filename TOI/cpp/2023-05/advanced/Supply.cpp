// 2-糧食便道 | 2023/05/29~2023/06/02 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202305/Supply.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202305/Supply.zip
#include <bits/stdc++.h>
#include <cstdio>
#include <algorithm>
using namespace std;

struct Edge {
    int a, b, c;
    Edge() {}
    Edge(int _a, int _b, int _c) : a(_a), b(_b), c(_c) {}
    bool operator < (const Edge &rhs) const {
        return c < rhs.c;
    }
};

int getfa(int *fa, int u) {
    if (fa[u] == u) {
        return fa[u];
    }
    fa[u] = getfa(fa, fa[u]);
    return fa[u];
}

int main() {
    int n, m, k;
    bool *food = nullptr;
    int *fa = nullptr;
    Edge *edges = nullptr;

    int ans = 0;

    scanf("%d%d%d", &n, &m, &k);

    food = new bool[n + 1];
    fa = new int[n + 1];
    edges = new Edge[m];

    for (int i = 0; i < n; ++i) {
        food[i + 1] = false;
        fa[i + 1] = i + 1;
    }

    for (int i = 0; i < k; ++i) {
        int x;
        scanf("%d", &x);
        food[x] = true;
    }

    for (int i = 0; i < m; ++i) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        edges[i] = (Edge){a, b, c};
    }

    sort(edges, edges + m);

    for (int i = 0; i < m; ++i) {
        int ra = getfa(fa, edges[i].a), rb = getfa(fa, edges[i].b);
        if (ra != rb && (food[ra] == false || food[rb] == false)) {
            ans += edges[i].c;
            if (food[ra] == true) {
                fa[rb] = ra;
            } else {
                fa[ra] = rb;
            }
        }
    }

    printf("%d\n", ans);

    delete [] food;
    delete [] fa;
    delete [] edges;

    return 0;
}
