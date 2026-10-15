// 2-外星語 | 2024/12/23~2024/12/27 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202412/Language.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202412/Language.zip
#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

void dbg(int char_exists[], int adjacent_matrix[][130])
{
    cout << "  ";
    for(int i=0; i<128; ++i)
        if(char_exists[i])cout << (char)i << ' ';
    cout << endl;
    for(int i=0; i<128; ++i)
    {
        if(char_exists[i])
        {
            cout << (char)i << ' ';
            for(int j=0; j<128; ++j)
            {
                if(adjacent_matrix[i][j])cout << "@ ";
                else if(char_exists[j]) cout << "  ";
            }
            cout << endl;
        }
    }
}

void dfs(int ind, const int graph[][130], int vis[])
{
    vis[ind] = 0;
    for(int i=0; i<130; ++i)
    {
        if(vis[i] && graph[ind][i])
        {
            dfs(i, graph, vis);
        }
    }
    cout << static_cast<char>(ind);
}
int main()
{
    int N;
    cin >> N;
    vector<string> data(N);
    for(auto &s:data) cin >> s;
    int char_exists[130] = {0};
    int adjacent_matrix[130][130] = {0};
    for(int i=0, ub=N-1; i<ub; ++i)
    {
        int ind = 0;
        const string &s1 = data[i], &s2 = data[i+1];
        int len = min(s1.size(), s2.size());
        while(ind<len)
        {
            if(s1[ind]!=s2[ind])
            {
                char_exists[s1[ind]] = 1;
                char_exists[s2[ind]] = 1;
                adjacent_matrix[s2[ind]][s1[ind]] = 1;
                break;
            }
            ++ind;
        }
    }
    //dbg(char_exists, adjacent_matrix);
    for(int i=0; i<128; ++i)
    {
        if(char_exists[i]) dfs(i, adjacent_matrix, char_exists);
    }
    cout << endl;
    return 0;
}
