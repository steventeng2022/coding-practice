// 3-整數分拆 | 2025/09/29~2025/10/03 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202509/partition.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202509/partition.zip
#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

constexpr int MOD = 1000000007;
long long int ThreePow(long long int exp)
{
    if(exp==0) return 1;
    else if(exp==1) return 3;
    long long int half = ThreePow(exp/2);
    long long int val = (exp&1) ? 3 : 1;
    return (val * half * half) % MOD;
}
long long int Solve(long long int K)
{
    long long int res = K;
    if(K>=3)
    {
        long long int exp = K/3;
        long long int rem = K%3;
        if(rem==0) res = ThreePow(exp);
        else if(rem==1) res = 4 * ThreePow(exp-1);
        else res = 2 * ThreePow(exp);
    }
    return res % MOD;
}

int main()
{
    int T;
    cin >> T;
    while(T)
    {
        --T;
        long long int K = 0;
        cin >> K;
        cout << Solve(K) << endl;
    }
}
