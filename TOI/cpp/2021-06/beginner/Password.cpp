// 3-密碼備忘錄 | 2021/06/07~2021/06/11 (原定2021 05 月底進行，因應疫情延後) | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202105/Password.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202105/Password.zip
#include <bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str;
    getline(cin, str);
    int count[26] = {};
    for(int i=0; i<str.size(); i++)
    {
        count[str[i]-'A'] += 1;
    }
    for(int i=100; i>0 ; i--)
    {
        for(int j=0; j<26; j++)
        {
            if(count[j]==i) cout<<(char)(j+'A');
        }
    }
    cout<<endl;
}
