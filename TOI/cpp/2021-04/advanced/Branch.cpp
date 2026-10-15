// 1-枯枝 | 2021/04/26~2021/04/30 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202104/Branch.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202104/Branch.zip
#include <bits/stdc++.h>
#include <string.h>
#include <stdio.h>
#include <utility>
#include <limits>
#include <vector>

inline long long min(long long a, long long b) {
    return a < b ? a : b;
}

inline long long max(long long a, long long b) {
    return a < b ? b : a;
}

struct DegreeOfDeadBranch {

    std::vector<int> preorder;
    std::vector<std::vector<long long>> dp;

    std::pair<long long, long long> slove(const std::vector<int> &pre) {

        preorder = pre;
        int N = preorder.size();
        long long minimal, maximal = 0;

        dp.resize(N);
        for (int i = 0; i < N; ++i) {
            maximal += preorder[i];
            dp[i].resize(N);
            for (int j = 0; j < N; ++j) {
                dp[i][j] = -1;
            }
            dp[i][i] = preorder[i];
        }

        minimal = dp_min(0, N-1);

        return std::make_pair(minimal, maximal);
    }

    long long dp_min(int l, int r) {

        if (r < l) {
            return 0LL;
        }
        if (dp[l][r] >= 0) {
            return dp[l][r];
        }

        long long minimal = std::numeric_limits<long long>::max();
        for (int m = l; m <= r; ++m) {
            long long lt = dp_min(l+1, m), rt = dp_min(m+1, r);
            long long k = max(lt, rt);
            minimal = min(k, minimal);
        }

        dp[l][r] = minimal + preorder[l];

        return dp[l][r];
    }
};

int main() {

    int N;
    std::vector<int> preorder;

    scanf("%d", &N);
    preorder.resize(N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &preorder[i]);
    }

    DegreeOfDeadBranch ddb;
    std::pair<long long, long long> ans = ddb.slove(preorder);

    printf("%lld %lld\n", ans.first, ans.second);

}
