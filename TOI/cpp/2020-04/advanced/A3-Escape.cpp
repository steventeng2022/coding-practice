// 3-迷宮逃離 | 2020/04/27~2020/05/04 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202004/A3-Escape.pdf
// 本儲存庫實作；詳解見 TOI/explanations/ 同路徑 Markdown。
#include <bits/stdc++.h>
using namespace std;
struct DSU{
    vector<int>p,s,x;
    DSU(int n):p(n),s(n,1),x(n){iota(p.begin(),p.end(),0);}
    int find(int u){if(p[u]!=u){int old=p[u];p[u]=find(old);x[u]^=x[old];}return p[u];}
    bool join(int u,int v,int want){
        int a=find(u),b=find(v),d=x[u]^x[v]^want;
        if(a==b)return d==0;
        if(s[a]<s[b])swap(a,b);
        p[b]=a;x[b]=d;s[a]+=s[b];return true;
    }
};
int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n,t;cin>>n>>t;DSU dsu(n);bool ok=true;
    while(t--){string a,b;char r;cin>>a>>b>>r;
        int u=stoi(a)-1,v=stoi(b)-1;
        int want=(r=='D')^(a.back()=='R')^(b.back()=='R');
        if(!dsu.join(u,v,want))ok=false;
    }
    cout<<(ok?"Easy Peasy":"Impossible")<<'\n';
}
