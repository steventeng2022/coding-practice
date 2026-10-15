// 3-串珠吊飾 | 2025/11/10~2025/11/14 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202511/BeadedCharm.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202511/BeadedCharm.zip
#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<unordered_set>
using namespace std;

struct Node
{
    int in_order = -1;
    int min_back_order = -1;
    int subtree_size = 1;
    unordered_set<int> bridges = unordered_set<int>();
};

int dfs(const vector<vector<int>> &graph, int index, int parent, vector<Node> &data, int &in_order)
{
    if(data[index].in_order==-1)
    {
        int min_back_order = in_order;
        data[index].in_order = in_order;
        data[index].min_back_order = in_order;
        ++in_order;

        for(auto &i:graph[index])
        {
            if(i==parent)continue;
            bool add_to_subtree = (data[i].in_order==-1);
            int back_order = dfs(graph, i, index, data, in_order);
            if(back_order > data[index].in_order)
            {
                data[index].bridges.insert(i);
                data[i].bridges.insert(index);
            }
            min_back_order = min(min_back_order, back_order);
            if(add_to_subtree) data[index].subtree_size += data[i].subtree_size;
        }
        data[index].min_back_order = min_back_order;
        return min_back_order;
    }
    return data[index].min_back_order;
}

int main()
{
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<vector<int>> graph(N);
    for(int i=0; i<M; ++i)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    //finding bridge and subtree size
    vector<Node> data(N);
    int vis = 0;
    dfs(graph, 0, -1, data, vis);

    //queries
    for(int i=0; i<Q; ++i)
    {
        int a, b;
        cin >> a >> b;
        const unordered_set<int> &node = data[a].bridges;
        int fallen = 0;
        if(node.find(b)!=node.end()) fallen = min( data[a].subtree_size, data[b].subtree_size);
        cout << N-fallen << endl;
    }
    return 0;
}
