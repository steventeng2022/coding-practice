// 骨牌 | 2021/10/23 新手同好會 | 新手同好會
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202110-OFFLINE/Domino.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202110-OFFLINE/Domino.zip
#include <bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    int num[1005] = {};
    int find_first[1005] = {};

    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x, next;
        cin >> x >> next;
        num[x] = next;
        find_first[x] += 1;
        if(next!=-1) find_first[next] += 1;
    }
    int first;
    for(int i = 0; i < 1001; i++)
    {
        if(find_first[i] == 1)
        {
            first = i;
            break;
        }
    }
    cout << first;

    int next = num[first];
    while(next != -1)
    {
        cout << " " << next;
        next = num[next];
    }
    cout << endl;

}
