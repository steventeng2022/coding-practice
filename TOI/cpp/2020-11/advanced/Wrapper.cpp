// 3-包雞紙包 | 2020/11/23~2020/11/27 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202011/Wrapper.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202011/Wrapper.zip
#include <bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;
uint64_t mod = 1080494663;
void print_matrix(uint64_t *matrix)
{
    printf("%I64u %I64u\n", matrix[0], matrix[1]);
    printf("%I64u %I64u\n", matrix[2], matrix[3]);
}
void matrix_mul(uint64_t *m1, uint64_t *m2,uint64_t *res)
{
    res[0]=((m1[0]*m2[0])%mod+(m1[1]*m2[2])%mod)%mod,
    res[1]=((m1[0]*m2[1])%mod+(m1[1]*m2[3])%mod)%mod,
    res[2]=((m1[2]*m2[0])%mod+(m1[3]*m2[2])%mod)%mod,
    res[3]=((m1[2]*m2[1])%mod+(m1[3]*m2[3])%mod)%mod;
}
uint64_t get_ans(int n)
{
    if(n == 0)
        return 1;

    uint64_t m1[] = {0,1,1,1};
    uint64_t m2[] = {0,1,1,1};
    uint64_t tmp[] = {0,0,0,0};
    uint64_t res = (m1[0] + m1[1] + m2[0] + m2[1]) % mod;
    for(int i =0;i<n-1;++i)
    {
        matrix_mul(m1,m2,tmp);
        swap(m1,m2);
        swap(m2,tmp);
        res = (res+(m2[0]+m2[1])%mod)%mod;
    }
    return res;
}
int main()
{
    int x;
    cin >> x;
    cout << get_ans(x) << "\n";
}
