# 1-雷射探測

2026/06/8~2026/06/12 · 新手組

[官方題目](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202606/Laser.pdf) · [官方參考資料](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202606/Laser.zip) · [官方繁體中文詳解投影片](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202606/Laser.odp)

## 解題思路

把雷射視為狀態 (列、行、方向)，由左上角向右逐步模擬。用每格四個位元記錄已處理的方向，另計算首次經過的格子數。右斜鏡將方向編號 xor 3，左斜鏡則 xor 1。到達新格後才套用該格的鏡子。

## 正確性

每一步都依照當前方向前進一格，並依新格的鏡子更新方向，因此模擬路徑與題意相同。每格第一次處理才加一，故重訪不會重複計數；障礙物在計數前排除。若同一位置與方向再次出現，往後路徑必定重複，已不可能遇到新格，可以停止。

## 複雜度

時間 O(NM)，空間 O(NM)，最多處理 4NM 個狀態。

## 實作注意

不能只用「格子走過」決定停止，因為不同方向通過同一格仍可能走向新區域；牆壁不列入答案。

[C++ 程式](../../../cpp/2026-06/beginner/Laser.cpp)

[Python 程式](../../../python/2026-06/beginner/Laser.py)

驗證以 [狀態表](../../../STATUS.md) 與 [測試報告](../../../validation.json) 為準。範例通過不等同官方評測 AC；未做跨平台效能排名，沒有宣稱全球最快。
