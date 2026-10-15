// 2-宴會 | 2022/01/03~2022/01/07 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202112/Banquet.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202112/Banquet.zip
#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    string str[205];

    int max_len = 0;
    for(int i=0; i<N; i++) {
        cin >> str[i];
        if(str[i].size() > max_len) {
            max_len = str[i].size();
        }
    }
    for(int i=0; i<max_len; i++) {
        for(int j=0; j<N; j++) {
            if(str[j].size() <= i) continue;
            if(isalpha(str[j][i])) {
                cout << str[j][i];
            }
        }
    }
    cout << "\n";
}
