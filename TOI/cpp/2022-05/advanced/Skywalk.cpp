// 2-天空步道 | 2022/05/30~2022/06/05 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202205/Skywalk.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202205/Skywalk.zip
#include <bits/stdc++.h>
#include<iostream>

int main()
{
    int T;
    std::cin >> T;
    for(int i=0; i<T; i+=1)
    {
        int N, M, K;
        std::cin >> N >> M >> K;
        K -= 1;

        long long int lb = 1, ub = M+1;
        while(lb < ub)
        {
            long long int mid = (lb + ub) / 2;

            long long int counter = mid;
            if(mid < K+1)
            {
                counter += (mid) * (mid-1) / 2;
                counter += (K-mid)+1;
            }
            else
            {
                counter += (mid-1+mid-K) * K / 2;
            }

            long long int second_half = N - K - 1;
            if(mid < second_half+1)
            {
                counter +=  (mid) * (mid-1) / 2;
                counter +=  (second_half-mid)+1;
            }
            else
            {
                counter += (mid-1+mid-second_half) * second_half / 2;
            }

            if(counter <= M)
                lb = mid + 1;
            else
                ub = mid;
        }
        std::cout << lb-1 << std::endl;
    }
    return 0;
}
