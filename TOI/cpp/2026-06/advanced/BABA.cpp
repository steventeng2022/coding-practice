// 3-BABA | 2026/06/8~2026/06/12 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202606/BABA.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202606/BABA.zip
#include <bits/stdc++.h>
#include<iostream>
#include<cassert>
#include<algorithm>
using namespace std;

int main()
{
    constexpr int CHARSET = 3;
    int cnt[CHARSET] = {};
    int total = 0, mx = 0;
    for(int i=0; i<CHARSET; ++i)
    {
        cin >> cnt[i];
        total += cnt[i];
        mx = max(mx, cnt[i]);
    }
    int K;
    cin >> K;
    if((mx-1)/K>total-mx) cout << "No Solution\n";
    else
    {
        char prev = '#';
        int consecutive_count = 0;
        while(total>0)
        {
            total -= 1;
            char flg = '#';
            for(int i=CHARSET-1; i>=0; --i)
            {

                if(prev!='A'+i || consecutive_count<K)
                {
                    int mx = 0;
                    for(int k=0; k<CHARSET; ++k)
                    {
                        mx = max(mx, cnt[k]-(k==i));
                    }
                    if(cnt[i]>0 && (mx-1)/K <= (total-mx))
                    {
                        flg = 'A' + i;
                        break;
                    }
                }
            }
            cout << flg;
            cnt[flg-'A'] -= 1;

            if(flg==prev) consecutive_count += 1;
            else
            {
                prev = flg;
                consecutive_count = 1;
            }
        }
        cout << endl;
    }
}
