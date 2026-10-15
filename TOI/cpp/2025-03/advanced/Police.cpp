// 3-取締違規 | 2025/03/17~2025/03/21 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202503/Police.pdf
// 本儲存庫實作；詳解見 TOI/explanations/ 同路徑 Markdown。
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n,m;cin>>n>>m;vector<long long>delta(m+2);
    while(n--){int a,l,r;cin>>a>>l>>r;delta[l]+=a;delta[r+1]-=a;}
    long long now=0,best=0;int pos=0;
    for(int i=0;i<=m;++i){now+=delta[i];if(now>best){best=now;pos=i;}}
    cout<<pos<<' '<<best<<'\n';
}
