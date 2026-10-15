// 3-聚寶盆 | 2023/12/25~2023/12/29 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202312/TreasureBowl.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202312/TreasureBowl.zip
#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<utility>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> data(N);
    for(int i=0;i<N;++i)
    {
        cin >> data[i];
    }

    sort(data.begin(), data.end(), greater<int>());
    long long int ans = 0;
    long long int sum = 0;
    for(int i=0; i<N; ++i)
    {
        long long int t = ans + sum + data[i]*2;
        if(t<ans)
            break;
        sum += data[i];
        ans = t;
    }
    cout << ans << endl;
    return 0;
}
