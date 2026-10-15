// 1-字母排序 | 2019/11/25~2019/11/29 | 潛力組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201911/A1-Letters.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201911/A1-Letters.zip
#include <bits/stdc++.h>
#include<stdio.h>
#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
int main(){
    string rule,s;
    cin >> rule >> s;
    map<char,int>m;
    for(int i=0 ; i < rule.size() ; i+=1){
        m[rule[i]] = i;
    }
    int Count[30]={0};
    for(int i=0 ; i < s.size() ; i+=1 ){
        Count[m[s[i]]] += 1;
    }
    for(int i=1 ; i < rule.size() ; i+=1 ){
        Count[i] += Count[i-1];
    }
    int N = 0,num;
    cin >> N;
    while(N--){
        cin >> num;
        int temp = lower_bound(Count,Count+rule.size(),num) - Count;
        cout << rule[temp] << endl;
    }
}
