// 3-商品擺設 | 2020/11/23~2020/11/27 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202011/Merchandise.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202011/Merchandise.zip
#include <bits/stdc++.h>
#include<stdio.h>

int main()
{
    int N=0,mer[200]={},num[200]={};
    scanf("%d",&N);
    for(int i=0;i<N;++i)
    {
        scanf("%d",&mer[i]);
    }
    for(int i=0;i<N;++i)
    {
        scanf("%d",&num[i]);
    }
    int flag1=0,flag2=0;
    for(int i=0;i<N;++i)
    {
        int count=0;
        if(mer[i]==-1)
        {
            flag1=i;
            int temp=i;
            if(temp+1==N)
            {
                break;
            }
            else
            {
                while(mer[temp+1]!=-1&&temp+1<N)
                {
                    count+=1;
                    temp+=1;
                }
                if(temp+1<N)
                {
                    flag2=temp+1;
                }
                else
                {
                    continue;
                }
            }
            if(count>=2)
            {
                int max=-5555,min=5555;
                int maxindex=-1,minindex=-1;
                for(int j=flag1;j<flag2;++j)
                {
                    if(mer[j]!=-1)
                    {
                        if(mer[j]>max)
                        {
                            max=mer[j];
                            maxindex=j;
                        }
                        if(mer[j]<min)
                        {
                            min=mer[j];
                            minindex=j;
                        }
                    }
                }
                int x=num[maxindex];
                num[maxindex]=num[minindex];
                num[minindex]=x;
            }
        }
    }
    for(int i=0;i<N;++i)
    {
        printf("%d ",num[i]);
    }
}
