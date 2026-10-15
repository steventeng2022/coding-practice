// 1-美味漢堡 | 2021/10/25~2021/10/29 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202110/Hamburger.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202110/Hamburger.zip
#include <bits/stdc++.h>

#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    int n, k, cur, ans=0;
    vector<int> s, w;
    scanf("%d%d", &n, &k);
    s.resize(n); w.resize(n);
    for(int i=0; i<n; ++i) scanf("%d", &s[i]);
    for(int i=0; i<n; ++i) scanf("%d", &w[i]);
    cur=s[0];
    for(int i=1; i<n; ++i)
    {
        if(w[i]!=w[i-1])
        {
            ans+=cur;
            cur=0;
        }
        cur=max(cur, s[i]);
    }

    ans+=cur;
    printf("%d\n", ans);
    return 0;
}
