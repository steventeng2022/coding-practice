// 2-符文 | 2025/11/10~2025/11/14 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202511/Runes.pdf
// 本儲存庫實作；詳解見 TOI/explanations/ 同路徑 Markdown。
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n,m;cin>>n>>m;vector<int>a(n),b(m),fail(m);
    for(int&x:a)cin>>x;for(int&x:b)cin>>x;
    for(int i=1,j=0;i<m;++i){
        while(j&&b[i]!=b[j])j=fail[j-1];
        if(b[i]==b[j])++j;fail[i]=j;
    }
    for(int i=0,j=0;i<n;++i){
        while(j&&a[i]!=b[j])j=fail[j-1];
        if(a[i]==b[j])++j;
        if(j==m){cout<<i-m+2<<'\n';return 0;}
    }
    cout<<"not found\n";
}
