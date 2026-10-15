// 2-校隊 | 2021/11/29~2021/12/03 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202111/School Team.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202111/School Team.zip
#include <bits/stdc++.h>
#include<cstdio>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n, m, ans = 0;
    vector<pair<int, int>> v;
    scanf("%d%d", &n, &m);
    v.resize(n+m);
    for(int i = 0; i < n + m; ++i) scanf("%d%d", &v[i].first, &v[i].second);
    sort(v.begin(), v.end() ,[](const pair<int, int> &a, const pair<int, int> &b) {
        return a.first - a.second < b.first - b.second;
    });
    for(int i = 0; i < n; ++i) ans += v[i].first;
    for(int i = 0; i < m; ++i) ans += v[n + i].second;
    printf("%d\n", ans);
    return 0;
}
