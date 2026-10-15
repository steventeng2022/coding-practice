// 3-舉旗遊戲 | 2020/12/28~2021/01/01 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202012/Flag.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202012/Flag.zip
#include <bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    int m, n;
    int student[110][110]={};
    cin>>m>>n;
    for(int i=1;i<=m;++i)
    {
        for(int j=1;j<=n;++j)
        {
            cin>>student[i][j];
        }
    }
    int find_s=0;
    int dir[8][2]={{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    for(int i=1;i<=m;++i)
    {
        for(int j=1;j<=n;++j)
        {
            int x = i, y = j;
            bool fail = true;
            for(int d=0;d<8;++d)
            {
                if(student[x][y]==student[x+dir[d][0]][y+dir[d][1]])
                {
                    fail=false;
                    break;
                }
            }
            if(fail)
            {
                find_s+=1;
            }
        }
    }
    cout<<find_s<<endl;
}
