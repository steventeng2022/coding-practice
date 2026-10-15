// 2-座位安排 | 2019/05/27~2019/05/31 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201905/B2-Seats(Q).pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201905/B2-Seats.zip
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{
    int R,C,N;
    cin>>R>>C>>N;
    int arr[105][105]= {};
    int k=1;
    for(int i=0; i<R; i+=1)
    {
        for(int j=0; j<C; j+=1)
        {
            arr[i][j]=k;
            k+=1;
        }
    }

    N-=1;
    int right=0,back=0;
    if(N%2==0) right=N/2;
    else right=N/2+1;
    back=N/2;

    for(int a=0; a<right; a+=1)
    {
        for(int i=0; i<R; i+=1)
        {
            int temp=arr[i][C-1];
            for(int j=C-1; j>0; j-=1)
            {
                arr[i][j]=arr[i][j-1];
            }
            arr[i][0]=temp;
        }
    }
    for(int a=0; a<back; a+=1)
    {
        for(int j=0; j<C; j+=1)
        {
            int temp=arr[R-1][j];
            for(int i=R-1; i>0; i-=1)
            {
                arr[i][j]=arr[i-1][j];
            }
            arr[0][j]=temp;
        }
    }

    for(int i=0; i<R; i+=1)
    {
        for(int j=0; j<C; j+=1)
        {
            cout<<arr[i][j];
            if(j!=C-1) cout<<' ';
        }
        if(i!=R-1) cout<<endl;
    }
}
