# 1-食譜換算

2025/04/28~2025/05/02 · 新手組

[官方題目](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202504/Recipe.pdf) · [官方參考資料](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202504/Recipe.zip) · [官方繁體中文詳解投影片](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202504/Recipe.odp)

以下思路、正確性與複雜度以本儲存庫的 Python 版為主；C++ 檔是官方參考實作，其資料結構與常數可能不同，並未逐題證明為最快。

## 解題思路

原食材重量乘以新份數，再除以原份數；不足整數重量時向上取整，以確保足量。正整數上取整可寫成 (分子+分母−1)//分母。

## 正確性

食材與份數成正比，精確需求為 weight×wanted/portions。最小且不少於需求的整數就是此比例的上取整，逐項計算即符合要求。

## 複雜度

時間 O(N)，空間 O(N)，包含讀入與輸出緩衝區。

## 實作注意

先乘再除，不能先把每份重量取整；C++ 應注意乘法的整數範圍。

[C++ 程式](../../../cpp/2025-04/beginner/Recipe.cpp)

[Python 程式](../../../python/2025-04/beginner/Recipe.py)

驗證以 [狀態表](../../../STATUS.md) 與 [測試報告](../../../validation.json) 為準。範例通過不等同官方評測 AC；未做跨平台效能排名，沒有宣稱全球最快。
