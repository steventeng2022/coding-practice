// 3-取貨 | 2023/05/29~2023/06/02 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202305/Pickup.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202305/pickup.zip
#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    string str;
    cin >> str;
    int order = 1;
    map<char, int> m;
    for(int i=str.size()-1; i>=0; i--) {
        if(m.find(str[i]) == m.end()) {
            m[str[i]] = order;
            order++;
        }
    }
    for(map<char, int>::iterator it=m.begin(); it!=m.end(); it++) {
        cout << order - it->second;
    }
    cout << endl;
}
