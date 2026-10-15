// 1-分組 | 2020/10/26~2020/10/30 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202010/Grouping.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202010/Grouping.zip
#include <bits/stdc++.h>
#include<stdio.h>

int main()
{
    int N=0,P=0;
    scanf("%d%d",&N,&P);
    int temp=P;
    int max_num=-1,flag=1,team_no=0;
    while(temp)
    {
        int sum=0;
        for(int i=0;i<N;++i)
        {
            int x=temp%10;
            sum+=x;
            temp/=10;
        }
        if(sum>=max_num)
        {
            team_no=flag;
            max_num=sum;
        }
        flag+=1;
    }
    printf("%d %d\n",team_no,max_num);
}
