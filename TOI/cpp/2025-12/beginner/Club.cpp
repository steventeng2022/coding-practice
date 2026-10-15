// 2-社團 | 2025/12/22~2025/12/26 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202512/Club.pdf
// 本儲存庫實作；詳解見 TOI/explanations/ 同路徑 Markdown。
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n,m;cin>>n>>m;vector<string>names(m);vector<int>cnt(m);unordered_map<string,int>id;
    for(int i=0;i<m;++i){cin>>names[i];id[names[i]]=i;}
    while(n--){set<int>used;for(int j=0;j<3;++j){string s;cin>>s;used.insert(id.at(s));}for(int i:used)++cnt[i];}
    for(int i=0;i<m;++i)cout<<names[i]<<' '<<cnt[i]<<'\n';
}
