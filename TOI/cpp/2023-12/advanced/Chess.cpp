// 2-搶地棋 | 2023/12/25~2023/12/29 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202312/Chess.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202312/Chess.zip
#include <bits/stdc++.h>
#include<iostream>
#include<cstdlib>
#include<unordered_map>
using namespace std;

class Solution
{
private:
    const int R, C;
    unordered_map<long long int, int> states;
    constexpr static int dirs[4][2] = { {-1, 2}, {-2, 1}, {1, 2}, {2, 1} };
public:
    Solution(int r, int c): R(r), C(c),states(unordered_map<long long int, int>()){}
    bool Winnable(long long int);
};

constexpr int Solution::dirs[4][2];
constexpr long long int TR = 1;
bool Solution::Winnable(long long int state)
{
    if(states.find(state)!=states.end())
        return states[state];

    bool ans = false ;
    for(int i=0; i<R*C && (ans==false); ++i)
    {
        for(int d=0; d<4 && (ans==false); ++d)
        {
            int x = i/C + dirs[d][0];
            int y = i%C + dirs[d][1];
            if(x<0 || y<0 || x>=R || y>=C)continue;
            int bit = x * C  + y;

            if( (state&(TR<<i))==0 && (state&(TR<<bit))==0 )
            {
                long long int next_state = state | (TR<<i) | (TR<<bit);
                if(this->Winnable(next_state)==false)
                    ans = true;
            }
        }
    }
    states[state] = ans;
    return ans;
}

int main()
{

    int R, C;
    cin >> R >> C;
    Solution sol(R, C);

    long long int state = 0;
    for(int i=0; i<R*C; ++i)
    {
        char flg;
        cin >> flg;
        if(flg=='#')
            state |= (TR<<i);
    }
    if(sol.Winnable(state))
        cout << "Charlie\n";
    else
        cout << "Dave\n";
    return 0;
}
