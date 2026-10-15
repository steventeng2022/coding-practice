// 1-股票交易 | 2023/10/23~2023/10/27 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202310/Stocks.pdf
// 本儲存庫實作；詳解見 TOI/explanations/ 同路徑 Markdown。
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n;long long k;cin>>n>>k;vector<int>ans(n,-1);
    using P=pair<long long,int>;priority_queue<P,vector<P>,greater<P>>q;
    for(int i=0;i<n;++i){long long p;cin>>p;
        while(!q.empty()&&q.top().first<=p){ans[q.top().second]=i+1;q.pop();}
        q.push({p+k,i});
    }
    for(int i=0;i<n;++i)cout<<ans[i]<<(i+1==n?'\n':' ');
}
