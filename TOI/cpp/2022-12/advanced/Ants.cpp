// 2-螞蟻暗號 | 2022/12/26~2022/12/30 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202212/Ants.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202212/Ants.zip
#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Ant
{
    int st = 0;
    bool right = false;
    int diff = 0;
};

int main()
{
    int K;
    cin >> K;
    string S;
    cin >> S;
    int N, M;
    cin >> N >> M;
    vector<Ant> data(N);
    vector<int> diffs(N);
    for(int i=0;i<N;++i)
    {
        cin >> data[i].st >> data[i].right;
        if(data[i].right)
            data[i].diff = K+1-data[i].st;
        else
            data[i].diff = data[i].st;
        diffs[i] = data[i].diff;
    }
    nth_element(diffs.begin(),diffs.begin()+M-1,diffs.end());
    int distance = diffs[M-1];
    bool flg[2000001] = {};
    for(int i=0;i<N;++i)
    {
        if(data[i].diff>distance)
        {
            if(data[i].right)
                flg[data[i].st+distance-1] = true;
            else
                flg[data[i].st-distance-1] = true;
        }
    }
    for(int i=0;i<K;++i)
    {
        if(flg[i])
            cout << S[i];
    }
    return 0;
}
