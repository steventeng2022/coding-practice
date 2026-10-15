// 炸彈超人 | 2019/08/16 新手同好會 | 新手同好會
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201908-onsite/5-Bombs.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201908-onsite/5-Bombs.zip
#include <bits/stdc++.h>
#include<stdio.h>

int main()
{
    int n = 0;
    char map[101][101]={}; //原始地圖狀態
    char bomb[101][101]={};//爆炸後地圖狀態

    scanf("%d",&n);
    for(int i=0;i<n;i+=1){
        for(int j=0;j<n;j+=1)
            scanf(" %c",&map[i][j]);
    }

    //將爆炸後地圖預設為空格
    for(int i=0;i<n;i+=1){
        for(int j=0;j<n;j+=1)
            bomb[i][j]='0';
    }

    for(int i=0;i<n;i+=1)
    {
        for(int j=0;j<n;j+=1)
        {
            //偵測到炸彈
            if(map[i][j] == '*')
            {
                //炸彈周圍十字爆炸
                for(int k=0;k<n;k+=1)
                {
                    bomb[i][k] = '*';
                    bomb[k][j] = '*';
                }
            }
        }
    }

    //印出爆炸後地圖狀態
    for(int i=0;i<n;i+=1){
        for(int j=0;j<n;j+=1)
            printf("%c",bomb[i][j]);
        printf("\n");
    }
}
