// 1-庫存清理 | 2023/03/27~2023/03/31 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202303/Stock.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202303/stock.zip
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    int T, S, P;
    cin >> T >> S >> P;
    float dis[5] = {0.5, 0.6, 0.8, 0.9, 0};
    int ans = 0;
    for(int i=0; i<5; i++)
    {
        int cnt = int(T * 0.2);
        if(i == 0) cnt += 1;
        cnt = min(cnt, S);
        ans += int(P * dis[i]) * cnt;
        S -= cnt;
        if(S == 0) break;
    }
    cout << ans << endl;
}
