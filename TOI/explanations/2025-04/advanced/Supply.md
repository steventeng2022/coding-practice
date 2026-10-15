# 3-供給調度

2025/04/28~2025/05/02 · 潛力組

[官方題目](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202504/Supply.pdf) · [官方參考資料](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202504/Supply.zip) · [官方繁體中文詳解投影片](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202504/Supply.odp)

以下思路、正確性與複雜度以本儲存庫的 Python 版為主；C++ 檔是官方參考實作，其資料結構與常數可能不同，並未逐題證明為最快。

## 解題思路

指定前 t 筆調升後，用 Kruskal 求該時刻的最小生成樹總成本。所有成本只會增加，所以最小生成樹成本也單調不減；對「是否嚴格超過 K」二分搜尋首次成立的 t。先檢查全部調升後是否仍未超標，若是則無解。

## 正確性

連通所有倉庫的最低維護成本等於最小生成樹。對任意固定生成樹，增加邊權不會讓它變便宜；對所有生成樹取最小值後仍不會下降，故判斷函數具有二分所需的單調性。Kruskal 每次給出真實最小值，因此二分邊界即首次超標時刻。

## 複雜度

時間 O((Q+M log M)log(Q+1))，空間 O(N+M+Q)。

## 實作注意

必須是嚴格大於 K。答案可能為 0 或 −1；不可嘗試讀取第 Q+1 筆調升。多次調升同一條邊要累加。

[C++ 程式](../../../cpp/2025-04/advanced/Supply.cpp)

[Python 程式](../../../python/2025-04/advanced/Supply.py)

驗證以 [狀態表](../../../STATUS.md) 與 [測試報告](../../../validation.json) 為準。範例通過不等同官方評測 AC；未做跨平台效能排名，沒有宣稱全球最快。
