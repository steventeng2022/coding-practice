// 俄羅斯方塊 | 2020/08/15 新手同好會 | 新手同好會
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202008/Tetris.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202008/Tetris.zip
#include <bits/stdc++.h>
#include <iostream>
#include <assert.h>

using namespace std;

/*
    ----------------------------
    |  0  ||  1  ||  2  ||  3  |
    ----------------------------
    |     ||  0  ||  0  ||  0  |
    | 0x0 || 0x  || 0x0 ||  x0 |
    |  0  ||  0  ||     ||  0  |
    ----------------------------
*/
int t_bias[4][4][2]={
    {{ 0, 0},{ 0,-1},{-1, 0},{ 1, 0}},
    {{ 0, 0},{-1, 0},{ 0, 1},{ 0,-1}},
    {{ 0, 0},{ 0, 1},{-1, 0},{ 1, 0}},
    {{ 0, 0},{ 1, 0},{ 0, 1},{ 0,-1}}
};
bool check_grid(int c_x,int c_y,int x,int y)
{
    return 0<c_x && c_x<=x && 0<c_y && c_y<=y;
}
int check_t(int c_x,int c_y,int c_ori,int x,int y)
{
    for(int i=0;i!=4;i++)
        if(!check_grid(c_x + t_bias[c_ori][i][0],c_y + t_bias[c_ori][i][1],x,y))
            return false;
    return true;
}
void safe_move(int &c_x,int &c_y,int &c_ori,int x,int y,int move)
{
    int bias[5][3] = {
        { 0,-1, 0},
        { 1,-1, 0},
        {-1,-1, 0},
        { 0,(c_ori==2)? -c_y+1:-c_y+2, 0},
        { 0,-1, 1}
    };
    if(check_t(c_x + bias[move][0],c_y+ bias[move][1],(c_ori+ bias[move][2])%4,x,y))
    {
        c_x += bias[move][0];
        c_y += bias[move][1];
        c_ori=(c_ori+ bias[move][2])%4;
    }
    else if(check_t(c_x,c_y-1,c_ori,x,y))
    {
        c_y --;
    }
    else
    {
        assert(false);
    }
}

int main()
{

    int x,y,csize;
    cin >> x >> y;
    cin >> csize;
    int cs[csize];
    for(int i=0;i!=csize;i++)
        cin>>cs[i];
    int s_x = (x+1)/2 , s_y = y ,s_ori=0;
    for(int i=0;i!=csize;i++)
        safe_move(s_x ,s_y,s_ori,x,y,cs[i]);

    int maps[y][x];
    for(int i=0;i!=y;i++)
        for(int j=0;j!=x;j++)
            maps[i][j] = 0;

    for(int i=0;i!=4;i++)
    {
        int tar_x = s_x+t_bias[s_ori][i][0];
        int tar_y = s_y+t_bias[s_ori][i][1];
        maps[tar_y-1][tar_x-1] = 1;
    }

    for(int i=y-1;i>=0;i--)
    {
        for(int j=0;j!=x;j++)
            cout<< maps[i][j];
        cout << '\n';
    }

    return 0;
}
