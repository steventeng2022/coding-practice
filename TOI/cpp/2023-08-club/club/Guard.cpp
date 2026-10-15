// 值班警衛 | 2023/08 新手同好會 | 新手同好會
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202308-OFFLINE/Guard.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202308-OFFLINE/Guard.zip
#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> G(n+1, vector<bool>(n+1, false));

    for(int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        G[u][v] = true;
        G[v][u] = true;
    }
    int ans = 20;
    for(int mask = 0; mask < (1 << (n+1)); ++mask)
    {
        int cnt = 0;
        vector<vector<bool>> visited(n+1, vector<bool>(n+1, false));
        for(int i = 1; i <= n; ++i)
        {
            if(mask & (1 << i))
            {
                ++cnt;
                for(int j = 1; j <= n; ++j)
                {
                    if(G[i][j])
                    {
                        visited[i][j] = true;
                        visited[j][i] = true;
                    }
                }
            }
        }
        bool allVisited = true;
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j <= n; ++j)
            {
                if(G[i][j] && !visited[i][j])
                {
                    allVisited = false;
                }
            }
        }
        if(allVisited)
            ans = (cnt < ans) ? cnt: ans;
    }

    cout << ans << endl;
    return 0;
}
