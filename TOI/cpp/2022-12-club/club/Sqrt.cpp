// 根號 | 2022/12 新手同好會 | 新手同好會
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202212-OFFLINE/Sqrt.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202212-OFFLINE/Sqrt.zip
#include <bits/stdc++.h>
#include<stdio.h>

char area[501][2501] = {};
int dir[4][2]= {{0,1},{1,1},{-1,1}};

void draw_horizon(int *x, int *y, int *way, int len)
{
    for(int i=0; i<len-1; ++i)
    {
        area[*x][*y] = '*';
        *x += dir[*way][0];
        *y += dir[*way][1];
    }
    *way = 1;
}
void draw_v(int *x, int *y, int *way, int len)
{
    if(len%2==0)
    {
        for(int i=0; i<len/2-1; ++i)
        {
            area[*x][*y] = '*';
            *x += dir[*way][0];
            *y += dir[*way][1];
        }
        *way = 2;
    }
    else
    {
        for(int i=0; i<len/2; ++i)
        {
            area[*x][*y] = '*';
            *x += dir[*way][0];
            *y += dir[*way][1];
        }
        *way = 2;
    }
    for(int i=0; i<len-1; ++i)
    {
        area[*x][*y] = '*';
        *x += dir[*way][0];
        *y += dir[*way][1];
    }
    *way = 0;
}
int main()
{
    int len;
    scanf("%d",&len);
    int x = len/2, y=0,way = 0;
    for(int i=0; i<501; ++i)
    {
        for(int j=0; j<2501; ++j)
        {
            area[i][j] = ' ';
        }
    }
    draw_horizon(&x,&y,&way,len);
    draw_v(&x,&y,&way,len);
    draw_horizon(&x,&y,&way,len*2+1);
    int horizon = 4*len+(len+1)/2-3;
    for(int i=0; i<len; ++i)
    {
        for(int j=0; j<horizon; ++j)
        {
            printf("%c",area[i][j]);
        }
        printf("\n");
    }
}
