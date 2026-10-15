// 1-捕魚 | 2022/03/28~2022/04/01 | 新手組
// 題目：http://toi/wp-content/uploads/question/202203/Fishing.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202203/Fishing.zip
#include <bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    int X, Y;
    cin >> X >> Y;
    int N;
    cin >> N;
    int min_dis = 999999999;
    int min_x, min_y;
    for(int i=0; i<N; i++)
    {
        int a, b;
        cin >> a >> b;
        int dis = (X - a) * (X - a)+(Y - b) * (Y - b);
        if(dis < min_dis)
        {
            min_dis = dis;
            min_x = a;
            min_y = b;
        }
    }
    cout << min_x << " " << min_y << endl;
}
