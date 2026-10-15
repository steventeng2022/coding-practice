# 2-滑雪場

2025/03/17~2025/03/21 · 潛力組

[官方題目](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202503/Ski.pdf) · [官方參考資料](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202503/Ski.zip) · [官方繁體中文詳解投影片](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202503/Ski.odp)

以下思路、正確性與複雜度以本儲存庫的 Python 版為主；C++ 檔是官方參考實作，其資料結構與常數可能不同，並未逐題證明為最快。

## 解題思路

固定右端 i，記錄最近一次超出 [L,H] 的位置 bad，以及最近的 L、H 出現位置。合法左端必須大於 bad，且不大於 min(lastL,lastH)，此範圍整數數量就是以 i 結尾的合法區間數。

## 正確性

不包含超界值保證區間所有值介於 L、H；同時包含至少一個 L 與 H，則最小值與最大值恰為指定上下界。上述兩個左端條件各自必要且合起來充分，因此對每個右端累加不會漏算或重算。

## 複雜度

時間 O(N)，除讀入緩衝區外額外空間 O(1)。

## 實作注意

L=H 時同一位置可以同時更新兩個最後出現位置。區間數可達 N(N+1)/2，C++ 使用 64 位元答案。

[C++ 程式](../../../cpp/2025-03/advanced/Ski.cpp)

[Python 程式](../../../python/2025-03/advanced/Ski.py)

驗證以 [狀態表](../../../STATUS.md) 與 [測試報告](../../../validation.json) 為準。範例通過不等同官方評測 AC；未做跨平台效能排名，沒有宣稱全球最快。
