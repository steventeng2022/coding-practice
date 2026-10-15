// 3-陣列運算 | 2024/11/11~2024/11/15 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202411/Array.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202411/Array.zip
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    int A[5], B[5], last = 1;
    for (int i = 0; i < 5; ++i)
    {
        cin >> A[i];
    }
    for (int i = 0; i < 5; ++i)
    {
        cin >> B[i];
    }

    while (1)
    {
        if (last % 2 == 1) // 處理第一個陣列
        {
            if (A[0] % 3 == 0) // 如果第一個數值可以被3整除
            {
                int max = 0;
                for (int i = 0; i < 5; ++i) // 找到最大值
                {
                    if (A[i] > max)
                    {
                        max = A[i];
                    }
                }
                cout << max << endl;
                for (int i = 0; i < 5; ++i) // 將他們除以2
                {
                    if (A[i] == max)
                    {
                        A[i] /= 2;
                    }
                }
                last = max;
            }
            else // 如果第一個數值不能被3整除
            {
                int min = 2147483647;
                for (int i = 0; i < 5; ++i) // 找到非0最小值
                {
                    if (A[i] < min && A[i] != 0)
                    {
                        min = A[i];
                    }
                }
                cout << min << endl;
                for (int i = 0; i < 5; ++i) // 將他們減去1
                {
                    if (A[i] == min)
                    {
                        A[i] -= 1;
                    }
                }
                last = min;
            }
        }
        else // 處理第二個陣列
        {
            if (B[0] % 3 == 0) // 如果第一個數值可以被3整除
            {
                int max = 0;
                for (int i = 0; i < 5; ++i) // 找到最大值
                {
                    if (B[i] > max)
                    {
                        max = B[i];
                    }
                }
                cout << max << endl;
                for (int i = 0; i < 5; ++i) // 將他們除以2
                {
                    if (B[i] == max)
                    {
                        B[i] /= 2;
                    }
                }
                last = max;
            }
            else // 如果第一個數值不能被3整除
            {
                int min = 2147483647;
                for (int i = 0; i < 5; ++i) // 找到非0最小值
                {
                    if (B[i] < min && B[i] != 0)
                    {
                        min = B[i];
                    }
                }
                cout << min << endl;
                for (int i = 0; i < 5; ++i) // 將他們減去1
                {
                    if (B[i] == min)
                    {
                        B[i] -= 1;
                    }
                }
                last = min;
            }
        }
        if (last == 0)
        {
            break;
        }
    }
}
