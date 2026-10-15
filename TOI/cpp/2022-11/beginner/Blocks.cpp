// 3-積木對接 | 2022/11/28~2022/12/02 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202211/Blocks.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202211/Blocks.zip
#include <bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    int N, M;
    int blkA[2001] = {}, blkB[2001] = {};
    cin >> N;
    int indA = 0;
    int type = 1;
    for(int i=0; i<2*N+1; i++) {
        int A;
        cin >> A;
        for(int j=indA; j<indA+A; j++) {
            blkA[j] = type;
        }
        indA += A;
        type = -type;
    }

    cin >> M;
    int indB = 0;
    type = -1;
    for(int i=0; i<2*M-1; i++) {
        int B;
        cin >> B;
        for(int j=indB; j<indB+B; j++) {
            blkB[j] = type;
        }
        indB += B;
        type = -type;
    }
    bool ans = false;
    for(int i=0; i+indB <= indA; i++) {
        bool check = true;
        for(int j=0; j<indB; j++) {
            if(blkA[i+j] == -1 && blkB[j] == -1) {
                check = false;
                break;
            }
        }
        if(check) {
            ans = true;
            break;
        }
    }
    if(ans) cout << "YES\n";
    else cout << "NO\n";
}
