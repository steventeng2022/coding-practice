// 2-道路鋪設 | 2019/10/21~2019/10/31 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201910/A2-Roads.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201910/A2-Roads.zip
#include <bits/stdc++.h>
#include<bits/stdc++.h>
const long long MOD=1e9+7;
long long mod(long long a)
{
    if(a==0) return 1;
    else if(a==1) return 2;
    else if(a%2==0)
    {
        long long x=mod(a/2);
        return (x*x)%MOD;
    }
    else return (mod(a-1)*mod(1))%MOD;
}
int main()
{
    int a;
    scanf("%d",&a);
    while(a--)
    {
        long long x;
        scanf("%lld",&x);
        printf("%lld\n",mod(x-1));
    }
}
