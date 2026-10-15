// 3-兔子跳躍 | 2021/10/25~2021/10/29 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202110/Rabbit.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202110/Rabbit.zip
#include <bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    int N, M, D;
    cin >> N >> M >> D;
    if(N > M) swap(N, M);    //N < M

    bool ans = false;
    for(int i=0; i<=(D/N); i++)
    {
        int remain = D-N*i;
        if(remain % M == 0)
        {
            ans=true;
            break;
        }
    }
    if(ans) cout << "YES\n";
    else cout << "NO\n";

}
