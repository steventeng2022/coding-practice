// 1-隕石 | 2020/12/28~2021/01/01 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202012/Meteorite.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202012/Meteorite.zip
#include <bits/stdc++.h>
//fast version
#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 100000 + 5, M = 100000 + 5;
typedef long long ll;

int main()
{
    ll ans=0;
    static int n, m, meteorite[N], machine[N];
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; ++i) scanf("%d", &meteorite[i]);
    for(int i=0; i<m; ++i) scanf("%d", &machine[i]);
    sort(meteorite, meteorite+n);
    sort(machine, machine+m);
    for(int i=n-1, j=m-1; i>=0 && j>=0; --i)
    {
        if(meteorite[i]>machine[j]) continue;
        ans += (ll)meteorite[i];
        --j;
    }
    printf("%lld\n", ans);
}
