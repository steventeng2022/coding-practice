// 2-釣魚 | 2022/01/03~2022/01/07 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202112/Fishing.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202112/Fishing.zip
#include <bits/stdc++.h>
#include <functional>
#include <iostream>
#include <vector>
#include <cmath>

inline double min(double a, double b) {
    return a < b ? a : b;
}

struct Fishing {

    static constexpr double ESP = 1e-12;

    std::vector<double> friend_excitation_rate;

    Fishing(const std::vector<int> &f) : friend_excitation_rate(f.size()) {
        for (int i = 0; i < (int)friend_excitation_rate.size(); ++i) {
            friend_excitation_rate[i] = min(log2(f[i]+1), 30.0) / 30.0;
        }
    }

    bool can_fish(int init_patience, int prediction) const {
        int total_fish = init_patience;
        if (total_fish >= prediction) {
            return true;
        }
        for (int i = 0; i < (int)friend_excitation_rate.size(); ++i) {
            init_patience = (int)(init_patience * friend_excitation_rate[i] + ESP);		// fixed floating-point error
            if (init_patience == 0) {
                break;
            }
            total_fish += init_patience;
            if (total_fish >= prediction) {
                return true;
            }
        }
        return total_fish >= prediction;
    }

};

struct Search {

    static int binary_search(int low, int high, std::function<bool(int)> judge) {
        while (low < high) {
            int mid = low + ((high - low) / 2);		// avoid arithmetic overflow
            if (judge(mid)) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }

};

int main() {

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<int> F(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> F[i];
    }

    int Q;
    std::cin >> Q;

    Fishing fishing(F);
    while (Q--) {
        int K;
        std::cin >> K;
        std::cout << Search::binary_search(1, K, [&](int g) { return fishing.can_fish(g, K); }) << '\n';
    }

}
