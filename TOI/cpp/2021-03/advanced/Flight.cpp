// 3-航班 | 2021/03/22~2021/03/30 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202103/Flight.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202103/Flight.zip
#include <bits/stdc++.h>
#include <stdio.h>
#include <vector>

struct DisjointSet {
    std::vector<int> f, cnt;

    void init(int N) {
        f.resize(N), cnt.resize(N);
        for (int i = 0; i < N; ++i) {
            f[i] = i, cnt[i] = 1;
        }
    }

    int find(int x) {
        return x != f[x] ? f[x] = find(f[x]) : x;
    }

    int count(int x) {
        return cnt[find(x)];
    }

    void uni(int a, int b) {
        int x = find(a), y = find(b);
        if (x != y) {
            if (cnt[x] < cnt[y]) {
                int tmp = x;
                x = y;
                y = tmp;
            }
            f[y] = x, cnt[x] += cnt[y];
        }
    }
};

struct edge {
    int a, b;
};

struct operation {
    int k, p;
};

int main() {
    int N, M, Q;
    DisjointSet ds;
    std::vector<edge> flight; std::vector<operation> opt; std::vector<int> cancel, ans;

    scanf("%d%d", &N, &M);
    ds.init(N+1), flight.resize(M+1), cancel.resize(M+1);

    for (int m = 1; m <= M; ++m) {
        scanf("%d%d", &flight[m].a, &flight[m].b);
        cancel[m] = 0;
    }

    scanf("%d", &Q);
    opt.resize(Q);

    for (int q = 0; q < Q; ++q) {
        scanf("%d%d", &opt[q].k, &opt[q].p);
        if (opt[q].k == 1) {
            ++cancel[opt[q].p];
        }
    }

    for (int m = 1; m <= M; ++m) {
        if (!cancel[m]) {
            ds.uni(flight[m].a, flight[m].b);
        }
    }

    for (int q = Q-1; q >= 0; --q) {
        int k = opt[q].k, p = opt[q].p;
        if (k == 1) {
            ds.uni(flight[p].a, flight[p].b);
        }
        else {
            ans.push_back(ds.count(p)-1);
        }
    }

    for (int i = ans.size()-1; i >= 0; --i) {
        printf("%d\n", ans[i]);
    }
}
