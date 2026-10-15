# 2-午餐

2025/06/09~2025/06/13 · 新手組

[官方題目](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202506/Lunch.pdf) · [官方參考資料](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202506/Lunch.zip) · [官方繁體中文詳解投影片](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202506/Lunch.odp)

以下思路、正確性與複雜度以本儲存庫的 Python 版為主；C++ 檔是官方參考實作，其資料結構與常數可能不同，並未逐題證明為最快。

## 解題思路

依列優先順序掃描座位，與要找的名字完全相等時輸出座標。將扁平索引 i 轉為 i//C+1 與 i%C+1；完全找不到則輸出 0 0。

## 正確性

列優先掃描恰好檢查每個座位一次；座標公式與輸入排列方式一致，因此每個符合位置都被輸出且不會有不符合位置。

## 複雜度

時間 O(RC)，空間 O(RC)，包含輸入與可能的輸出。

## 實作注意

座標從 1 起算。字串比對區分大小寫，不應以部分字串判斷。

[C++ 程式](../../../cpp/2025-06/beginner/Lunch.cpp)

[Python 程式](../../../python/2025-06/beginner/Lunch.py)

驗證以 [狀態表](../../../STATUS.md) 與 [測試報告](../../../validation.json) 為準。範例通過不等同官方評測 AC；未做跨平台效能排名，沒有宣稱全球最快。
