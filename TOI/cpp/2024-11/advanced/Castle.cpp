// 1-積木城堡 | 2024/11/11~2024/11/15 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202411/Castle.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202411/Castle.zip
#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> building_size(N);
    vector<int> building_height(N);
    int max_height = -1;
    for(int i=0; i<N; ++i)
    {
        cin >> building_size[i];
        int height = -1;
        int K = building_size[i];
        for(int j=0; j<K; ++j)
        {
            int s;
            cin >> s;
            height = max(height, s);
        }
        building_height[i] = height;
        if(height>max_height)
            max_height = height;
    }
    long long ans = 0;
    for(int i=0; i<N; ++i)
    {
        ans += (long long)building_size[i] * (max_height-building_height[i]);
    }
    cout << ans << endl;
}
