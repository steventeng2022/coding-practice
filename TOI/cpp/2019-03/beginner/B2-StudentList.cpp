// 2-班級名單 | 2019/03/25~2019/03/29 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201903/B2-StudentList(Q).pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201903/B2-StudentList.zip
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{
    int n;
    int a,b,c;
    cin>>n;
    cin>>a>>b>>c;
    int j=1;
    for(int i=n;i>0;i-=1)
    {
        if(i!=a && i!=b && i!=c)
        {
            cout<<"No. "<<i;
            if(j<n-3)
            {
                cout<<endl;
                j+=1;
            }
        }
    }
}
