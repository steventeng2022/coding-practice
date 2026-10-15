// 2-紙膠帶 | 2026/03/16~2026/03/20 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202603/Tape.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202603/Tape.zip
#include <bits/stdc++.h>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

constexpr int CHARSET_SIZE = 26;

int sliding_window(string &tape, int limit[], int scoring)
{
    int frequency[CHARSET_SIZE] = {0};
    int different_chr = 0;
    int max_score = 0;
    int l = 0;
    int N = tape.size();
    for(int r=0; r<N; ++r)
    {
        int k = tape[r]-'a';
        bool violate = false;
        frequency[k] += 1;
        if(frequency[k]==1) different_chr += 1;
        if(frequency[k]>limit[k] && k!=scoring) violate = true;
        while(violate || different_chr>3)
        {
            if(l>=N) break;

            int l_chr = tape[l]-'a';
            frequency[l_chr] -= 1;
            if(frequency[l_chr]==0)different_chr -= 1;
            if(frequency[k]<=limit[k])violate = false;
            ++l;
        }
        if(different_chr==3)
        {
            max_score = max(max_score, frequency[scoring]);
        }
    }
    return max_score;
}

int main()
{
    int N;
    cin >> N;
    int limit[CHARSET_SIZE] = {0};
    for(int i=0; i<CHARSET_SIZE; ++i)
    {
        cin >> limit[i];
    }
    string tape;
    cin >> tape;
    int ans = 0;
    for(int i=0; i<CHARSET_SIZE; ++i)
    {
        ans = max(ans, sliding_window(tape, limit, i));
    }
    cout << ans << endl;
    return 0;
}
