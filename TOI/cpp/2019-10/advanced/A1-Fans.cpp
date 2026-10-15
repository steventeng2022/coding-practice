// 1-粉絲見面會 | 2019/10/21~2019/10/31 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201910/A1-Fans.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201910/A1-Fans.zip
#include <bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;
struct fans
{
    int ind=0;
    int donate=0;
}f[100005];
bool cmp(fans a,fans b)
{
    if(a.donate==b.donate) return a.ind<b.ind;
    return a.donate>b.donate;
}
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    for(int i=0;i<a;i+=1)
    {
        f[i].ind=i;
    }
    for(int j=0;j<b;j+=1)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        f[x].donate+=y;
    }
    sort(f,f+a,cmp);
    for(int i=0;i<a;i+=1)
    {
        printf("%d %d\n",f[i].ind,f[i].donate);
    }
}
