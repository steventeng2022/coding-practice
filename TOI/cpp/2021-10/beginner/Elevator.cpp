// 2-電梯 | 2021/10/25~2021/10/29 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202110/Elevator.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202110/Elevator.zip
#include <bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    int N;
    cin >> N;
    int elavator[5005] = {};
    elavator[0] = 1;
    for(int i = 1; i <= N; i++)
    {
        cin >> elavator[i];
    }

    int price = 0;
    for(int i = 1; i <= N; i++)
    {
        if(elavator[i] > elavator[i-1])
        {
            price += (elavator[i] - elavator[i-1])*3;
        }
        else
        {
            price += (elavator[i-1] - elavator[i])*2;
        }
    }
    cout << price << endl;

}
