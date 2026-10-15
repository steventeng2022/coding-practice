// 3-精靈王國 | 2023/11/20~2023/11/24 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202311/Kingdom.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202311/Kingdom.zip
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    int K;
    cin >> K;
    int num[K], max = 1;
    for (int i = 0; i < K; ++i)
    {
        cin >> num[i];
    }

    for (int i = 0; i < K; ++i)
    {
        if (num[i] != -1)
        {
            int cnt = 0, cur = i;
            while (num[cur] != -1)
            {
                int tmp = cur;
                cnt++;
                cur = num[cur] - 1;
                num[tmp] = -1;
            }
            if (cnt > max)
            {
                max = cnt;
            }
        }
    }

    cout << max << endl;
}
