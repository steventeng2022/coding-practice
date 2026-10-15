// 1-雷射探測 | 2026/06/8~2026/06/12 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202606/Laser.pdf
// 本儲存庫實作；詳解見 TOI/explanations/ 同路徑 Markdown。
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n,m; cin>>n>>m; vector<string>a(n); for(auto&s:a)cin>>s;
    vector<unsigned char>seen(n*m); int r=0,c=0,d=0,ans=0;
    const int dr[]={0,1,0,-1},dc[]={1,0,-1,0};
    while(r>=0&&r<n&&c>=0&&c<m&&a[r][c]!='#'){
        int p=r*m+c;
        if(seen[p]&(1<<d))break;
        if(!seen[p])++ans;
        seen[p]|=1<<d;
        r+=dr[d]; c+=dc[d];
        if(r>=0&&r<n&&c>=0&&c<m){
            if(a[r][c]=='R')d^=3;
            else if(a[r][c]=='L')d^=1;
        }
    }
    cout<<ans<<'\n';
}
