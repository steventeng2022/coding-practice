# 3-調香師

2026/06/8~2026/06/12 · 新手組

[官方題目](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202606/Perfumer.pdf) · [官方參考資料](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202606/Perfumer.zip) · [官方繁體中文詳解投影片](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202606/Perfumer.odp)

## 解題思路

預先建立「精油名稱 → 香調編號」雜湊表。讀取每次使用量時直接加到對應香調，不再逐一比對所有精油。最後依輸入順序尋找總量最大者。

## 正確性

每種精油只屬於一種香調，因此雜湊表給出的累加位置唯一正確。處理完所有使用紀錄後，每個桶的值就是該香調總量。Python 的 max 在鍵值相同時保留最早出現者，符合平手規則。

## 複雜度

設 S 為精油種類總數，時間期望 O(S+K+N)，空間 O(S+N)，另計輸入緩衝區；字串長度上限視為常數。

## 實作注意

平手選輸入較早的香調。官方參考程式逐一搜尋精油，本版改用雜湊查詢。

[C++ 程式](../../../cpp/2026-06/beginner/Perfumer.cpp)

[Python 程式](../../../python/2026-06/beginner/Perfumer.py)

驗證以 [狀態表](../../../STATUS.md) 與 [測試報告](../../../validation.json) 為準。範例通過不等同官方評測 AC；未做跨平台效能排名，沒有宣稱全球最快。
