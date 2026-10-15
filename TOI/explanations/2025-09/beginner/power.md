# 1-指數

2025/09/29~2025/10/03 · 新手組

[官方題目](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202509/power.pdf) · [官方參考資料](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202509/power.zip) · [官方繁體中文詳解投影片](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202509/power.odp)

以下思路、正確性與複雜度以本儲存庫的 Python 版為主；C++ 檔是官方參考實作，其資料結構與常數可能不同，並未逐題證明為最快。

## 解題思路

從 N 的一次方開始，每次輸出當前值並乘以 N，直到超過 M。N 至少為 2，因此迴圈必定結束。

## 正確性

循環開始時 value=N^k，初始 k=1；乘以 N 後得到下一個正整數次方。所有次方嚴格遞增，所以超過 M 後後續也都超過，不會漏掉答案。

## 複雜度

以機器整數運算估計時間 O(log_N M)，輸出空間 O(log_N M)。

## 實作注意

只輸出正整數次方，不含 N^0=1；C++ 乘法前可檢查 value>M/N 以避免溢位。

[C++ 程式](../../../cpp/2025-09/beginner/power.cpp)

[Python 程式](../../../python/2025-09/beginner/power.py)

驗證以 [狀態表](../../../STATUS.md) 與 [測試報告](../../../validation.json) 為準。範例通過不等同官方評測 AC；未做跨平台效能排名，沒有宣稱全球最快。
