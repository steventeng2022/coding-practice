// 3-姓名分析 | 2023/04/24~2023/04/28 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202304/Name.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202304/Name.zip
#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string>
using namespace std;

constexpr int ALPHABET = 26;
struct TrieNode
{
    int count = 0;
    TrieNode *child[ALPHABET] = {};
    ~TrieNode(){ for(int i=0;i<ALPHABET;i+=1) if(child[i])delete child[i]; }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<string> names(N);
    for(int i=0;i<N;++i)
    {
        cin >> names[i];
    }

    TrieNode *root = new TrieNode;
    for(auto &s:names)
    {
        TrieNode *cur = root;
        for(auto &c:s)
        {
            if(cur->child[c-'A']==nullptr)
                cur->child[c-'A'] = new TrieNode;
            cur = cur->child[c-'A'];
            cur->count += 1;
        }
    }
    for(auto &s:names)
    {
        TrieNode *cur = root;
        int cnt = 0;
        for(auto &c:s)
        {
            cur = cur->child[c-'A'];
            cnt += cur->count;
        }
        cout << cnt-s.size() << "\n";
    }
    delete root;
    return 0;
}
