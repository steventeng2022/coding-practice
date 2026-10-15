// 2-拍七 | 2023/03/27~2023/03/31 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202303/Seven.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202303/seven.zip
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool iscontain(int num, int b)
{
    while(num != 0)
    {
        if(num % 10 == b) return true;
        num /= 10;
    }
    return false;
}
int main()
{
    int S, E, B, K;
    cin >> S >> E >> B >> K;
    bool ans = false;
    for(int i=S; i<=E; i++)
    {
        if(i % B == 0 || iscontain(i, B)) {
            K--;
        }
        if(K == 0)
        {
            cout << i << endl;
            ans = true;
            break;
        }
    }
    if(!ans) cout << -1 << endl;
}
