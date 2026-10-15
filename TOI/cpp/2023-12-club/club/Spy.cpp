// 間諜 | 2023/12 新手同好會 | 新手同好會
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202312-OFFLINE/Spy.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202312-OFFLINE/Spy.zip
// 編譯修正：將無法初始化的變長陣列改為等價的零初始化 vector<array<int,26>>。
#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

bool cmp(int feq1[26], int feq2[26])
{
    for (int i = 0; i < 26; ++i)
    {
        if (feq1[i] != feq2[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int N;
    cin >> N;
    vector<array<int,26>> word_feq(N), col_feq(N);
    string S[N];
    for (int i = 0; i < N; ++i)
    {
        cin >> S[i];
        for (size_t l = 0; l < S[i].length(); ++l)
        {
            word_feq[i][S[i][l] - 'a']++;
            if (l < N)
            {
                col_feq[l][S[i][l] - 'a']++;
            }
        }
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (cmp(word_feq[i].data(), col_feq[j].data()))
            {
                cout << S[i] << endl;
            }
        }
    }
}
