// 3-關鍵星 | 2019/04/22~2019/04/26 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201904/A3-KeyPlanet(Q).pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201904/A3-KeyPlanet.zip
#include <bits/stdc++.h>
 #include<bits/stdc++.h>
void DFS(int pre, int cur, std::vector<int> adj[], int low[], int visit[], int &t, std::vector<int> &ans)
{
    t+=1;
    visit[cur] = low[cur] = t;
    int Num_child = 0;
    bool ap = false;
    int Num = adj[cur].size();
    for (int i=0; i<Num; i+=1)
    {
        int dest = adj[cur][i];
        if (dest==pre)
            continue;
        if (visit[dest]!=0)
        {
            low[cur] = std::min(low[cur], visit[dest]);
        }
        else
        {
            Num_child+=1;
            DFS(cur, dest, adj, low, visit, t, ans);
            low[cur] = std::min(low[cur], low[dest]);
            if(low[dest]>=visit[cur]) ap=true;
        }
    }
    if ((pre==cur&&Num_child>1)||(cur != pre && ap))
        ans.push_back(cur);
}
int main()
{
    std::vector<int> adj[20005];
    std::vector<int> ans;
    int visit[20005]= {};
    int low[20005]= {};
    int t = 0;

    int V,E;
    scanf("%d%d", &V, &E);
    for(int i=0; i<E; i+=1)
    {
        int v1,v2;
        scanf("%d%d",&v1, &v2);
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }
    DFS(0,0, adj, low, visit, t, ans);
    int n=ans.size();
    std::sort(ans.begin(),ans.end());
    for(int i=n-1; i>=0; i-=1)
    {
        if(i!=n-1)
            printf(" ");
        printf("%d", ans[i]);
    }
    if (n==0)
        printf("FAIL");
    printf("\n");
}
