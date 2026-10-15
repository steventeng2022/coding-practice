# 3-湯圓

2026/03/16~2026/03/20 · 新手組

[官方題目](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202603/Tangyuan.pdf) · [官方參考資料](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202603/Tangyuan.zip) · [官方繁體中文詳解投影片](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202603/Tangyuan.odp)

以下思路、正確性與複雜度以本儲存庫的 Python 版為主；C++ 檔是官方參考實作，其資料結構與常數可能不同，並未逐題證明為最快。

## 解題思路

先分別加總芝麻與花生需求。對總需求 s，最少盒數為 ceil(s/10)，以整數公式 (s+9)//10 計算；剩餘數量是盒數乘 10 再減 s。

## 正確性

b 盒能供應 10b 顆，要求足夠等價於 b≥s/10。最小整數解就是上取整。選定最少盒數後，總供應扣掉需求即為剩餘。兩種口味不能互相代替，因此獨立計算。

## 複雜度

時間 O(N)，除讀入緩衝區外額外空間 O(1)。

## 實作注意

需求為 0 時應輸出 0 盒、剩 0 顆；需求剛好是 10 倍數時不必多買。

[C++ 程式](../../../cpp/2026-03/beginner/Tangyuan.cpp)

[Python 程式](../../../python/2026-03/beginner/Tangyuan.py)

驗證以 [狀態表](../../../STATUS.md) 與 [測試報告](../../../validation.json) 為準。範例通過不等同官方評測 AC；未做跨平台效能排名，沒有宣稱全球最快。
