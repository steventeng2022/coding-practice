// 海底探險 | 2022/08 新手同好會 | 新手同好會
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202208-OFFLINE/Adventure.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202208-OFFLINE/Adventure.zip
#include <bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    int N;
    cin >> N;
    int arr[1005] = {};
    int maxi = -1;
    int tar1 = -1;
    int tar2 = -1;
    for(int i=0;i<N;++i)
    {
        cin >> arr[i];
        if(arr[i]>maxi)
        {
            maxi = arr[i];
            tar1 = i;
        }
    }
    if(tar1==N-1)
    {
        maxi = 1005;
        for(int i=N-2;i>0;--i)
        {
            if(arr[i]<maxi)
            {
                maxi = arr[i];
                tar2 = i;
            }
        }
    }
    else
    {
        maxi = -1;
        for(int i=tar1+1;i<N;++i)
        {
            if(arr[i]>maxi)
            {
                maxi = arr[i];
                tar2 = i;
            }
        }
    }
    int T;
    cin >> T;
    int ans[1005] = {};
    int position = 0;
    bool phase1 = true;
    for(int i=0;i<1001;++i)
    {
        ans[i] = position;
        if(arr[0]<arr[tar1])
        {
            arr[0]+=1;
        }
        else if(phase1)
        {
            position += 1;
            if(position==tar1)
            {
                phase1 = false;
            }
        }
        else if(position!=tar2)
        {
            if(tar2>position)
            {
                position += 1;
            }
            else
            {
                position -= 1;
            }
        }
    }
    cout << ans[T-1]+1 << endl;
}
