// 2-卡牌遊戲 | 2022/10/24~2022/10/28 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202210/Cards.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202210/Cards.zip
#include <bits/stdc++.h>
//cards.cpp
#include<cstdio>
#include<vector>
#include<cassert>
#include<algorithm>
const int CARD = 50;
using namespace std;

int main()
{
    int k, n, m;
    vector<vector<int>> next;
    vector<int> gt;
    vector<vector<int>> pos(CARD);
    vector<int> idx(CARD, 0);

    scanf("%d%d%d", &k, &n, &m);

    next.resize(k, vector<int>(CARD, -1));
    gt.resize(k);

    for(int i = 0; i < k; ++i)
    {
        scanf("%d", &gt[i]);
        assert(0 <= gt[i] && gt[i] <= 49);
        pos[gt[i]].emplace_back(i);
    }
    for(int i = 0; i < k; ++i)
    {
        pos[gt[i]].emplace_back(i + k);
    }

    for(int i = 0; i < k; ++i)
    {
        for(int j = 0; j < CARD; ++j)
        {
            while( idx[j] < (int)pos[j].size() && pos[j][idx[j]] <= i) ++idx[j];
            if(idx[j] < (int)pos[j].size()) next[i][j] = pos[j][idx[j]] % k;
            else next[i][j] = -1;
        }
    }

    for(int i = 0; i < n; ++i)
    {
        int no, ptr = -1;
        int round = 0;
        scanf("%d", &no);

        if(gt[0] == no) ptr = 0;
        else ptr = next[0][no];

        for(int j = 1; ptr != -1 && j < m; ++j)
        {
            scanf("%d", &no);
            assert(0 <= no && no <= 49);
            if(ptr >= next[ptr][no] ) ++round;
            ptr = next[ptr][no];
        }

        if(ptr == -1) printf("-1");
        else printf("%d\n", round * k + ptr + 1);
    }
    return 0;
}
