# 3-整數分拆

2025/09/29~2025/10/03 · 潛力組

[官方題目](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202509/partition.pdf) · [官方參考資料](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202509/partition.zip) · [官方繁體中文詳解投影片](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202509/partition.odp)

以下思路、正確性與複雜度以本儲存庫的 Python 版為主；C++ 檔是官方參考實作，其資料結構與常數可能不同，並未逐題證明為最快。

## 解題思路

把整數盡可能拆成 3，餘 2 就保留一個 2，餘 1 則將一個 3 與 1 改成 2+2。用模快速冪計算大量 3 的乘積。題目允許不拆，因此 1、2、3 直接回傳本身。

## 正確性

大於等於 5 的部分可拆成 3 與 x−3，乘積不減且在 x≥5 時增加；1 與 3 相鄰可改為 2+2，乘積由 3 增至 4；三個 2 可改成兩個 3，乘積由 8 增至 9。因此最優解由盡可能多的 3 與至多兩個 2 構成，對應三種餘數分類。

## 複雜度

每筆 O(log x)，共 O(T log x_max)；除輸入輸出外額外空間 O(1)。

## 實作注意

先求最大整數乘積的結構，最後才取模；不能拿取模後數值比較大小。

[C++ 程式](../../../cpp/2025-09/advanced/partition.cpp)

[Python 程式](../../../python/2025-09/advanced/partition.py)

驗證以 [狀態表](../../../STATUS.md) 與 [測試報告](../../../validation.json) 為準。範例通過不等同官方評測 AC；未做跨平台效能排名，沒有宣稱全球最快。
