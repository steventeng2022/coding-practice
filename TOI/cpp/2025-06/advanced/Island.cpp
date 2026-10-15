// 1-島嶼 | 2025/06/09~2025/06/13 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202506/Island.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202506/Island.zip
#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<utility>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> board(N, vector<int>(M));
    queue<pair<int,int>> first_island, bfs;
    for(int i=0; i<N; ++i)
    {
        for(int j=0; j<M; ++j)
        {
            cin >> board[i][j];
            if(board[i][j]==1 && first_island.empty())
            {
                first_island.push({i, j});
                board[i][j] = -1;
            }
        }
    }

    constexpr int DIR = 4;
    constexpr int bias[DIR+1] = {0, 1, 0, -1, 0};
    while(!first_island.empty())
    {
        int x = first_island.front().first;
        int y = first_island.front().second;
        first_island.pop();
        bfs.push({x, y});
        for(int d=0; d<DIR; ++d)
        {
            int new_x = x + bias[d];
            int new_y = y + bias[d+1];
            if(new_x>=0 && new_x<N && new_y>=0 && new_y<M && board[new_x][new_y]==1)
            {
                board[new_x][new_y] = -1;
                first_island.push({new_x, new_y});
            }
        }
    }

    int dist = 0;
    bool found = false;
    while(!bfs.empty() && !found)
    {
        ++dist;
        int K = bfs.size();
        while(K && !found)
        {
            --K;
            int x = bfs.front().first;
            int y = bfs.front().second;
            bfs.pop();
            for(int d=0; d<DIR; ++d)
            {
                int new_x = x + bias[d];
                int new_y = y + bias[d+1];
                if(new_x>=0 && new_x<N && new_y>=0 && new_y<M)
                {
                    if(board[new_x][new_y]==1)
                    {
                        found = true;
                        break;
                    }
                    else if(board[new_x][new_y]==0)
                    {
                        board[new_x][new_y] = -1;
                        bfs.push({new_x, new_y});
                    }
                }
            }
        }
    }
    if(found) cout << dist-1 << endl;
    else cout << -1 << endl;
}
