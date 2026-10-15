# 1-串燒

2025/12/22~2025/12/26 · 新手組

[官方題目](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202512/BBQ.pdf) · [官方參考資料](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202512/BBQ.zip) · [官方繁體中文詳解投影片](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202512/BBQ.odp)

以下思路、正確性與複雜度以本儲存庫的 Python 版為主；C++ 檔是官方參考實作，其資料結構與常數可能不同，並未逐題證明為最快。

## 解題思路

分別統計各品項上桌與訂購的數量。每種品項若訂購較多，差值計入漏上；若上桌較多，差值計入多上。

## 正確性

不同品項不能互相抵銷，逐品項差值的正負部分分別就是缺少與多出的數量。Counter 的減法僅保留正差，兩個方向各減一次即可得到兩種總數。

## 複雜度

設訂購總數為 S、品項範圍為 U，時間 O(N+S+U)，空間 O(U)，另計輸入。

## 實作注意

要先逐品項比較，不能只比較上桌與訂購總數；輸出順序為漏上、多上。

[C++ 程式](../../../cpp/2025-12/beginner/BBQ.cpp)

[Python 程式](../../../python/2025-12/beginner/BBQ.py)

驗證以 [狀態表](../../../STATUS.md) 與 [測試報告](../../../validation.json) 為準。範例通過不等同官方評測 AC；未做跨平台效能排名，沒有宣稱全球最快。
