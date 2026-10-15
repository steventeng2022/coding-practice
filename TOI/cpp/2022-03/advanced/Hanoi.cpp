// 3-河內塔 | 2022/03/28~2022/04/01 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202203/Hanoi.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202203/Hanoi.zip
#include <bits/stdc++.h>
#include<iostream>

int main()
{
    int T = 0;
    std::cin >> T;
    for(int i=0; i<T; i+=1)
    {
        int numDisc = 0;
        int step = 0;
        std::cin >> numDisc >> step;

        int answer = 1;
        while(step % 2 == 0)
        {
            step /= 2;
            answer += 1;
        }
        std::cout << answer << std::endl;
    }
    return 0;
}
