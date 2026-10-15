// 2-鏡像對稱 | 2023/12/25~2023/12/29 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202312/Mirror.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202312/Mirror.zip
#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    cin >> str;
    string symmetry = "AHIMOTUVWXY";
    bool isYes = true;
    for(size_t i = 0; i < str.size(); ++i)
    {
        bool isSymmetry = false;
        for(size_t j = 0; j < symmetry.size(); ++j)
        {
            if(str[i] == symmetry[j])
            {
                isSymmetry = true;
                break;
            }
        }
        if(!isSymmetry)
        {
            isYes = false;
            break;
        }
    }
    for(size_t i = 0; i < str.size()/2; ++i)
    {
        if(str[i] != str[str.size()-1-i])
        {
            isYes = false;
            break;
        }
    }
    if(isYes)
        cout << "Yes" <<endl;
    else
        cout << "No" << endl;
    return 0;
}
