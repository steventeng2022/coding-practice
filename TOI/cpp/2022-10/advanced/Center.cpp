// 1-資料中心 | 2022/10/24~2022/10/28 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202210/Center.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202210/Center.zip
#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

struct UnionFind
{
    vector<int> root;
    vector<int> rank;

    UnionFind(int siz): root(siz), rank(siz)
    {
        for(int i=0;i<siz;++i)
        {
            root[i] = i;
            rank[i] = 1;
        }
    }
    int Find(int x)
    {
        if(root[x]==x)
            return x;
        else
            return root[x] = Find(root[x]);
    }
    void Union(int x, int y)
    {
        int rootX = Find(x);
        int rootY = Find(y);
        if (rootX != rootY) {
            if (rank[rootX] >= rank[rootY]) {
                root[rootY] = rootX;
                rank[rootX] += rank[rootY];
            } else {
                root[rootX] = rootY;
                rank[rootY] += rank[rootX];
            }
        }
    }
};

int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> data;
    for(int i=0;i<M;++i)
    {
        vector<int> line(3);
        cin >> line[1] >> line[2] >> line[0];
        line[0] = -line[0];
        data.push_back(line);
    }
    sort(begin(data),end(data));

    UnionFind uf(N);
    int in_tree = 1;
    int index = 0;
    int ans;
    while(in_tree<N)
    {
        if(uf.Find(data[index][1]-1)!=uf.Find(data[index][2]-1))
        {
            uf.Union(data[index][1]-1,data[index][2]-1);
            in_tree += 1;
            ans = -data[index][0];
        }
        index += 1;
    }
    cout << ans << endl;
    return 0;
}
