// 3-密碼產生器 | 2019/11/25~2019/11/29 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201911/A3-Password.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201911/A3-Password.zip
#include <bits/stdc++.h>
#include<bits/stdc++.h>
#define MOD 10000
int M[3]= {};
int ans[3]={};
int mul[3][3]= {{0,0,1},{1,0,0},{0,0,1}};
void mulm(int a[][3],const int b[][3],const int c[][3])
{
    int temp[3][3]={};
    for(int i=0; i<3; i+=1)
    {
        for(int j=0; j<3; j+=1)
        {
            for(int k=0; k<3; k+=1)
            {
                temp[i][j]+=(b[i][k]*c[k][j])%MOD;
            }
        }
    }
    for(int i=0;i<3;i+=1)
    {
        for(int j=0;j<3;j+=1)
        {
            a[i][j]=temp[i][j]%MOD;
        }
    }
}
void cpym(int a[][3],const int b[][3])
{
    for(int i=0;i<3;i+=1)
    {
        for(int j=0;j<3;j+=1)
        {
            a[i][j]=b[i][j];
        }
    }
}
void init(int a[][3])
{
    for(int i=0;i<3;i+=1)
    {
        a[i][i]=1;
    }
}
void solve(long long N)
{
    int re[3][3]={};
    init(re);
    long long now=1;
    while(N)
    {
        long long low=N&(-N);
        if(low==now)
        {
            mulm(re,re,mul);
            N-=now;
        }
        now<<=1;
        mulm(mul,mul,mul);
    }
    for(int i=0;i<3;i+=1)
    {
        for(int j=0;j<3;j+=1)
        {
            ans[i]+=(re[i][j]*M[j])%MOD;
        }
    }
}
int main()
{
    long long N;
    scanf("%d%d%d%d%d%lld",&mul[0][0],&mul[0][1],&M[2],&M[1],&M[0],&N);
    N-=1;
    solve(N);
    printf("%04d\n",ans[0]%MOD);

}
