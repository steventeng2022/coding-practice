// 3-石頭遊戲 | 2019/03/25~2019/03/29 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201903/A3-StoneGame(Q).pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201903/A3-StoneGame.zip
#include <bits/stdc++.h>
#include<bits/stdc++.h>
std::vector<int> v;
int SG[2000005]={};
void get_sg()
{
    int visit=1;
    for(int i=0;i<2000005;i+=1)
    {
        for(int j=0;j<(int)v.size();j+=1)
        {
            if(v[j]>i) break;
            else if(SG[i-v[j]]==0)
            {
                SG[i]=1;
                break;
            }
        }
        if(!visit)
        {
            SG[i]=1;
        }
    }
}
int main()
{
    int a;
    scanf("%d",&a);
    while(a--)
    {
        int x;
        scanf("%d",&x);
        v.push_back(x);
    }
    std::sort(v.begin(),v.end());
    get_sg();
    int T;
    scanf("%d",&T);
    int x;
    while(T--)
    {
        scanf("%d",&x);
        if(SG[x]==0) printf("Lose\n");
        else printf("Win!\n");
    }
}
