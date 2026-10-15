# 2-水管

2025/04/28~2025/05/02 · 潛力組

[官方題目](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202504/Pipe.pdf) · [官方參考資料](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202504/Pipe.zip) · [官方繁體中文詳解投影片](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202504/Pipe.odp)

以下思路、正確性與複雜度以本儲存庫的 Python 版為主；C++ 檔是官方參考實作，其資料結構與常數可能不同，並未逐題證明為最快。

## 解題思路

把不交叉連接看成保序配對，類似加權最長共同子序列。dp[i][j] 是兩側前 i、j 個水管的最大流量；可略過左管、略過右管，或配對當前兩管並增加 min(A[i],B[j])。使用一維陣列與對角暫存壓縮空間。

## 正確性

若最佳解使用當前兩管，之前所有配對都位於前 i−1、j−1 範圍，否則會交叉；若未使用其中某管，就屬於略過該管的狀態。三個分支涵蓋全部合法解，取最大得到正確轉移。

## 複雜度

時間 O(N²)，額外 DP 空間 O(N)，總空間 O(N)。

## 實作注意

更新 dp[j] 前先保存舊值，才能保留下一格所需的上一列對角值。

[C++ 程式](../../../cpp/2025-04/advanced/Pipe.cpp)

[Python 程式](../../../python/2025-04/advanced/Pipe.py)

驗證以 [狀態表](../../../STATUS.md) 與 [測試報告](../../../validation.json) 為準。範例通過不等同官方評測 AC；未做跨平台效能排名，沒有宣稱全球最快。
