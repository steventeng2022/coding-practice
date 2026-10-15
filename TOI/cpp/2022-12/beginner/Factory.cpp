// 2-工廠派遣 | 2022/12/26~2022/12/30 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202212/Factory.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202212/Factory.zip
#include <bits/stdc++.h>
#include<stdio.h>

int main()
{
    int n;
    int A[475]={},P[475]={};
    scanf("%d",&n);
    int need = n;
    for(int i=0;i<n;++i)
    {
        scanf("%d%d",&A[i],&P[i]);
    }
    int people,work_area=0;
    scanf("%d",&people);
    while(people>0 && need>0)
    {
        int mx = -1 , index = 0;
        for(int i=0;i<n;++i)
        {
            if(A[i]>mx)
            {
                mx = A[i];
                index = i;
            }
        }
        people -= P[index];
        A[index] = -1;
        work_area +=1;
        need-=1;
    }
    printf("%d\n",work_area);
}
