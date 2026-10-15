# 3-平均值

2026/05/04~2026/05/08 · 潛力組

[官方題目](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202605/BeatAverage.pdf) · [官方參考資料](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202605/BeatAverage.zip) · [官方繁體中文詳解投影片](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202605/BeatAverage.odp)

## 解題思路

將 A、B 兩欄各自分塊，每塊保留原始值、排序值與總和。單點增加時在排序塊刪除舊值再插入新值。區間查詢先用完整塊總和與邊界零碎元素計算平均，再在完整排序塊二分搜尋大於平均的元素數量，邊界直接掃描。

## 正確性

塊總和與兩端零碎元素恰好無重疊覆蓋查詢區間，因此得到正確總和 S。整數 x 高於平均等價於 x>floor(S/L)，所以可用整數門檻避免浮點誤差。每塊排序陣列維護其真實元素多重集合，二分搜尋得到的數量與直接逐一比較相同。

## 複雜度

設塊寬 B≈√N，建置 O(N log B)，更新 O(B)，查詢 O(B+(N/B)log B)，空間 O(N)，另計輸入與輸出。

## 實作注意

B 欄只有初始值等於 500−A，後續兩欄更新互不影響。採 Python 向下整除處理負總和也能正確比較；C++ 若用截斷整除則需要另處理負數。

[C++ 程式](../../../cpp/2026-05/advanced/BeatAverage.cpp)

[Python 程式](../../../python/2026-05/advanced/BeatAverage.py)

驗證以 [狀態表](../../../STATUS.md) 與 [測試報告](../../../validation.json) 為準。範例通過不等同官方評測 AC；未做跨平台效能排名，沒有宣稱全球最快。
