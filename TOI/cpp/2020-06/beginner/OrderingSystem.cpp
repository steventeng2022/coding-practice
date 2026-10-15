// 1-點餐系統 | 2020/06/29~2020/07/03 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202006/OrderingSystem.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202006/OrderingSystem.zip
#include <bits/stdc++.h>
#include<iostream>
using namespace std;

int main()
{
    string setUp[]=
    {
        "Medium Wac",
        "WChicken Nugget",
        "Geez Burger",
        "ButtMilk Crispy Chicken",
        "Plastic Toy"
    };
    string single[]=
    {
        "German Fries",
        "Durian Slices",
        "WcFurry",
        "Chocolate Sunday"
    };
    int setUpPrice[]=
    {
        4,
        8,
        7,
        6,
        3
    };
    int singlePrice[]=
    {
        2,
        3,
        5,
        7
    };

    int total = 0;
    while(true)
    {
        int cmd;
        cin >> cmd;
        if(cmd == 0)
        {
            cout << "Total: " << total << endl;
            break;
        }
        int order;
        cin >> order;
        order--;
        if(cmd == 1)
        {
            cout << setUp[order] << ' ' << setUpPrice[order] << endl;
            total += setUpPrice[order];
        }
        else if(cmd == 2)
        {
            cout << single[order] << ' ' << singlePrice[order] << endl;
            total += singlePrice[order];
        }
    }
}
