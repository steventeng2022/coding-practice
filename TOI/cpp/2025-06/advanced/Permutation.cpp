// 3-排列順序 | 2025/06/09~2025/06/13 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202506/Permutation.pdf
// 本儲存庫實作；詳解見 TOI/explanations/ 同路徑 Markdown。
#include <bits/stdc++.h>
using namespace std;
using ll=long long;const ll MOD=1000000007;
ll power(ll a,ll e){ll r=1;for(;e;e>>=1,a=a*a%MOD)if(e&1)r=r*a%MOD;return r;}
int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n,m;cin>>n>>m;vector<int>a(n),bit(m+1);for(int&x:a)cin>>x;
    vector<ll>fact(m+1,1);for(int i=1;i<=m;++i)fact[i]=fact[i-1]*i%MOD;
    ll inv=power(fact[m-n],MOD-2),ans=0;
    for(int i=0;i<n;++i){
        int used=0;for(int p=a[i];p;p-=p&-p)used+=bit[p];
        ll smaller=a[i]-1-used;
        ans=(ans+smaller*fact[m-i-1]%MOD*inv)%MOD;
        for(int p=a[i];p<=m;p+=p&-p)++bit[p];
    }
    cout<<ans<<'\n';
}
