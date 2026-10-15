// 1-加密系統 | 2025/03/17~2025/03/21 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202503/Encryption.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202503/Encryption.zip
#include <bits/stdc++.h>
#include<iostream>
using namespace std;

int main()
{
    int Q;
    cin >> Q;
    while(Q--)
    {
        int a, b;
        cin >> a >> b;
        if(a==b) cout << "0 0\n";
        else
        {
            int g = a-b;
            cout << g << ' ';
            int k = 2;
            while(g>=k)
            {
                k *= 2;
            }
            k /= 2;
            int t = a-b-k;
            cout <<  k-t << endl;
        }
    }
}
