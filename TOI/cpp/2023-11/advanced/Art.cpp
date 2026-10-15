// 1-公共藝術 | 2023/11/20~2023/11/24 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202311/Art.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202311/Art.zip
#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<string>
#include<queue>
using namespace std;

int main()
{
    int H, W;
    cin >> H >> W;
    vector<string> table(H);
    for(int i=0; i<H; ++i)
        cin >> table[i];
    int K;
    cin >> K;

    vector<int> ans(K);
    queue<pair<int,int>> bfs;
    for(int i=0; i<H; ++i)
    {
        for(int j=0; j<W; ++j)
        {
            if(table[i][j]=='-')
            {
                bfs.push(make_pair(i, j));
            }
        }
    }
    constexpr int dirs[5] = {0, -1, 0, 1, 0};
    int steps = 0;
    while(!bfs.empty())
    {
        int siz = bfs.size();
        for(int k=0; k<siz; ++k)
        {
            int x = bfs.front().first;
            int y = bfs.front().second;
            bfs.pop();
            for(int d=0; d<4; ++d)
            {
                int new_x = x + dirs[d];
                int new_y = y + dirs[d+1];
                if(new_x < H && new_x >= 0 && new_y < W && new_y >= 0 && table[new_x][new_y]=='*')
                {
                    table[new_x][new_y] = '-';
                    bfs.push(make_pair(new_x, new_y));
                    ans[steps] += 1;
                }
            }
        }
        steps += 1;
        if(steps==K)steps = 0;
    }
    for(auto &i: ans)
        cout << i << ' ';

    return 0;
}
