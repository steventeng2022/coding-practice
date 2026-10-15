// 2-收納盒 | 2021/10/25~2021/10/29 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202110/Storage Box.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202110/Storage Box.zip
#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>

struct StorageBox {

    static const long long mod = 1000000007LL;

    static long long dp(const std::string &s) {
        std::vector<long long> count(s.size()+1);
        count[0] = 1;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '[') {
                for (int j = count.size()-1; j > 0; --j) {
                    count[j] = count[j-1];
                }
                count[0] = 0;
            }
            else if (s[i] == ']') {
                for (int j = 0; j < count.size()-1; ++j) {
                    count[j] = count[j+1];
                }
                count[count.size()-1] = 0;
            }
            else if (s[i] == '?') {
                std::vector<long long> count_tmp(count.size());
                for (int j = 1; j < count.size()-1; ++j) {
                    count_tmp[j] = (count[j-1]+count[j+1])%mod;
                }
                count_tmp[0] = count[1];
                count_tmp[count.size()-1] = count[count.size()-2];
                count.swap(count_tmp);
            }
        }
        return count[0];
    }

};

int main() {

    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int N;
    std::string s;

    std::cin >> N;
    std::cin >> s;

    std::cout << StorageBox::dp(s) << '\n';

}
