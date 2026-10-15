// 3-入住旅館 | 2024/11/11~2024/11/15 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202411/CheckIn.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202411/CheckIn.zip
#include <bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

constexpr int MOD = 1000000007;

long long int Solve(const vector<vector<int>> &pascal, const vector<int> &nums)
{
    if(nums.size()<=1)
        return 1;

    vector<int> left;
    vector<int> right;
    for(int i=1;i<nums.size();++i)
    {
        if(nums[i]<nums[0])
            left.emplace_back(nums[i]);
        else
            right.emplace_back(nums[i]);
    }
    long long int ans = 1;
    ans *= Solve(pascal, left);
    ans *= Solve(pascal, right);
    ans %= MOD;
    ans *= pascal[left.size()+right.size()][left.size()];
    return ans % MOD;
}
int main()
{
    //Preprocessing pascal's triangle
    vector<vector<int>> pascal(1001, vector<int>(1001));
    for(int i=0; i<1001; ++i)
    {
        for(int j=0; j<=i; ++j)
        {
            if(0==j || i==j)
                pascal[i][j] = 1;
            else
            {
                pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
                pascal[i][j] %= MOD;
            }
        }
    }
    int N;
    cin >> N;
    vector<int> data(N);
    for(int i=0;i<N;++i)
    {
        cin >> data[i];
    }
    cout << Solve(pascal, data) << '\n';

    return 0;
}
