// 1-尋寶 | 2022/05/30~2022/06/05 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202205/Treasure.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202205/Treasure.zip
#include <bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    int N;
    cin >> N;
    int treasure[101][101] = {};
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin >> treasure[i][j];
        }
    }

    bool ans = false;
    for(int i=0; i<N; i++)
    {
        int max_num = -1;
        for(int j=0; j<N; j++)
        {
            if(treasure[i][j] > max_num) max_num = treasure[i][j];
        }
        for(int j=0; j<N; j++)
        {
            if(treasure[i][j] == max_num)
            {
                int min_num = 1001;
                for(int k=0; k<N; k++)
                {
                    if(treasure[k][j] < min_num) min_num = treasure[k][j];
                }
                if(treasure[i][j] == min_num)
                {
                    cout << i << " " << j << endl;
                    ans = true;
                    break;
                }
            }
        }
        if(ans) break;
    }
    if(!ans) cout << "NO" << endl;
}
