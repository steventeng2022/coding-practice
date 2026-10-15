# 3-找數字

2025/03/17~2025/03/21 · 新手組

[官方題目](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202503/Numbers.pdf) · [官方參考資料](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202503/Numbers.zip) · [官方繁體中文詳解投影片](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202503/Numbers.odp)

以下思路、正確性與複雜度以本儲存庫的 Python 版為主；C++ 檔是官方參考實作，其資料結構與常數可能不同，並未逐題證明為最快。

## 解題思路

質數由 N+1 起逐一試除檢查；平方數直接用整數平方根取得下一個平方；立方根則以整數二分搜尋找出第一個立方大於 N 的底數。

## 正確性

合數必有不超過平方根的質因數，因此試除能正確判質數，首個通過者就是答案。floor(√N)+1 是第一個平方大於 N 的底數。立方單調遞增，二分維持左端立方不大於 N、右端立方大於 N，因此結束時右端最小。

## 複雜度

令 p 為下一個質數，時間 O((p−N)√p+log N)，額外空間 O(1)。此處保留可驗證的試除法，未宣稱質數測試最快。

## 實作注意

三個答案都要求嚴格大於 N；使用整數平方根與整數二分可避免浮點開根誤差。

[C++ 程式](../../../cpp/2025-03/beginner/Numbers.cpp)

[Python 程式](../../../python/2025-03/beginner/Numbers.py)

驗證以 [狀態表](../../../STATUS.md) 與 [測試報告](../../../validation.json) 為準。範例通過不等同官方評測 AC；未做跨平台效能排名，沒有宣稱全球最快。
