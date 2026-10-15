// 排課表 | 2019/12/14 新手同好會 | 新手同好會
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201912-onsite/8-Schedule.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/201912-onsite/8-Schedule.zip
#include <bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;
struct Class{
    int date = 0;
    int start = 0;
    int end = 0;
};
bool cmp(Class a , Class b){
    if(a.date != b.date)return a.date < b.date;
    else{
        return a.end < b.end;
    }
}
Class classes[100005];
int main(){
    int N;
    cin >> N;
    int class_num = 0;
    memset(classes, 0 , sizeof(classes));
    for(int i = 0 ; i < N; i += 1 ){
        int d,s,t;
        cin >> d >> s >> t ;
        classes[class_num].date = d;
        classes[class_num].start = s;
        classes[class_num++].end = t;
    }
    sort(classes,classes+class_num,cmp);
    int last = 0,ans = 0;
    for(int i = 0 ; i < class_num ; i += 1 ){
        if(i != 0 && classes[i].date != classes[i-1].date){
            last = 0;
        }
        if(last <= classes[i].start){
            ans += 1;
            last = classes[i].end;
        }
    }
    cout << ans << endl;
}
