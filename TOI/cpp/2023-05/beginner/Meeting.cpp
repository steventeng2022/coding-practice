// 1-會議安排 | 2023/05/29~2023/06/02 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202305/Meeting.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202305/Meeting.zip
#include <bits/stdc++.h>
#include <stdio.h>

int main()
{
    int n,m;
    scanf("%d%d", &n, &m);
    int a[n][2];
    int b[m][2];
    for(int i=0;i<n;++i)
    {
        scanf("%d%d",&a[i][0],&a[i][1]);
    }
    for(int i=0;i<m;++i)
    {
        scanf("%d%d",&b[i][0],&b[i][1]);
    }
    int d;
    scanf("%d",&d);
    int st=-1, ed=-1;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if (a[i][1] >= b[j][0] && a[i][0] <= b[j][1])
            {
                st = (a[i][0]>b[j][0])?a[i][0]:b[j][0];
                ed = (a[i][1]<b[j][1])?a[i][1]:b[j][1];
                if (ed-st >= d)
                {
                    printf("%d %d\n",st,st+d);
                    return 0;
                }
            }
        }
    }
    printf("-1\n");
    return 0;
}
