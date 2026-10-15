// 2-尋找蜂后 | 2019/03/25~2019/03/29 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201903/A2-QueenBee(Q).pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201903/A2-QueenBee.zip
#include <bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;
char arr[305][305][305]= {};
int visit[305][305][305]= {};
int enqueue[305][305][305]= {};
int now=0;
int big=0;
struct st
{
    int L,W,H;
};
void BFS(st temp,int L,int W,int H)
{
    queue<st> next;
    next.push(temp);
    while(!next.empty())
    {
        st pos=next.front();
        now++;
        big=max(big,now);
        next.pop();
        int x=pos.H,y=pos.L,z=pos.W;
        enqueue[x][y][z]=0;
        visit[x][y][z]=1;
        int movex[6]={1,-1,0,0,0,0};
        int movey[6]={0,0,1,-1,0,0};
        int movez[6]={0,0,0,0,1,-1};
        for(int i=0;i<6;i+=1)
        {
            int nx=x+movex[i];
            int ny=y+movey[i];
            int nz=z+movez[i];
            if(nx>=0 && ny>=0 && nz>=0 && nx<H && ny<L && nz<W)
            {
                if(!visit[nx][ny][nz] && arr[nx][ny][nz]!='1' && !enqueue[nx][ny][nz])
                {
                    next.push({ny,nz,nx});
                    enqueue[nx][ny][nz]=1;
                }
            }
        }
    }
}
int main()
{
    int L,W,H;
    scanf("%d%d%d",&L,&W,&H);
    for(int i=0; i<H; i+=1)
    {
        for(int j=0; j<L; j+=1)
        {
            for(int k=0; k<W; k+=1)
            {
                scanf(" %c",&arr[i][j][k]);
            }
        }
    }
    for(int i=0; i<H; i+=1)
    {
        for(int j=0; j<L; j+=1)
        {
            for(int k=0; k<W; k+=1)
            {
                if(arr[i][j][k]=='0' && !visit[i][j][k])
                {
                    now=0;
                    BFS({j,k,i},L,W,H);
                }
            }
        }
    }
    printf("%d\n",big);
}
