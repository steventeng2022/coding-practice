// 機票 | 2022/12 新手同好會 | 新手同好會
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202212-OFFLINE/Ticket.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202212-OFFLINE/Ticket.zip
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int N;
int ans = INT_MAX;
bool visited[55] = {};
int ticket[55][55] = {};

void dfs(int s, int t, int cost)
{
    if(s == t) {
        ans = min(ans, cost);
        return;
    }
    visited[s] = true;
    for(int i=0; i<N; i++) {
        if(ticket[s][i] != -1 && !visited[i]){
            visited[i] = true;
            int tmp = cost + ticket[s][i];
            if(cost > 0) tmp -= 50;
            dfs(i, t, tmp);
            visited[i] = false;
        }
    }
}

int main()
{
    cin >> N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> ticket[i][j];
        }
    }
    int src, trg;
    cin >> src >> trg;
    dfs(src-1, trg-1, 0);
    cout << ans << endl;
}
