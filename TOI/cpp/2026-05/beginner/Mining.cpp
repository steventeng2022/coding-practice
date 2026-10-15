// 3-礦業調度 | 2026/05/04~2026/05/08 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202605/Mining.pdf
// 本儲存庫實作；詳解見 TOI/explanations/ 同路徑 Markdown。
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;long long m;cin>>n>>m;vector<long long>a(n+1);
    for(int i=0;i<n;++i){cin>>a[i];a[i]=max(0LL,a[i]-i);}
    sort(a.begin(),a.begin()+n,greater<long long>());
    long long ans=0;
    for(int i=0;i<n;++i){
        long long hi=a[i],lo=a[i+1],width=i+1,cnt=(hi-lo)*width;
        if(m>=cnt){ans+=(hi+lo+1)*(hi-lo)/2*width;m-=cnt;}
        else{long long levels=m/width,extra=m%width;
            ans+=(2*hi-levels+1)*levels/2*width+extra*(hi-levels);break;}
    }
    cout<<ans<<'\n';
}
