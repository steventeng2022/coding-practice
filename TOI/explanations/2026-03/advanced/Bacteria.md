# 1-細菌繁殖

2026/03/16~2026/03/20 · 潛力組

[官方題目](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202603/Bacteria.pdf) · [官方參考資料](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202603/Bacteria.zip) · [官方繁體中文詳解投影片](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202603/Bacteria.odp)

以下思路、正確性與複雜度以本儲存庫的 Python 版為主；C++ 檔是官方參考實作，其資料結構與常數可能不同，並未逐題證明為最快。

## 解題思路

把所有細菌起點依種類編號由小到大加入佇列，執行多源廣度優先搜尋。每輪只處理原有的一層，代表經過一分鐘；發現空格時立即標記佔領，避免其他細菌覆蓋。T 很大時也不用空轉，佇列空了就結束。

## 正確性

BFS 按擴散距離逐層處理，所以格子首先被最早能抵達的細菌佔領。初始佇列按編號排序，且每層依前一層順序加入新格，因此同一分鐘中編號小者先處理，符合同時抵達的優先規則。每個空格只加入佇列一次，計數恰好累積佔領格數。

## 複雜度

時間 O(MN+K)，空間 O(MN+K)，不隨 T 的數值線性增加。

## 實作注意

必須先按細菌編號排起點，不能直接使用格子掃描順序；標記要在入隊時執行。

[C++ 程式](../../../cpp/2026-03/advanced/Bacteria.cpp)

[Python 程式](../../../python/2026-03/advanced/Bacteria.py)

驗證以 [狀態表](../../../STATUS.md) 與 [測試報告](../../../validation.json) 為準。範例通過不等同官方評測 AC；未做跨平台效能排名，沒有宣稱全球最快。
