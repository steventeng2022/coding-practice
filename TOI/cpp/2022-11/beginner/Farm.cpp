// 1-開心農場 | 2022/11/28~2022/12/02 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202211/Farm.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202211/Farm.zip
#include <bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    int N;
    cin >> N;
    int sun[105] = {}, rain[105] = {};
    for(int i=1; i<=N; i++) {
        cin >> rain[i];
        rain[i] += rain[i-1];
    }
    for(int i=1; i<=N; i++) {
        cin >> sun[i];
        sun[i] += sun[i-1];

    }
    int x, y;
    cin >> x >> y;
    int ans = -1;
    for(int i=1; i<=N; i++) {
        if(rain[i] >= x && sun[i] >= y) {
            ans = i + 1;
            break;
        }
    }
    cout << ans << endl;
}
