// 2-比大小 | 2022/04/25~2022/04/29 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202204/Cards.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202204/Cards.zip
#include <bits/stdc++.h>
#include<iostream>
#include<algorithm>

int main()
{
    int X,Y;
    std::cin >> X >> Y;
    int deck_X[100005] = {};
    int deck_Y[100005] = {};
    for(int i=0; i<X; i+=1)
        std::cin >> deck_X[i];
    for(int i=0; i<Y; i+=1)
        std::cin >> deck_Y[i];

    std::sort(deck_X, deck_X+X);
    std::sort(deck_Y, deck_Y+Y);

    long long int win = 0;
    long long int lose = 0;
    long long int tie = 0;

    int X_index = 0;
    int Y_index_head = 0;
    int Y_index_tail = 0;
    int table[100005][2] = {};
    while(X_index<X)
    {
        while(Y_index_tail<Y && deck_Y[Y_index_head] == deck_Y[Y_index_tail])
            Y_index_tail += 1;

        if(deck_X[X_index] < deck_Y[Y_index_head])
        {
            table[X_index][0] = Y_index_head;
            win += Y_index_head;
            table[X_index][1] = Y - Y_index_head;
            lose += Y - Y_index_head;
        }
        else if(deck_X[X_index] == deck_Y[Y_index_head])
        {
            table[X_index][0] = Y_index_head;
            win += Y_index_head;
            table[X_index][1] = Y - Y_index_tail;
            lose += Y - Y_index_tail;

            tie += Y_index_tail - Y_index_head;
        }
        else
        {
            if(Y_index_tail!=Y)
            {
                Y_index_head = Y_index_tail;
                continue;
            }
            else
            {
                table[X_index][0] = Y;
                win += Y;
                table[X_index][1] = 0;
            }
        }
        X_index += 1;
    }

    double win_d = win;
    double lose_d = lose;
    double rate = win_d / (win_d + lose_d);

    int min_card = -1;
    int lb = 0, ub = X;
    while(lb<ub)
    {
        int mid = (lb + ub) / 2;
        double add_win = table[mid][0];
        double add_lose = table[mid][1];
        double new_rate = (win_d + add_win) / (win_d + lose_d + add_win + add_lose);
        if(new_rate >= rate && win+table[mid][0] > lose+table[mid][1])
        {
            min_card = deck_X[mid];
            ub = mid;
        }
        else
        {
            lb = mid + 1;
        }
    }

    std::cout << min_card << std::endl;
    return 0;
}
