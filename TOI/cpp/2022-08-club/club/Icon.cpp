// 龍捲風圖示 | 2022/08 新手同好會 | 新手同好會
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202208-OFFLINE/Icon.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202208-OFFLINE/Icon.zip
#include <bits/stdc++.h>
#include<stdio.h>

int main()
{
    char a[105][105]= {};
    int len,width;
    int dir[4][2]= {{1,0},{0,-1},{-1,0},{0,1}};
    scanf("%d%d",&len,&width);
    int x=0,y=0,way=0,edge=len,cnt=0;
    int turn=0;
    if(width==1)
    {
        for(int i=0; i<len; ++i)
        {
            for(int j=0; j<len; ++j)
            {
                a[i][j]=' ';
            }
        }
        for(int i=0; i<edge; ++i)
        {
            a[0][i]='*';
        }
        x=0;
        y=edge-1;
        edge-=1;
        while(edge>=1)
        {
            if(edge==1)
            {
                x+=dir[way][0];
                y+=dir[way][1];
                a[x][y] = '*';
                break;
            }
            else
            {
                x+=dir[way][0];
                y+=dir[way][1];
                a[x][y] = '*';
                cnt+=1;
                if(cnt==edge)
                {
                    way+=1;
                    cnt=0;
                    turn+=1;
                    if(turn==2)
                    {
                        turn=0;
                        edge-=2;
                    }
                }
                if(way>=4)
                {
                    way=0;
                }
            }
        }
    }
    else//draw space
    {
        for(int i=0; i<len; ++i)
        {
            for(int j=0; j<len; ++j)
            {
                a[i][j]='*';
            }
        }
        x=width;
        y=0;
        edge=len-width;
        for(int i=0; i<edge; ++i)
        {
            a[x][i]=' ';
        }
        y=edge-1;
        edge-=3;
        while(edge>=1)
        {
            x+=dir[way][0];
            y+=dir[way][1];
            a[x][y] = ' ';
            cnt+=1;
            if(cnt==edge)
            {
                way+=1;
                cnt=0;
                turn+=1;
                if(turn==2)
                {
                    turn=0;
                    edge-=3;
                }
            }
            if(way>=4)
            {
                way=0;
            }
        }
        if(len%3==0)
        {
            way+=1;
            x+=dir[way][0];
            y+=dir[way][1];
            a[x][y]=' ';
        }
        else if (len%3==1)
        {
            for(int i=0; i<2; ++i)
            {
                x+=dir[way][0];
                y+=dir[way][1];
                a[x][y]=' ';
                way+=1;
            }
        }
    }
    for(int i=0; i<len; ++i)
    {
        for(int j=0; j<len; ++j)
        {
            printf("%c",a[i][j]);
        }
        printf("\n");
    }
}
