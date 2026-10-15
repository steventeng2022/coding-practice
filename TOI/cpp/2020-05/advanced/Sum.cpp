// 3-總和 | 2020/05/25~2020/05/29 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202005/Sum.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202005/Sum.zip
#include <bits/stdc++.h>
//sum
#include<stdio.h>
#include<vector>
typedef long long ll;
using namespace std;

const ll mod = 1000000009;
typedef vector<ll> vec;
typedef vector<vec> mat;

ll fib[4];

mat mul(mat &x, mat &y)
{
    mat ret(3, vec(3));
    for(int i=0; i<3; ++i) for(int j=0; j<3; ++j) ret[i][j]=0;
    for(int i=0; i<3; ++i)
    {
        for(int j=0; j<3; ++j)
        {
            for(int k=0; k<3; ++k)
            {
                ret[i][j]+=x[i][k]*y[k][j];
                ret[i][j]%=mod;
            }
        }
    }
    return ret;
}

mat pow_mod(mat m, int n)
{
    if(n==1) return m;
    mat ret=pow_mod(m, n>>1);
    ret=mul(ret, ret);
    if(n&1) ret=mul(ret, m);
    return ret;
}

ll get_val(mat m, int n)
{
    if(n<=3) return fib[n];
    mat res;
    ll ret=0;
    res=pow_mod(m, n-3);
    ret+=(res[0][0]*fib[3])%mod;
    while(ret<0) ret+=mod;
    ret+=(res[0][1]*fib[2])%mod;
    while(ret<0) ret+=mod;
    ret+=(res[0][2]*fib[1])%mod;
    while(ret<0) ret+=mod;
    return ret%mod;
}

int main()
{
    ll a, b, sum=0;
    int lb, ub;
    mat res;
    mat m(3, vec(3));
    scanf("%lld%lld%d%d", &a, &b, &lb, &ub);
    m[0][0]=a+1, m[0][1]=-a+b, m[0][2]=-b;
    m[1][0]=1, m[1][1]=0, m[1][2]=0;
    m[2][0]=0, m[2][1]=1, m[2][2]=0;
    fib[0]=0, fib[1]=1, fib[2]=2, fib[3]=(a+b+2)%mod;

    sum+=get_val(m, ub);

    sum-=get_val(m, lb-1);
    while(sum<0) sum+=mod;
    printf("%lld\n", sum);
    return 0;
}
