// 色彩轉換 | 2023/12 新手同好會 | 新手同好會
// 題目：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202312-OFFLINE/Color.pdf
// 官方參考程式（正規化編碼、換行並補齊標準標頭；額外修正另列）：https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202312-OFFLINE/Color.zip
#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int main()
{
    double r, g, b;
    cin >> r >> g >> b;
    double h, s, l;
    r /= 255;
    g /= 255;
    b /= 255;
    double MAX = std::max(r, std::max(b, g));
    double MIN = std::min(r, std::min(b, g));
    // h
    if (MAX == MIN)
        h = 0;
    else if (MAX == r && g >= b)
        h = 60 * (g - b) / (MAX - MIN);
    else if (MAX == r && g < b)
        h = 60 * (g - b) / (MAX - MIN) + 360;
    else if (MAX == g)
        h = 60 * (b - r) / (MAX - MIN) + 120;
    else if (MAX == b)
        h = 60 * (r - g) / (MAX - MIN) + 240;
    // l
    l = (MAX + MIN) / 2;
    // s
    if (l == 0 || MAX == MIN)
        s = 0;
    else if (l > 0 && l <= 0.5)
        s = (MAX - MIN) / (2 * l);
    else
        s = (MAX - MIN) / (2 - 2 * l);
//
    cout << setprecision(0) << fixed << h << " " << s * 255 << " " << l * 255 << endl;
}
