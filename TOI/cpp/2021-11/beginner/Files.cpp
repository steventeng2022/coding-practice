// 1-檔案分類 | 2021/11/29~2021/12/03 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202111/Files.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202111/Files.zip
#include <bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    int N;
    cin>>N;

    int file[101]={};
    for(int i = 0; i < N; i++)
    {
        int s;
        cin>>s;
        int cls = (s % 1000) / 10;
        file[cls] += 1;
    }
    for(int i = 0; i < 100; i++)
    {
        if(file[i] != 0)
        {
            cout << i << " " << file[i] <<endl;
        }
    }
}
