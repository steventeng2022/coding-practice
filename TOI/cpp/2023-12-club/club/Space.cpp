// 太空站 | 2023/12 新手同好會 | 新手同好會
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202312-OFFLINE/Space.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202312-OFFLINE/Space.zip
#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>

using namespace std;

int search(pair<int, int> num[], int right, int target)
{
    int left = 0;
    int loc = (left + right) / 2;
    while (num[loc].second != target)
    {
        if (target > num[loc].second)
        {
            left = loc + 1;
            loc = (left + right) / 2;
        }
        else if (target < num[loc].second)
        {
            right = loc - 1;
            loc = (left + right) / 2;
        }
    }
    return num[loc].first + 1;
}

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int M, N;
    cin >> M >> N;
    pair<int, int> A[M];
    for (int i = 0; i < M; ++i)
    {
        A[i].first = i;
        cin >> A[i].second;
    }

    sort(A, A + M, cmp);

    int target, ans;
    for (int i = 0; i < N; ++i)
    {
        cin >> target;
        ans = search(A, M - 1, target);
        if (i == N - 1)
        {
            cout << ans << endl;
        }
        else
        {
            cout << ans << " ";
        }
    }
}
