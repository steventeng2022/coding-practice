// 3-建材 | 2021/11/29~2021/12/03 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202111/Material.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202111/Material.zip
#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>

struct Query {
    int no, l, r;
    bool operator<(const Query &q) const {
        return r < q.r;
    }
};

struct BinaryIndexedTree {

    int N;
    std::vector<int> t;

    static int lowerbit(int x) {
        return x & -x;
    }

    void init(int _N) {
        N = _N;
        t.clear();
        t.resize(N+1);
    }

    void update(int pos, int d) {
        for (++pos; pos <= N; pos += lowerbit(pos)) {
            t[pos] += d;
        }
    }

    int query(int pos) const {
        int count = 0;
        for (++pos; pos > 0; pos -= lowerbit(pos)) {
            count += t[pos];
        }
        return count;
    }
    int query(int l, int r) const {
        return query(r) - query(l-1);
    }

};

struct NumberOfMaterialQuery {

    std::vector<int> material;
    std::vector<Query> queries;

    void init(const std::vector<int> &m) {
        material = m;
        queries.clear();
    }

    void query(int l, int r) {
        queries.push_back({(int)queries.size(), l, r});
    }

    std::vector<int> offlineQueryByBinaryIndexedTree() {

        BinaryIndexedTree bit;
        std::vector<int> mark(material.size()+1, -1), ans(queries.size());

        bit.init(material.size());
        std::sort(queries.begin(), queries.end());

        for (int i = 0, q = 0; i < material.size(); ++i) {
            const int material_type = material[i];
            if (mark[material_type] >= 0) {
                bit.update(mark[material_type], -1);
            }
            mark[material_type] = i;
            bit.update(mark[material_type], 1);
            for (; q < queries.size() && queries[q].r <= i; ++q) {
                ans[queries[q].no] = bit.query(queries[q].l, queries[q].r);
            }
        }

        return ans;

    }

};

int main() {

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, Q;
    NumberOfMaterialQuery nmq;

    std::cin >> N;
    std::vector<int> m(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> m[i];
    }
    nmq.init(m);

    std::cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int l, r;
        std::cin >> l >> r;
        nmq.query(l-1, r-1);
    }

    std::vector<int> ans(nmq.offlineQueryByBinaryIndexedTree());
    for (int i = 0; i < ans.size(); ++i) {
        std::cout << ans[i] << '\n';
    }

}
