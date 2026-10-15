// 字母排列 | 2019/08/16 新手同好會 | 新手同好會
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201908-onsite/4-Letters.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201908-onsite/4-Letters.zip
#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    cin>>str;

    int max_cnt=0,max_index=0;
    int len=int(str.size());
    for(int i=0;i<len;i+=1)
    {
        int cnt=1,index=len-1;
        while(str[i]+1==str[i+1] && i+1<len)
        {
            cnt+=1;
            if(cnt==2) index=i;
            i+=1;
        }
        if(cnt>=max_cnt)
        {
            max_cnt=cnt;
            max_index=index;
        }
    }

    cout<<max_cnt<<' ';
    for(int i=max_index;i<max_index+max_cnt;i+=1)
    {
        cout<<str[i];
    }
}
