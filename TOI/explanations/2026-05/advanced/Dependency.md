# 1-檢查答案

2026/05/04~2026/05/08 · 潛力組

[官方題目](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202605/Dependency.pdf) · [官方參考資料](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202605/Dependency.zip) · [官方繁體中文詳解投影片](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202605/Dependency.odp)

## 解題思路

將已知的先後關係建成有向圖，使用 Kahn 拓樸排序。每一步都只有一個入度為 0 的候選時，順序被唯一決定；只要出現兩個候選，便有不只一種合法順序。依題目約定，唯一時輸出 0，否則輸出 1。

## 正確性

入度為 0 代表所有前置條件都已滿足。若同時有兩個候選，兩者沒有尚未處理的先後限制，可以交換取出順序，故答案不唯一。反之每一步都只有一個選擇，就能用歸納法得到唯一完整順序。處理數不足 N 表示圖中有環，沒有合法完整順序。

## 複雜度

時間 O(N+M)，空間 O(N+M)。

## 實作注意

本版使用迭代拓樸排序，避免長鏈造成 Python 遞迴深度溢位。注意題目 0 與 1 的輸出意義。

[C++ 程式](../../../cpp/2026-05/advanced/Dependency.cpp)

[Python 程式](../../../python/2026-05/advanced/Dependency.py)

驗證以 [狀態表](../../../STATUS.md) 與 [測試報告](../../../validation.json) 為準。範例通過不等同官方評測 AC；未做跨平台效能排名，沒有宣稱全球最快。
