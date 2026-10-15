// 2-單字找找看 | 2022/05/30~2022/06/05 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202205/Word.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202205/Word.zip
#include <bits/stdc++.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
    int r,c;
    int mp[100][100]= {};
    int dir[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
    scanf("%d%d",&r,&c);
    for(int i=1; i<=r; ++i)
    {
        for(int j=1; j<=c; ++j)
        {
            scanf(" %c",&mp[i][j]);
            mp[i][j] = tolower(mp[i][j]);
        }
    }
    for(int i=0; i<=r+1; ++i)
    {
        for(int j=0; j<=c+1; ++j)
        {
            if(i==0 || j==0 || i==r+1 || j==c+1)
            {
                mp[i][j] = '.';
            }
        }
    }
    char word[100]= {};
    scanf("%s",word);
    int len=strlen(word);
    for(int i=0;i<len;++i)
    {
        word[i] = tolower(word[i]);
    }
    int tx=-1,ty=-1,ex=-1,ey=-1;
    int ans=0;
    bool fnd=false;
    if(len==1)
    {
        for(int i=1; i<=r; ++i)
        {
            for(int j=1; j<=c; ++j)
            {
                if(mp[i][j]==word[0])
                {
                    tx=i;
                    ex=i;
                    ty=j;
                    ey=j;
                    fnd=true;
                    break;
                }
            }
            if(fnd==true)
                break;
        }
    }
    else
    {
        for(int i=1; i<=r; ++i)
        {
            for(int j=1; j<=c; ++j)
            {
                ans=0;
                if(mp[i][j]==word[0])
                {
                    for(int k=0; k<8; ++k)
                    {
                        int flag=1;
                        for(int c=1; c<len; ++c)
                        {
                            if(mp[ i+dir[k][0]*c ][ j + dir[k][1]*c ] != word[c] )
                            {
                                break;
                            }
                            if(c==len-1)
                            {
                                ex=i+dir[k][0]*c;
                                ey=j+dir[k][1]*c;
                            }
                            flag+=1;
                        }
                        if(flag==len)
                        {
                            ans=1;
                            tx=i;
                            ty=j;
                            break;
                        }
                    }
                }
                if(ans==1)
                    break;
            }
            if(ans==1)
                break;
        }
    }
    if(fnd==true)
        printf("%d %d\n%d %d\n",tx,ty,ex,ey);
    else if(ans==1)
        printf("%d %d\n%d %d\n",tx,ty,ex,ey);
    else
        printf("NO\n");
}
