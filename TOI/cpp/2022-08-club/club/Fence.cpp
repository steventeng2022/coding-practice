// 興建圍籬 | 2022/08 新手同好會 | 新手同好會
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202208-OFFLINE/Fence.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202208-OFFLINE/Fence.zip
#include <bits/stdc++.h>
#include<cstdio>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

int getfa(vector<int> &fa, int x)
{
    if(x == fa[x]) return x;
    return fa[x] = getfa(fa, fa[x]);
}

void combine(vector<int> &fa, int x, int y)
{
    fa[getfa(fa, x)] = getfa(fa, y);
    return;
}

int main()
{
    int h, w;
    vector<int> fa;
    vector<vector<int>> maze;
    unordered_map<int, int> mp;
    vector<int> ans;

    scanf("%d%d", &h, &w);
    fa.resize(h * w);
    maze.resize(h, vector<int>(w));

    for(int i = 0; i < h; ++i) for(int j = 0; j < w; ++j) fa[i * w + j] = i * w + j;

    for(int i = 0; i < h; ++i)
    {
        for(int j = 0; j < w; ++j)
        {
            scanf("%d", &maze[i][j]);
            if(maze[i][j] == 1)
            {
                if(i > 0 && maze[i - 1][j] == 1)
                {
                    combine(fa, (i - 1) * w + j, i * w + j);
                }
                if(j > 0 && maze[i][j - 1] == 1)
                {
                    combine(fa, i * w + (j - 1), i * w + j);
                }
            }
        }
    }

    for(int i = 0; i < h; ++i)
    {
        for(int j = 0; j < w; ++j)
        {
            const int di[] = {-1, 1, 0, 0}, dj[] = {0, 0, -1, 1};
            if(maze[i][j] == 0) continue;
            getfa(fa, i * w + j);
            for(int k = 0; k < 4; ++k)
            {
                int ni = i + di[k], nj = j + dj[k];
                if(0 <= ni && ni < h && 0 <= nj && nj < w && maze[ni][nj] == 0)
                {
                    ++mp[fa[i * w + j]];
                }
            }
        }
    }

    for(const auto &it : mp) ans.emplace_back(it.second);
    sort(ans.begin(), ans.end());

    for(int i = 0; i < (int)ans.size(); ++i)
    {
        printf("%d", ans[i]);
        if(i == (int)ans.size() - 1) printf("\n");
        else printf(" ");
    }

    return 0;
}
