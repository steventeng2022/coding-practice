// 2-試算表 | 2025/09/29~2025/10/03 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202509/sheet.pdf
// 本儲存庫實作；詳解見 TOI/explanations/ 同路徑 Markdown。
#include <bits/stdc++.h>
using namespace std;const int MOD=1000000007;
int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int m,n;cin>>m>>n;int count=m*n;vector<int>value(count),degree(count);vector<vector<int>>out(count);
    for(int i=0;i<count;++i){
        string s;cin>>s;vector<string>terms;
        if(s[0]=='='){int split=s.find('+');terms={s.substr(1,split-1),s.substr(split+1)};}else terms={s};
        for(auto&t:terms){if(t[0]>='A'&&t[0]<='Z'){int src=(stoi(t.substr(1))-1)*n+t[0]-'A';out[src].push_back(i);++degree[i];}else value[i]+=stoi(t);}
    }
    queue<int>q;for(int i=0;i<count;++i)if(!degree[i])q.push(i);
    while(!q.empty()){int u=q.front();q.pop();value[u]%=MOD;for(int v:out[u]){value[v]=(value[v]+value[u])%MOD;if(!--degree[v])q.push(v);}}
    for(int i=0;i<count;++i){if(degree[i])cout<<"ERROR";else cout<<value[i];cout<<((i+1)%n?' ':'\n');}
}
