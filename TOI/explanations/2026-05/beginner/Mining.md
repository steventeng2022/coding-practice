# 3-礦業調度

2026/05/04~2026/05/08 · 新手組

[官方題目](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202605/Mining.pdf) · [官方參考資料](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202605/Mining.zip) · [官方繁體中文詳解投影片](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202605/Mining.odp)

## 解題思路

地點 i（從 0 起算）的初始淨收益為金量減 i；連續開採該地的收益依序遞減 1。把所有正收益視為多條遞減數列，答案是其中最大的 M 項。先將初值降序排序，將目前最高的若干地點一起削平到下一個高度，整段以等差級數求和；最後不足一整層時用商與餘數計算。

## 正確性

同一地點較低收益項被選到時，前面更高的項必定先被選到，所以全域最大的 M 項一定構成合法開採順序。排序後，前 i 個地點削平到下一高度時，所消耗的項數與總收益都可精確計算。逐層處理即等價於每次挑最大淨收益，收益非正時停止。

## 複雜度

時間 O(N log N)，空間 O(N)，不依賴 M 的迴圈次數。

## 實作注意

計算移動成本時索引從 0 開始；收益小於等於 0 時不用挖。等差級數與答案在 C++ 應使用 64 位元整數。

[C++ 程式](../../../cpp/2026-05/beginner/Mining.cpp)

[Python 程式](../../../python/2026-05/beginner/Mining.py)

驗證以 [狀態表](../../../STATUS.md) 與 [測試報告](../../../validation.json) 為準。範例通過不等同官方評測 AC；未做跨平台效能排名，沒有宣稱全球最快。
