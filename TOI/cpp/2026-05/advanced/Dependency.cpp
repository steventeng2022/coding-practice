// 1-檢查答案 | 2026/05/04~2026/05/08 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202605/Dependency.pdf
// 本儲存庫實作；詳解見 TOI/explanations/ 同路徑 Markdown。
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n,m;cin>>n>>m;vector<vector<int>>g(n);vector<int>deg(n);
    while(m--){int u,v;cin>>u>>v;--u;--v;g[u].push_back(v);++deg[v];}
    queue<int>q;for(int i=0;i<n;++i)if(!deg[i])q.push(i);
    bool unique=true;int done=0;
    while(!q.empty()){
        if(q.size()!=1)unique=false;
        int u=q.front();q.pop();++done;
        for(int v:g[u])if(!--deg[v])q.push(v);
    }
    cout<<(!unique||done!=n)<<'\n';
}
