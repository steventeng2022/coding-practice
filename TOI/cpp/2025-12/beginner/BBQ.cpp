// 1-串燒 | 2025/12/22~2025/12/26 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202512/BBQ.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202512/BBQ.zip
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    int N, M, in;
    cin >> N >> M;
    int cnt[100] = {0}, order[100] = {0};
    for (int i = 0; i < N; ++i)
    {
        cin >> in;
        cnt[in - 1]++;
    }

    int ordernum;
    for (int i = 0; i < M; ++i)
    {
        cin >> ordernum;
        for (int j = 0; j < ordernum; ++j)
        {
            cin >> in;
            order[in - 1]++;
        }
    }

    int over = 0, less = 0;
    for (int i = 0; i < 100; ++i)
    {
        if (order[i] > cnt[i])
            less += order[i] - cnt[i];
        else
            over += cnt[i] - order[i];
    }

    cout << less << " " << over << endl;
}
