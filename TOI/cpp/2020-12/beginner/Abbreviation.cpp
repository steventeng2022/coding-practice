// 2-英文縮寫 | 2020/12/28~2021/01/01 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202012/Abbreviation.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202012/Abbreviation.zip
#include <bits/stdc++.h>
#include<iostream>
#include<sstream>
#include<string>
#include<ctype.h>
using namespace std;
int main()
{
    string str;
    getline(cin, str);
    istringstream iss(str);

    string word;
    while(iss>>word)
    {
        for(int i=0;i<word.size();++i)
        {
            word[i] = toupper(word[i]);
        }
        if(word == "FOR") cout<<"4";
        else if(word == "YOU") cout<<"u";
        else if(word == "TO") cout<<"2";
        else if(word == "AND") cout<<"n";
        else cout<<word[0];
    }
    cout<<endl;
}
