// 3-凱撒密碼 | 2024/12/23~2024/12/27 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202412/Cipher.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202412/Cipher.zip
#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    getline(cin, str);
    int k;
    cin >> k;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = (str[i] - 'A' + k) % 26 + 'A';
        }
        else if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = (str[i] - 'a' + k) % 26 + 'a';
        }
    }
    cout << str << endl;
}
