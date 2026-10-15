# 1-棟距

2025/12/22~2025/12/26 · 潛力組

[官方題目](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202512/Spacing.pdf) · [官方參考資料](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202512/Spacing.zip) · [官方繁體中文詳解投影片](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202512/Spacing.odp)

以下思路、正確性與複雜度以本儲存庫的 Python 版為主；C++ 檔是官方參考實作，其資料結構與常數可能不同，並未逐題證明為最快。

## 解題思路

分別由左、由右用高度單調不增的堆疊，找每棟樓最近的「高度大於或等於自己」的大樓，兩側距離取最小。沒有此類大樓時以 N 表示。預處理完成後每筆詢問 O(1)。

## 正確性

比當前樓矮的堆疊頂元素，既不能擋住當前樓，日後對更右側的大樓也不會比當前樓更合適，因此可移除。移除後頂端是左側最近且足夠高的大樓；反向掃描同理。最近阻擋者必在左或右其中之一，取較短距離正確。

## 複雜度

時間 O(N+M)，空間 O(N)。每個索引每次掃描最多進出堆疊一次。

## 實作注意

相同高度也算阻擋，pop 條件是嚴格小於。大樓編號從 0 起算。

[C++ 程式](../../../cpp/2025-12/advanced/Spacing.cpp)

[Python 程式](../../../python/2025-12/advanced/Spacing.py)

驗證以 [狀態表](../../../STATUS.md) 與 [測試報告](../../../validation.json) 為準。範例通過不等同官方評測 AC；未做跨平台效能排名，沒有宣稱全球最快。
