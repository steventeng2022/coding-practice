// 1-二元搜尋樹復原 | 2022/12/26~2022/12/30 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202212/BST.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202212/BST.zip
#include <bits/stdc++.h>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(){}
    TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right) {}
};

TreeNode* dfs(vector<int> &a, int l, int r)
{
    if(l > r) return nullptr;
    if(l == r) return new TreeNode(a[r], nullptr, nullptr);
    int pos = upper_bound(a.begin() + l, a.begin() + r, a[r]) - a.begin();
    return new TreeNode(a[r], dfs(a, l, pos - 1), dfs(a, pos, r - 1));
}

void output(TreeNode *root, int fa)
{
    if(root == nullptr) return;
    output(root->left, root->val);
    printf("%d %d\n", root->val, fa);
    output(root->right, root->val);
}

int main()
{
    int n;
    vector<int> a;
    TreeNode *root = nullptr;
    scanf("%d", &n);
    a.resize(n);
    for(int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
    }
    root = dfs(a, 0, n - 1);
    output(root, -1);
    return 0;
}
