// 1-海嘯 | 2021/06/07~2021/06/11 (原定2021 05 月底進行，因應疫情延後) | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202105/Tsunami.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202105/Tsunami.zip
#include <bits/stdc++.h>
#include <vector>
#include <stdio.h>

int main() {

    long long N, K;
    scanf("%lld%lld", &N, &K);

    std::vector<long long> d(N+1), prefix_sum(N+1);
    for (int i = 1; i <= N; ++i) {
        scanf("%lld", &d[i]);
        prefix_sum[i] = d[i] + prefix_sum[i-1];
    }

    long long l = 0, r = prefix_sum[N];
    while (l != r) {
        long long m = (l + r) / 2, count = 0;

        for (int i = 1, j = 1; i <= N; ++i) {
            while (j <= N && prefix_sum[j]-prefix_sum[i-1] <= m) {
                ++j;
            }
            if (prefix_sum[j]-prefix_sum[i-1] > m) {
                count += (N - j + 1);
            }
        }

        if (count < K) {
            r = m;
        }
        else {
            l = m+1;
        }
    }

    printf("%lld\n", l);

}
