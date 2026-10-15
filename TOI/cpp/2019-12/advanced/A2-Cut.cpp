// 2-空間切割 | 2019/12/23~2019/12/27 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201912/A2-Cut.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201912/A2-Cut.zip
#include <bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;
long long int DP[105][105] ={0};
int main(){
    for(int i=0;i<=50;i+=1){
        DP[i][0] = 1;
        DP[0][i] = 1;
    }
    for(int i=1;i<=50;i+=1){
        for(int j=1;j<=50;j+=1){
            DP[i][j] = DP[i][j-1] + DP[i-1][j-1];
        }
    }
    int N;
    cin >> N;
    while(N--){
        int D,C;
        cin >> D >> C;
        cout <<DP[D][C] << endl;
    }
}
