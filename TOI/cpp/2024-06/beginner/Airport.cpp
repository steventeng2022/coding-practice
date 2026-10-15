// 2-機場 | 2024/06/17~2024/06/21 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202406/Airport.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202406/Airport.zip
#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    string target_airport;
    cin >> target_airport;
    int n;
    cin >> n;
    map<string, string> airports;
    cin.ignore();
    for (int i = 0; i < n; ++i)
    {
        string str;
        getline(cin, str);
        string IATA_code = str.substr(0, 3);
        string airport_name = str.substr(4);

        airports[IATA_code] = airport_name;
    }
    cout << airports[target_airport] << endl;
}
