// 2-切割板材 | 2024/04/29~2024/05/03 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202404/Plate.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202404/Plate.zip
#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

int Solve(int R, int C, const vector<vector<int>> &values, vector<vector<int>> &dp)
{
    if(dp[R][C]!=-1)return dp[R][C];
    int ans = 0;
    for(int i=1;i<R;++i)
    {
        ans = max( Solve(i,C,values,dp)+Solve(R-i,C,values,dp), ans);
    }
    for(int i=1;i<C;++i)
    {
        ans = max( Solve(R,i,values,dp)+Solve(R,C-i,values, dp), ans);
    }
    if(values[R][C]!=0)ans = max(ans,values[R][C]);

    dp[R][C] = ans;
    return ans;
}

int main()
{
    int R, C;
    cin >> R >> C;
    int N;
    cin >> N;

    vector<vector<int>> values(201, vector<int>(201, 0));
    vector<vector<int>> dp_table(R+1, vector<int>(C+1, -1));
    for(int i=0; i<N; ++i)
    {
        int V, a, b;
        cin >> V >> a >> b;
        values[a][b] = max(values[a][b], V);
        values[b][a] = max(values[b][a], V);
    }
    cout << Solve(R, C, values, dp_table);
    return 0;
}
