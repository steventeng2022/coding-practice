// 3-周遊列國 | 2021/10/25~2021/10/29 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202110/Travel.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202110/Travel.zip
#include <bits/stdc++.h>
#include <stdio.h>
#include <vector>

inline int min(int a, int b) {
    return a < b ? a : b;
}

struct SCC {

    int N;
    std::vector<std::vector<int>> edge;
    std::vector<int> scc, visit, low, in_stack, stack;
    int scc_no, t, top;

    void init(int _N) {
        N = _N;
        edge.clear(), edge.resize(N);
        scc.clear(), visit.clear(), low.clear(), in_stack.clear(), stack.clear();
        scc_no = t = top = 0;
    }

    void add_edge(int a, int b) {
        edge[a].push_back(b);
    }

    const std::vector<int>& slove() {
        scc.clear(), scc.resize(N);
        visit.clear(), visit.resize(N);
        low.clear(), low.resize(N);
        in_stack.clear(), in_stack.resize(N);
        stack.clear(), stack.resize(N);
        scc_no = t = top = 0;
        for (int i = 0; i < N; ++i) {
            if (!visit[i]) {
                _scc_dfs(i);
            }
        }
        return scc;
    }

    void _scc_dfs(int i) {
        visit[i] = low[i] = ++t;
        stack[top++] = i, ++in_stack[i];
        for (int j : edge[i]) {
            if (!visit[j]) {
                _scc_dfs(j);
            }
            if (in_stack[j]) {
                low[i] = min(low[i], low[j]);
            }
        }
        if (visit[i] == low[i]) {
            int j;
            do {
                j = stack[--top];
                in_stack[j] = 0;
                scc[j] = scc_no;
            } while(j != i);
            ++scc_no;
        }
    }

};

struct Chain {

    int N;
    std::vector<std::vector<int>> edge;
    std::vector<int> visit, count;

    void init(int _N) {
        N = _N;
        edge.clear(), edge.resize(N);
        visit.clear(), count.clear();
    }

    void add_edge(int a, int b) {
        edge[a].push_back(b);
    }

    bool check(int start_from) {
        visit.clear(), visit.resize(N);
        count.clear(), count.resize(N);
        return _check_dfs(start_from) == N;
    }

    int _check_dfs(int i) {
        ++visit[i];
        int m = 0;
        for (int j : edge[i]) {
            if (!visit[j]) {
                _check_dfs(j);
            }
            if (m < count[j]) {
                m = count[j];
            }
        }
        count[i] = m+1;
        return count[i];
    }

};

int main() {

    SCC scc;
    int N, M;

    scanf("%d%d", &N, &M);

    scc.init(N);
    while (M--) {
        int a, b;
        scanf("%d%d", &a, &b);
        scc.add_edge(a-1, b-1);
    }

    const std::vector<int> &scc_group = scc.slove();

    Chain chain;
    chain.init(scc.scc_no);
    for (int i = 0; i < N; ++i) {
        for (int j : scc.edge[i]) {
            chain.add_edge(scc_group[i], scc_group[j]);
        }
    }

    if (chain.check(scc_group[0])) {
        puts("Yes");
    }
    else {
        puts("No");
    }

}
