// 2-騎士 | 2020/10/26~2020/10/30 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202010/Knight.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202010/Knight.zip
#include <bits/stdc++.h>
#include <bits/stdc++.h>
#define in_bound(s_x,s_y,x,y) ((s_x >=0 && s_x < x) && (s_y >=0 && s_y < y))
using namespace std;
bool walked[1000][1000] = {0};
int delta[8][2]=
{
    { 2, 1},{ 1, 2},{-2, 1},{-1, 2},
    {-2,-1},{-1,-2},{ 2,-1},{ 1,-2}
};

int bfs(int x,int y,int sx,int sy,int ex,int ey)
{
    int sc = 0;
    queue<pair<int,int> > step;
    step.push(make_pair(sx,sy));
    while(!step.empty())
    {
        int bc = step.size();
        for(int i=0;i!=bc;++i)
        {
            pair<int,int> c_loc = step.front();

            walked[c_loc.first][c_loc.second] = true;

            if(c_loc.first == ex && c_loc.second == ey)
                return sc;

            for(int d=0;d!=8;++d)
            {
                int nx,ny;
                nx = c_loc.first+delta[d][0];
                ny = c_loc.second+delta[d][1];

                if(in_bound(nx,ny,x,y) && !walked[nx][ny])
                {
                    step.push(make_pair(nx,ny));
                    walked[nx][ny] = true;
                }
            }

            step.pop();
        }
        sc++;
    }
    return -1;
}
int main()
{
    int x,y;
    cin >> x >> y;
    int sx,sy,ex,ey;
    cin >> sx >> sy;
    cin >> ex >> ey;
    try
    {
        cout << bfs(x,y,sx,sy,ex,ey) << '\n';
    }
    catch(bad_alloc &e)
    {
        cout << "allocate failed:" <<e.what() <<'\n';
        return -1;
    }
    return 0;
}
