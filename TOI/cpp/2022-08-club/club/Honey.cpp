// 切割蜂蜜 | 2022/08 新手同好會 | 新手同好會
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202208-OFFLINE/Honey.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202208-OFFLINE/Honey.zip
#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>

int main()
{
    int H,W;
    std::cin >> H >> W;

    std::vector<std::vector<int>> table(H,std::vector<int>(1));
    for(int i=0;i<H;i+=1)
    {
        for(int j=0;j<W;j+=1)
        {
            int num;
            std::cin >> num;
            table[i].push_back(num);
        }
        if(i%2)
        {
            int num;
            std::cin >> num;
            table[i].push_back(num);
        }
    }

    for(int i=1;i<=W+1;i+=1)
    {
        for(int j=1;j<H;j+=2)
        {
            int last = std::min(table[j][i-1],table[j-1][i-1]);
            if(j!=H-1)
                last = std::min(last,table[j+1][i-1]);
            table[j][i]+=last;
        }
        for(int j=0;i!=W+1 && j<H;j+=2)
        {
            int last = table[j][i-1];
            if(j!=0)
                last = std::min(last,table[j-1][i]);
            if(j!=H-1)
                last = std::min(last,table[j+1][i]);
            table[j][i]+=last;
        }
    }

    int ans = table[0].back();
    for(int i=1;i<H;i+=1)
        ans = std::min(ans,table[i].back());
    std::cout << ans << std::endl;
    return 0;
}
