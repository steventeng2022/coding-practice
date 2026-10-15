// 2-分配寶物 | 2020/04/27~2020/05/04 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202004/A2-Treasure.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202004/A2-Treasure.zip
#include <bits/stdc++.h>
#include<stdio.h>

bool flag=false;
int n, a[20], pans=0;

void dfs(int cur, int p1, int p2, int p3)
{
    if(p1>pans || p2>pans || p3>pans) return;
    if(cur==n)
    {
        if(p1==p2 && p2==p3) flag=true;
        return;
    }
    if(!flag) dfs(cur+1, p1+a[cur], p2, p3);
    if(!flag) dfs(cur+1, p1, p2+a[cur], p3);
    if(!flag) dfs(cur+1, p1, p2, p3+a[cur]);
}

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; ++i)
    {
        scanf("%d", &a[i]);
        pans+=a[i];
    }
    if(pans%3==0)
    {
        pans/=3;
        dfs(0, 0, 0, 0);
    }
    puts(flag?"YES":"NO");
    return 0;
}
