// 2-YouTube 頻道 | 2021/04/26~2021/04/30 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202104/YouTube.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202104/YouTube.zip
#include <bits/stdc++.h>
#include <stdio.h>
#include <vector>
#include <queue>

struct lt {
    bool operator()(long long a, long long b) const {
        return a > b;
    }
};

struct YTchannel {

    std::priority_queue<long long, std::vector<long long>, lt> live;
    long long total_reduce, total_live;

    void init() {
        total_reduce = 0;
        total_live = 0;
        while (live.size()) {
            live.pop();
        }
    }

    void add_live(int v) {
        live.push(v + total_reduce);
        total_live += v;
    }

    void daily_reduce(int d) {
        while (live.size() && live.top() <= total_reduce + d) {
            total_live -= live.top() - total_reduce;
            live.pop();
        }
        total_reduce += d;
        total_live -= d * live.size();
    }

    long long popularity() {
        return total_live;
    }

};

int main() {

    int D;
    YTchannel channel;

    channel.init();
    scanf("%d", &D);
    for (int i = 0; i < D; ++i) {
        int v, d;
        scanf("%d%d", &v, &d);
        channel.daily_reduce(d);
        channel.add_live(v);
        printf("%lld\n", channel.popularity());
    }

}
