// 2-滑雪場 | 2025/03/17~2025/03/21 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202503/Ski.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202503/Ski.zip
#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int minK, maxK;
    cin >> minK >> maxK;
    vector<int> nums(N);
    for(auto &i:nums) cin >> i;

    int st = 0, minInd = -1, maxInd = -1;
    long long int ans = 0;
    for(int i=0;i<nums.size();++i)
    {
        if(nums[i]<minK || nums[i]>maxK)
        {
            minInd = -1;
            maxInd = -1;
            st = i+1;
        }
        if(nums[i]==minK)
            minInd = i;
        if(nums[i]==maxK)
            maxInd = i;
        if(minInd>=0 && maxInd>=0)
        {
            ans += min(minInd,maxInd)-st+1;
        }
    }
    cout << ans << endl;
}
