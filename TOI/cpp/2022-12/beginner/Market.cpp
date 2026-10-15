// 3-賣場設置 | 2022/12/26~2022/12/30 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202212/Market.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202212/Market.zip
#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main()
{
    string S, T;
    cin >> S >> T;
    int cnt[26] = {};
    int num[26] = {};
    int len = S.size();
    for(int i=0; i<len; i++) {
        S[i] = tolower(S[i]);
        cnt[S[i] - 'a'] ++;
        num[S[i] - 'a'] += T[i] - '0';
    }
    for(int i=len-1; i>=0; i--) {
        int idx = S[i] - 'a';
        T[i] = (num[idx] / cnt[idx]) + '0';
        if(num[idx] % cnt[idx] > 0) {
            T[i] += 1;
            num[idx] --;
        }
    }
    cout << T << endl;
}
