# 2-完美數

2025/09/29~2025/10/03 · 新手組

[官方題目](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202509/perfect.pdf) · [官方參考資料](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202509/perfect.zip) · [官方繁體中文詳解投影片](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202509/perfect.odp)

以下思路、正確性與複雜度以本儲存庫的 Python 版為主；C++ 檔是官方參考實作，其資料結構與常數可能不同，並未逐題證明為最快。

## 解題思路

題目要加總不包含 N 本身的正因數。先加入 1，再枚舉 2 到 floor(√N)，找到因數 d 時同時加入 N/d；完全平方數的平方根只加一次。

## 正確性

每個非平凡因數都能唯一配成 (d,N/d)，其中至少一個不超過 √N。枚舉較小者就能涵蓋全部配對，不含 N 本身；排除平方根重複後，累加值恰好是所有真因數和。

## 複雜度

時間 O(√N)，額外空間 O(1)。

## 實作注意

輸入保證 N≥2。平方根不可重複加；第一列輸出因數和，第二列才是判斷字串。

[C++ 程式](../../../cpp/2025-09/beginner/perfect.cpp)

[Python 程式](../../../python/2025-09/beginner/perfect.py)

驗證以 [狀態表](../../../STATUS.md) 與 [測試報告](../../../validation.json) 為準。範例通過不等同官方評測 AC；未做跨平台效能排名，沒有宣稱全球最快。
