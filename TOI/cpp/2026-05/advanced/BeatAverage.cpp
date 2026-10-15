// 3-平均值 | 2026/05/04~2026/05/08 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202605/BeatAverage.pdf
// 本儲存庫實作；詳解見 TOI/explanations/ 同路徑 Markdown。
#include <bits/stdc++.h>
using namespace std;using ll=long long;
struct Blocks{
    int width;vector<ll>a,sum;vector<vector<ll>>sorted;
    Blocks(vector<ll>v):width(max(1,(int)sqrt(v.size()))),a(move(v)){
        int count=(a.size()+width-1)/width;sum.resize(count);sorted.resize(count);
        for(int i=0;i<(int)a.size();++i){sum[i/width]+=a[i];sorted[i/width].push_back(a[i]);}
        for(auto&b:sorted)sort(b.begin(),b.end());
    }
    void modify(int i,ll delta){
        int b=i/width;auto&v=sorted[b];v.erase(lower_bound(v.begin(),v.end(),a[i]));
        a[i]+=delta;v.insert(upper_bound(v.begin(),v.end(),a[i]),a[i]);sum[b]+=delta;
    }
    int query(int l,int r){
        ll total=0,len=r-l;
        for(int i=l;i<r;){if(i%width==0&&i+width<=r){total+=sum[i/width];i+=width;}else total+=a[i++];}
        ll threshold=total/len;if(total<0&&total%len)--threshold;
        int ans=0;
        for(int i=l;i<r;){
            if(i%width==0&&i+width<=r){auto&b=sorted[i/width];ans+=b.end()-upper_bound(b.begin(),b.end(),threshold);i+=width;}
            else ans+=a[i++]>threshold;
        }
        return ans;
    }
};
int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n,q;cin>>n>>q;vector<ll>a(n),b(n);for(int i=0;i<n;++i){cin>>a[i];b[i]=500-a[i];}
    Blocks A(a),B(b);while(q--){int op,x;ll y;char col;cin>>op>>x>>y>>col;auto&v=col=='A'?A:B;
        if(op==1)v.modify(x-1,y);else cout<<v.query(x-1,(int)y)<<'\n';}
}
