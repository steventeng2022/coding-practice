// 3-調香師 | 2026/06/8~2026/06/12 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202606/Perfumer.pdf
// 本儲存庫實作；詳解見 TOI/explanations/ 同路徑 Markdown。
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;cin>>n;vector<string>names(n);vector<long long>sum(n);
    unordered_map<string,int>owner;
    for(int i=0;i<n;++i){int c;cin>>names[i]>>c;while(c--){string s;cin>>s;owner[s]=i;}}
    int k;cin>>k;while(k--){string s;long long m;cin>>s>>m;sum[owner.at(s)]+=m;}
    cout<<names[max_element(sum.begin(),sum.end())-sum.begin()]<<'\n';
}
