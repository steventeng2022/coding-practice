// 劇本殺 | 2023/12 新手同好會 | 新手同好會
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202312-OFFLINE/Game.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202312-OFFLINE/Game.zip
#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Story
{
    string name;
    int money;
    int num;
};

int main()
{
    int N;
    cin >> N;
    vector<Story> stories;
    for (int n = 0; n < N; ++n)
    {
        string S;
        int X;
        int A, B;
        cin >> S >> X;
        cin >> A >> B;
        vector<int> money(B+1);
        for(int i = A; i <= B; ++i)
        {
            cin >> money[i];
        }
        if (A <= X && X <= B)
        {
            stories.push_back({S, money[X], X});
        }
    }
    Story ans = {"", 10000, 0};
    for (int i = 0; i < stories.size(); ++i)
    {
        if (stories[i].num > ans.num)
        {
            ans = stories[i];
        }
        else if (stories[i].num == ans.num && stories[i].money < ans.money)
        {
            ans = stories[i];
        }
        else if (stories[i].num == ans.num && stories[i].money == ans.money && stories[i].name < ans.name)
        {
            ans = stories[i];
        }
    }

    if(stories.size()>0)
        cout << ans.name << endl;
    else
        cout << "Not Found" << endl;
}
