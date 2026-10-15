// 2-作物種植 | 2026/06/8~2026/06/12 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202606/Plant2.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202606/Plant2.zip
#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<stack>
using namespace std;

int locate(int i, int j, int dir,
           const vector<vector<int>> &grid)
{
    int res;
    switch(dir)
    {
    case 0:
        res = grid[i][j];
        break;
    case 1:
        res = grid[j][i];
        break;
    case 2:
        res = grid[grid.size()-i-1][j];
        break;
    case 3:
        res = grid[j][grid[0].size()-i-1];
        break;
    }
    return res;
}

void SolveDirection(const vector<vector<int>> &grid,
                    vector<int> &output, int dir)
{
    int H = grid.size();
    int W = grid[0].size();
    if(dir&1)swap(H, W); //for left-right scan

    vector<int> histogram(W);
    int max_area = 0;
    for(int i=0; i<H; ++i)
    {
        stack<int> mono_increasing_ind;
        mono_increasing_ind.push(-1);
        for(int j=0; j<W; ++j)
        {
            if( locate(i, j, dir, grid)==0)histogram[j] = 0;
            else ++histogram[j];

            while(mono_increasing_ind.top()!=-1 && histogram[mono_increasing_ind.top()]>histogram[j])
            {
                int h = histogram[mono_increasing_ind.top()];
                mono_increasing_ind.pop();
                max_area = max(max_area, h*(j-mono_increasing_ind.top()-1));
            }
            mono_increasing_ind.push(j);
        }

        while(mono_increasing_ind.top()!=-1)
        {
            int h = histogram[mono_increasing_ind.top()];
            mono_increasing_ind.pop();
            max_area = max(max_area, h*(W-mono_increasing_ind.top()-1));
        }
        output[i] = max_area;
    }
}

int main()
{
    int H, W, K;
    cin >> H >> W >> K;
    vector<vector<int>> grid(H, vector<int>(W));
    for(int i=0; i<H; ++i)
        for(int j=0; j<W; ++j)
            cin >> grid[i][j];

    int max_val = 0;
    vector<int> max_top_down_rectangle(H);
    SolveDirection(grid, max_top_down_rectangle, 0);
    if(K==1)
    {
        max_val = max_top_down_rectangle.back();
    }
    else
    {
        vector<int> max_bottom_up_rectangle(H);
        SolveDirection(grid, max_bottom_up_rectangle, 2);

        vector<int> max_left_right_rectangle(W);
        SolveDirection(grid, max_left_right_rectangle, 1);

        vector<int> max_right_left_rectangle(W);
        SolveDirection(grid, max_right_left_rectangle, 3);

        for(int i=0; i<H-1; ++i)
            max_val = max(max_val, max_top_down_rectangle[i] +
                          max_bottom_up_rectangle[H-i-2]);
        for(int i=0; i<W-1; ++i)
            max_val = max(max_val, max_left_right_rectangle[i] +
                          max_right_left_rectangle[W-i-2]);

    }
    cout << max_val << endl;
}
