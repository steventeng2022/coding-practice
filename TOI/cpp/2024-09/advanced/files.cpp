// 1-檔案順序 | 2024/09/30~2024/10/04 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202410/files.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202410/files.zip
#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct File{
    int fileInfo[5] = {0};
};

class Cmp{
public:
    bool operator() (const File &lhs, const File &rhs)
    {
        for(auto i: Cmp::sort_order)
        {
            if(i<0)
            {
                i *= -1;
                if(lhs.fileInfo[i]!=rhs.fileInfo[i])
                    return lhs.fileInfo[i]>rhs.fileInfo[i];
            }
            else
            {
                if(lhs.fileInfo[i]!=rhs.fileInfo[i])
                    return lhs.fileInfo[i]<rhs.fileInfo[i];
            }
        }
        return false;
    }
    static vector<int> sort_order;
};

vector<int> Cmp::sort_order;
int main()
{
    Cmp::sort_order.clear();
    int N, K;
    cin >> N >> K;
    vector<File> lists(N);
    for(int i=0; i<N; ++i)
    {
        File &f = lists[i];
        for(int info=0; info<4; ++info)
            cin >> f.fileInfo[info+1];
        f.fileInfo[0] = i;
    }

    vector<int> orders(K);
    for(auto &i:orders)
        cin >> i;
    reverse(orders.begin(), orders.end());

    //process click orders
    vector<bool> appeared(5, false);
    int prev = orders[0], cnt = 1;
    for(int i=1; i<orders.size(); ++i)
    {
        if(orders[i]==prev)cnt += 1;
        else
        {
            if(appeared[prev]==false)
            {
                appeared[prev] = true;
                if(cnt%2==0)prev *= -1;
                Cmp::sort_order.push_back(prev);
            }
            cnt = 1;
        }
        prev = orders[i];
    }
    if(appeared[prev]==false)
    {
        if(cnt%2==0)prev *= -1;
        Cmp::sort_order.push_back(prev);
    }
    Cmp::sort_order.push_back(0);

    sort(lists.begin(), lists.end(), Cmp());
    for(auto &f: lists)
    {
        for(int i=1; i<=4; ++i)
        {
            cout << f.fileInfo[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
