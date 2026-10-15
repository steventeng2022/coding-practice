// 巧克力工廠 | 2023/12 新手同好會 | 新手同好會
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202312-OFFLINE/Chocolate.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202312-OFFLINE/Chocolate.zip
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    int N;
    int64_t K;
    cin >> N >> K;
    int num[N];
    for (int i = 0; i < N; ++i)
    {
        cin >> num[i];
    }

    int left = 0, right = -1;
    int64_t cur = 1;

    while (cur != K)
    {
        if (K > cur)
        {
            right += 1;
            if (num[right] == 0)
            {
                left = right + 1;
                cur = 1;
            }
            else
            {
                cur *= num[right];
            }
        }
        else if (K < cur)
        {
            cur /= num[left];
            left += 1;
        }
    }

    cout << left + 1 << " " << right + 1 << endl;
}
