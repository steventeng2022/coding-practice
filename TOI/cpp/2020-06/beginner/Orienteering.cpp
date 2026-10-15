// 2-定向越野 | 2020/06/29~2020/07/03 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202006/Orienteering.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202006/Orienteering.zip
#include <bits/stdc++.h>
#include<stdio.h>

int main()
{
    int W=0,H=0,N=0,counter=0;
    scanf("%d%d",&W,&H);
    scanf("%d",&N);
    int exists[26]={},pos[26][2]={};
    char maze[30][30]= {};
    for(int i=0;i<W;++i)
    {
        for(int j=0;j<H;++j)
        {
            scanf(" %c",&maze[i][j]);
            if(maze[i][j]!='0')
            {
                exists[maze[i][j]-'a']=1;
                pos[maze[i][j]-'a'][0]=i;
                pos[maze[i][j]-'a'][1]=j;
                counter+=1;
            }
        }
    }
    if(counter<N)
    {
        printf("Mission fail.\n");
    }
    else
    {
        int cn=0;
        for(int i=0;i<26;++i)
        {
            if(exists[i]==1)
            {
                printf("%d %d\n",pos[i][0],pos[i][1]);
                cn+=1;
                if(cn==N)
                {
                    break;
                }
            }
        }
    }
}
