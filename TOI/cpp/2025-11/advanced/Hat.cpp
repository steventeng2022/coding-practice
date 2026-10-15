// 1-巫師帽 | 2025/11/10~2025/11/14 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202511/Hat.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202511/Hat.zip
#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> cnt(1005, 0);
    for(int i=0; i<N; ++i)
    {
        int num;
        cin >> num;
        cnt[num] += 1;
    }
    int ans = 0;
    for(int i=0; i<1002; ++i)
    {
        if(cnt[i]!=0)
        {
            if(cnt[i]%(i+1)!=0)
                cnt[i] += (i+1)-cnt[i]%(i+1);
        }
        ans += cnt[i];
    }
    cout << ans << endl;
    return 0;
}
