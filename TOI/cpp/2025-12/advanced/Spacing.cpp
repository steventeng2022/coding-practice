// 1-棟距 | 2025/12/22~2025/12/26 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202512/Spacing.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202512/Spacing.zip
#include <bits/stdc++.h>

#include<cstdio>
#include<stack>
using namespace std;

void solve(int n, int m, const int *h, const int *l, int *ans)
{
    stack<int> stk;
    int *res = new int[n];
    for (int i = 0; i < n; ++i)
    {
        while (stk.size() && h[stk.top()] < h[i])
        {
            stk.pop();
        }
        res[i] = stk.empty() ? n : i - stk.top();
        stk.push(i);
    }

    while (stk.size()) stk.pop();

    for (int i = n - 1; i >= 0; --i)
    {
        while (stk.size() && h[stk.top()] < h[i])
        {
            stk.pop();
        }
        res[i] = min(res[i], stk.empty() ? n : stk.top() - i);
        stk.push(i);
    }

    for (int i = 0; i < m; ++i)
    {
        ans[i] = res[l[i]];
    }

    delete [] res;

    return;
}

int main()
{
    int n, m;
    int *h, *l, *ans;

    scanf("%d%d", &n, &m);

    h = new int[n];
    l = new int[m];
    ans = new int[m];

    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &h[i]);
    }

    for (int i = 0; i < m; ++i)
    {
        scanf("%d", &l[i]);
    }

    solve(n, m, h, l, ans);
    for (int i = 0; i < m; ++i)
    {
        printf("%d%c", ans[i], i == m - 1 ? '\n' : ' ');
    }

    delete [] h;
    delete [] l;
    delete [] ans;

    return 0;
}
