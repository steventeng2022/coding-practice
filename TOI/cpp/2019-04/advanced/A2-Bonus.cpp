// 2-獎金關卡 | 2019/04/22~2019/04/26 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201904/A2-Bonus(Q).pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201904/A2-Bonus.zip
#include <bits/stdc++.h>
#include<bits/stdc++.h>
int arr[1000005]={};
int DP[1000005]={};
using namespace std;
int main()
{
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i+=1)
    {
        scanf("%d",&arr[i]);
        if(i<2) DP[i]=arr[i];
        else if(i==2) DP[i]=arr[0]+arr[2];
        else DP[i]=max(DP[i-2]+arr[i],DP[i-3]+arr[i]);
    }
    printf("%d\n",max(DP[N-1],DP[N-2]));
}
