// 停車場 | 2022/12 新手同好會 | 新手同好會
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202212-OFFLINE/Parking.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202212-OFFLINE/Parking.zip
#include <bits/stdc++.h>
#include<iostream>
using namespace std;

int main()
{
    int S, M, L;
    cin >> S >> M >> L;
    int N;
    cin >> N;
    int ans = 0;
    for(int i=0; i<N; i++) {
        int car;
        cin >> car;
        if(car < 200 && S > 0) {
            ans++;
            S--;
        }
        else if(car < 500 && M > 0) {
            ans++;
            M--;
        }
        else if(L > 0) {
            ans++;
            L--;
        }
    }
    cout << ans << endl;
}
