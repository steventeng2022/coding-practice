// 3-一二三木頭人 | 2022/01/03~2022/01/07 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202112/Freeze.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202112/Freeze.zip
#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <queue>

template<class T>
inline T max(const T &a, const T &b) {
    return a < b ? b : a;
}

struct PrifixSumQuery {

    std::vector<long long> prefix_sum;

    PrifixSumQuery(const std::vector<int> &v) : prefix_sum(v.size()+1, 0LL) {
        for (int i = 1; i < (int)prefix_sum.size(); ++i) {
            prefix_sum[i] = prefix_sum[i-1] + v[i-1];
        }
    }

    long long query(int pos) {
        return prefix_sum[pos+1];
    }

};

struct FixedLengthSlidingWindowMaximum {

    int L, back;
    std::deque<std::pair<int, long long>> deq;

    FixedLengthSlidingWindowMaximum(int l) : L(l), back(0), deq() {}

    void push_back(long long x) {
        if (!deq.empty() && back - deq.front().first >= L) {
            deq.pop_front();
        }
        while (!deq.empty() && x >= deq.back().second) {
            deq.pop_back();
        }
        deq.push_back(std::make_pair(back, x));
        ++back;
    }

    long long query() const {
        return deq.front().second;
    }

};

struct Freeze {

    static long long solve(const std::vector<int> &movement, const int K, const int T) {

        if (movement.size() == 0) {
            return 0LL;
        }

        std::vector<long long> dp(movement.size());
        std::vector<long long> dp_prefix_maximum(movement.size());
        PrifixSumQuery movement_psq(movement);
        FixedLengthSlidingWindowMaximum flswm(T);

        dp[0] = dp_prefix_maximum[0] = movement[0];
        flswm.push_back(-movement_psq.query(0));
        for (int i = 1; i < (int)dp.size(); ++i) {
            long long st_range_maximum_value = 0LL;
            if (i >= T) {
                st_range_maximum_value = flswm.query();
            }
            long long movement_prefix_sum_value = movement_psq.query(i);
            dp[i] = st_range_maximum_value + movement_prefix_sum_value;
            dp_prefix_maximum[i] = max(dp_prefix_maximum[i-1], dp[i]);
            long long dp_prefix_maximum_value = 0LL;
            if (i >= K) {
                dp_prefix_maximum_value = dp_prefix_maximum[i-K];
            }
            flswm.push_back(dp_prefix_maximum_value - movement_psq.query(i));
        }

        return dp_prefix_maximum[dp_prefix_maximum.size()-1];

    }

};

int main() {

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, K, T;
    std::cin >> N >> K >> T;

    std::vector<int> m(N);
    for (int i = 0; i < (int)m.size(); ++i) {
        std::cin >> m[i];
    }

    std::cout << Freeze::solve(m, K, T) << '\n';

}
