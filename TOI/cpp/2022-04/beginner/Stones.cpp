// 1-岩石觀察 | 2022/04/25~2022/04/29 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202204/Stones.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202204/Stones.zip
#include <bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    int N;
    cin >> N;
    int stone[105] = {};
    int sum = 0;
    int max_id, min_id;
    int max = -1, min = 105;
    for(int i=0; i<N; i++)
    {
        cin >> stone[i];
        sum += stone[i];
        if(stone[i] > max)
        {
            max = stone[i];
            max_id = i;
        }
        if(stone[i] < min)
        {
            min = stone[i];
            min_id = i;
        }
    }
    int mean = sum / N;
    stone[min_id] += (stone[max_id] - mean);
    stone[max_id] = mean;
    for(int i=0; i<N; i++)
    {
        cout << stone[i];
        if(i != N-1) cout << " ";
        else cout << "\n";
    }
}
