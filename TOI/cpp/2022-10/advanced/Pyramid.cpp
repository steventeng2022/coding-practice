// 3-金字塔 | 2022/10/24~2022/10/28 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202210/Pyramid.zip
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202210/Pyramid.zip
#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<pair<int,int>> wood;
    for(int i=0;i<N;++i)
    {
        int a,b;
        cin >> a >> b;
        wood.push_back(make_pair(a,b));
    }

    sort(begin(wood),end(wood),
         [](pair<int,int> &a, pair<int,int> &b)->bool{return a.first==b.first? a.second>b.second:a.first<b.first;});

    vector<int> pyramid;
    pyramid.push_back(wood[0].second);
    for(int i=1;i<wood.size();++i)
    {
        if(pyramid.back()<wood[i].second)
            pyramid.push_back(wood[i].second);
        else
            *lower_bound(begin(pyramid),end(pyramid),wood[i].second) = wood[i].second;

    }
    cout << pyramid.size() << endl;
    return 0;
}
