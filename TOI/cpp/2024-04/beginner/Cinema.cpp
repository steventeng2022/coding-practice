// 1-電影院 | 2024/04/29~2024/05/03 | 新手組
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202404/Cinema.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202404/Cinema.zip
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdio.h>
using namespace std;

// 定義電影開始時間的結構
struct MovieTime {
    int hour, minute;
};

// 轉換時間為分鐘
int toMinutes(int hour, int minute) {
    return hour * 60 + minute;
}

int main() {
    int N; // 電影數量
    vector<MovieTime> movieTimes; // 電影時刻表

    // 讀取電影數量
    cin >> N;

    // 讀取電影開始時間
    for (int i = 0; i < N; ++i) {
        int movieHour, movieMinute;
        cin >> movieHour >> movieMinute;
        movieTimes.push_back({movieHour, movieMinute});
    }

    // 讀取當前時間和電影數量
    int currentHour, currentMinute;
    cin >> currentHour >> currentMinute;

    // 將當前時間轉換為分鐘
    int currentTimeInMinutes = toMinutes(currentHour, currentMinute);

    // 尋找最早可以觀看的電影時刻
    for (auto& movieTime : movieTimes) {
        int movieTimeInMinutes = toMinutes(movieTime.hour, movieTime.minute);
        // 需要至少15分鐘的準備時間
        if (movieTimeInMinutes - currentTimeInMinutes >= 20) {
            cout << movieTime.hour << " " << movieTime.minute << endl;
            return 0;
        }
    }

    cout << "Too Late" << endl; // 找不到合適的電影時刻
    return 0;
}
