// 幸運基數 | 2022/12 新手同好會 | 新手同好會
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202212-OFFLINE/Base.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202212-OFFLINE/Base.zip
#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <string>
using namespace std;
typedef long long ll;

int main() {
    ll num;
    cin >> num;
    int m_top = log(num + 1) / log(2);
    ll ans = 0;
    for (int m = m_top; m >= 2; m--) {
        ll low = 2, top = pow(num, (1. / (m - 1))) + 1;

        while (low < top) {
            ll k = (low + top) / 2;

            ll val = 0, x = 1;
            for (int i = 0; i < m; i++) {
                val = val * k + 1;
            }

            if (val > num) {
                top = k;
            }
            else if (val < num) {
                low = k + 1;
            }
            else {
                ans = k;
                break;
            }
        }
        if(ans != 0) break;
    }
    if(ans == 0) cout << num - 1 << endl;
    else cout << ans << endl;
}
