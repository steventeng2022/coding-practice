// 2-角色升級 | 2025/06/09~2025/06/13 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202506/Upgrade.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202506/Upgrade.zip
#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

void EnumerateLeft(unordered_set<long long> &result,
    long long sum, int index, int maxN, const vector<long long> &data)
{
    if(index==maxN)
    {
        result.insert(sum);
    }
    else
    {
        EnumerateLeft(result, sum+data[index], index+1, maxN, data);
        EnumerateLeft(result, sum, index+1, maxN, data);
    }
}
bool EnumerateRight(const unordered_set<long long> &result,
    long long sum, int index, int maxN, const vector<long long> &data)
{
    bool res = false;
    if(index==maxN)
    {
        res = (result.find(-sum)!=result.end());
    }
    else
    {
        res = EnumerateRight(result, sum+data[index], index+1, maxN, data) ||
            EnumerateRight(result, sum, index+1, maxN, data);
    }
    return res;
}
int main()
{
    long long A, D;
    cin >> A >> D;
    int N;
    cin >> N;
    vector<long long> data;
    for(int i=0; i<N; ++i)
    {
        long long uA, uD;
        cin >> uA >> uD;
        data.push_back(uA-uD);
    }
    unordered_set<long long> first_half;
    int half_size = N/2;
    EnumerateLeft(first_half, A-D, 0, half_size, data);
    if( EnumerateRight(first_half, 0, half_size, N, data) )
        cout << "1\n";
    else
        cout << "0\n";
}
