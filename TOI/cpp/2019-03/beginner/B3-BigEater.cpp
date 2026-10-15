// 3-大吃大喝 | 2019/03/25~2019/03/29 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201903/B3-BigEater(Q).pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201903/B3-BigEater.zip
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{
    int n,m,k;
    cin>>n>>m>>k;

    int time=0,check=0;
    if((n<32)||(k==1 && n<55))
    {
        cout<<"Wayne can't eat and drink."<<endl;
        check=1;
    }
    while(n>=0 && check==0)
    {
        if(k==0)
        {
            if(n>=32)
            {
                n-=32;
                cout<<time<<": Wayne eats an Apple pie, ";
                k=1;
            }
            else break;

        }
        else if(k==1)
        {
            if(n>=55)
            {
                n-=55;
                cout<<time<<": Wayne drinks a Corn soup, ";
                k=0;
            }
            else break;
        }
        if(n>1) cout<<"and now he has "<<n<<" dollars."<<endl;
        else if(n==1) cout<<"and now he has 1 dollar."<<endl;
        else if(n==0) cout<<"and now he doesn't have money."<<endl;
        time+=m;
    }
    return 0;
}
