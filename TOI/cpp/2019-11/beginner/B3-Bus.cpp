// 3-不再傻傻等公車 | 2019/11/25~2019/11/29 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201911/B3-Bus.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201911/B3-Bus.zip
#include <bits/stdc++.h>
#include<stdio.h>

int main()
{
    int n = 0;
    int h = 0, m = 0;
    scanf("%d", &n);
    scanf("%d %d", &h, &m);

    int Bus_h[21]={}, Bus_m[21]={};
    Bus_h[0] = h;
    Bus_m[0] = m;

    for( int i=1; i<=n; i+=1 )
    {
        int t = 0;
        scanf("%d",&t);

        Bus_h[i] = Bus_h[i-1];
        Bus_m[i] = Bus_m[i-1] + t;

        while( Bus_m[i] >= 60 )
        {
            Bus_h[i] += 1;
            Bus_m[i] -= 60;
        }

        if( Bus_h[i] >= 24 ){
            Bus_h[i] -= 24;
        }
    }

    int p = -1;
    while( (scanf("%d", &p)) && (p != 0) )
    {
        printf("%02d:%02d\n", Bus_h[p], Bus_m[p]);
    }
    return 0;
}
