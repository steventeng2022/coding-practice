// 2-巨額獎金 | 2019/05/27~2019/05/31 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201905/A2-Bonus(Q).pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201905/A2-Bonus.zip
#include <bits/stdc++.h>
#include<bits/stdc++.h>
std::vector<int> Edge[1000005];
long long R[1000005]={1};
void DFS(int cur)
{
    int n=Edge[cur].size();
    for(int i=0;i<n;i+=1)
    {
        if (R[Edge[cur][i]]==0)
            DFS(Edge[cur][i]);
        R[cur]+=R[Edge[cur][i]];
    }
}
int main()
{
    int S,E;
    std::cin>>S>>E;
    for(int i=0;i<E;i+=1)
    {
        int t1,t2;
        std::cin>>t1>>t2;
        Edge[t2].push_back(t1);
    }
    DFS(S-1);
    std::cout<<R[S-1]<<std::endl;
}
