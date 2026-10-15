// 2-書房 | 2023/11/20~2023/11/24 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202311/Study.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202311/Study.zip
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int a[n];
    for(int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    for(int j = 1; j <= m; ++j)
    {
        for(int i = 0; i < n; ++i)
        {
            if(a[i] == j)
            {
                cout << i+1 << " ";
                break;
            }
        }
    }
}
