// 1-狼人殺 | 2023/11/20~2023/11/24 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202311/Werewolves.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202311/Werewolves.zip
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    int werewolves_alive = 0;
    for(int i = 0; i < n; ++i)
    {
        cin >> a[i];
        if (a[i] == -1)
            werewolves_alive += 1;
    }

    bool isWrong = false;
    int dead;
    while(cin >> dead)
    {
        if (dead == 0)
            break;

        if (a[dead-1] == 2)
        {
            isWrong = true;
        }
        if (a[dead-1] == -1)
        {
            werewolves_alive -= 1;
        }
        a[dead-1] = 2;
    }

    if (isWrong)
        cout << "Wrong" << endl;
    else if (werewolves_alive > 0)
        cout << "Werewolves" << endl;
    else
        cout << "Townsfolk" << endl;

    return 0;
}
