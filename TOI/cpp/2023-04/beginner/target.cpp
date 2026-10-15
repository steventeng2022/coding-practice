// 3-打靶 | 2023/04/24~2023/04/28 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202304/target.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202304/target.zip
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    int N, S, F;
    cin >> N >> S >> F;
    int tar[4000];
    bool num[10005] = {};
    for(int i=0; i<N; i++) {
        cin >> tar[i];
    }
    int cnt = 0;
    int prev = INT_MAX;
    for(int i=0; i<N; i++) {
        if(num[tar[i]]) {
            num[tar[i]] = false;
            if(tar[i] == F && S == 1) {
                cnt = prev;
                break;
            }
        }
        else {
            num[tar[i]] = true;
            cnt++;
        }
        if(tar[i] == F) {
            prev = cnt;
            S--;
        }
        if(S == 0) break;
    }
    cout << cnt << endl;
}
