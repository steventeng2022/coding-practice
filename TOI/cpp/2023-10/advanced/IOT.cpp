// 3-物聯網裝置 | 2023/10/23~2023/10/27 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202310/IOT.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202310/IOT.zip
#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

constexpr int SIZE = 4;
constexpr int mod = 1000000007;
void multi(long long int matrix[][SIZE],long long int vec[SIZE], int n)
{
    if(n&1)
    {
        long long int vt[SIZE]={0};
        for(int i=0;i<SIZE;++i)
            for(int j=0;j<SIZE;++j)
                vt[i]+=vec[j]*matrix[i][j];
        for(int i=0;i<SIZE;++i)
            vec[i]=vt[i]%mod;
    }
    //------------------------------------------------------
    long long int tmp[SIZE][SIZE]={0};
    for(int i=0;i<SIZE;++i)
        for(int j=0;j<SIZE;++j)
            for(int k=0;k<SIZE;++k)
                tmp[i][j]+=matrix[i][k]*matrix[k][j];
    for(int i=0;i<SIZE;++i)
        for(int j=0;j<SIZE;++j)
            matrix[i][j]=tmp[i][j]%mod;
}

int main()
{
    long long int N;
    cin >> N;
    {
        long long int base[SIZE] = {1, 2, 4, 8};
        if(N<SIZE)
            cout << base[N] << endl;
        else
        {
            N -= 3;
            long long int matrix[SIZE][SIZE]={0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1};
            while(N)
            {
                multi(matrix, base, N);
                N = N >> 1;
            }
            cout << base[3] << endl;
        }
    }
    return 0;
}
