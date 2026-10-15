# 2-符文

2025/11/10~2025/11/14 · 新手組

[官方題目](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202511/Runes.pdf) · [官方參考資料](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202511/Runes.zip) · [官方繁體中文詳解投影片](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202511/Runes.odp)

## 解題思路

對整數序列使用 KMP。先建立模式的最長相同真前後綴長度陣列，失配時直接跳回仍可能匹配的前綴長度，不重新掃描書中已讀過的位置。

## 正確性

失配後，任何仍可能匹配的起點都必須對應已匹配部分的一個相同前後綴；failure 陣列依長度從大到小檢查這些候選，所以不漏掉合法匹配。掃描到第一個完整匹配立即返回，因此得到最早位置。

## 複雜度

時間 O(N+M)，空間 O(N+M)，含原始序列。

## 實作注意

輸出位置從 1 起算；找不到時字串必須精確為 not found。本版避免官方暴力比對的 O(NM) 最壞時間。

[C++ 程式](../../../cpp/2025-11/beginner/Runes.cpp)

[Python 程式](../../../python/2025-11/beginner/Runes.py)

驗證以 [狀態表](../../../STATUS.md) 與 [測試報告](../../../validation.json) 為準。範例通過不等同官方評測 AC；未做跨平台效能排名，沒有宣稱全球最快。
