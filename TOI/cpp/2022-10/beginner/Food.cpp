// 3-戰備存糧 | 2022/10/24~2022/10/28 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202210/Food.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202210/Food.zip
#include <bits/stdc++.h>
#include<stdio.h>
int main() {
    int N;
    int E;
    while(scanf("%d%d", &N, &E) == 2) {
        if(N == 0 && E == 0) break;
        int total = N*E;
        int i = 1, cur = total, cost = N;
        while(cur > 0) {
            if(cost > 0) {
                cur -= cost;
                cost = N - (total-cur)/E;
            }
            i += 1;
        }
        printf("%d\n", i-1);
    }
    return 0;
}
