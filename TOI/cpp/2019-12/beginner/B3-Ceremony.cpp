// 3-畢業典禮 | 2019/12/23~2019/12/27 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201912/B3-Ceremony.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201912/B3-Ceremony-nosort.zip
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{
    char pAcademy[10]={"AEHILMOST"};
    char Grade[3]={'4','6','8'};
    int N;
    cin>>N;

    char id[100][10]={}, name[100][11]={};
    for(int i=0; i<N; i+=1)
    {
        cin>>id[i]>>name[i];
    }

    bool check[100]={false};  //是否印出過了
    int sNum=0; //已印出的人數
    for(int i=0; i<9; i+=1)
    {
        for(int j=0; j<3; j+=1)
        {
            for(int s=0; s<N; s+=1)
            {
                if(check[s]==false)
                {
                    if(id[s][0]==Grade[j] && id[s][8]==pAcademy[i])
                    {
                        cout<<id[s][8]<<": "<<name[s]<<endl;
                        sNum+=1;
                        check[s]=true;
                        if(sNum==N)
                        {
                            return 0;
                        }
                    }
                }
            }
        }
    }
}
