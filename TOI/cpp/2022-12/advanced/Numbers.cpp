// 3-數字遊戲 | 2022/12/26~2022/12/30 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202212/Numbers.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202212/Numbers.zip
#include <bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct Node
{
    Node *l=nullptr, *r = nullptr;
    long long int sum = 0;
    int zeros=0;
    Node(int val): sum(val){ if(sum==0)zeros = 1; }
    Node(Node* a, Node* b): l(a), r(b){ pull();}
    void pull() { sum = l->sum + r->sum; zeros = l->zeros+r->zeros; }
};

int N;
Node *Build(vector<int> &original, int l, int r)
{
    if(l+1==r) return new Node(original[l]);
    int mid = (l+r)/2;
    return new Node(Build(original,l,mid),Build(original,mid,r));
}

long long int Query(Node *root, int l, int r, int ql, int qr)
{
    if(r<=ql || l>=qr)
        return 0;
    if(ql<=l && r<=qr)
        return root->sum;
    if(root->zeros==r-l)
        return 0;

    int mid = (l+r)/2;
    return Query(root->l, l,mid,ql,qr) + Query(root->r, mid,r,ql,qr);
}
void RangeUpdate(Node *root, int l, int r, int ql, int qr)
{
    if(r<=ql || l>=qr)
        return;
    if(l+1==r)
    {
        root->sum /= 10;
        if(!root->sum)
            root->zeros = 1;
        return;
    }
    if(root->zeros == r-l)
        return;
    int mid = (l+r)/2;
    RangeUpdate(root->l,l,mid,ql,qr);
    RangeUpdate(root->r,mid,r,ql,qr);
    root->pull();
}
void Update(Node *root, int l, int r, int pos, int k)
{
    if(l+1==r)
    {
        root->sum = k;
        if(k==0)
            root->zeros = 1;
        else
            root->zeros = 0;
        return;
    }
    int mid = (l+r) / 2;
    if(pos<mid)
        Update(root->l,l,mid,pos,k);
    else
        Update(root->r,mid,r,pos,k);
    root->pull();
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int M;
    cin >> N >> M;
    vector<int> original(N);
    for(int i=0;i<N;++i)
        cin >> original[i];
    Node *root = Build(original,0,N);

    for(int i=0;i<M;++i)
    {
        int T, A, B;
        cin >> T >> A >> B;

        if(T==1)
        {
            cout << Query(root,0,N,A-1,B) << endl;
        }
        else if(T==2)
        {
            RangeUpdate(root,0,N,A-1,B);
        }
        else if(T==3)
        {
            Update(root,0,N,A-1,B);
        }
    }
}
