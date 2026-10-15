# 1-萬有引力

2025/03/17~2025/03/21 · 新手組

[官方題目](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202503/Gravitation.pdf) · [官方參考資料](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202503/Gravitation.zip) · [官方繁體中文詳解投影片](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202503/Gravitation.odp)

以下思路、正確性與複雜度以本儲存庫的 Python 版為主；C++ 檔是官方參考實作，其資料結構與常數可能不同，並未逐題證明為最快。

## 解題思路

直接代入題目簡化後的引力公式，分子為 6m1m2，分母為 r²，以整數除法取題目要求的整數部分。

## 正確性

所有輸入為正值，因此整數除法恰好等於非負結果的向下取整。先組合完整分子與分母可避免中間浮點誤差。

## 複雜度

時間 O(1)，空間 O(1)。

## 實作注意

距離要平方；不要用 Python round，題目不是四捨五入。

[C++ 程式](../../../cpp/2025-03/beginner/Gravitation.cpp)

[Python 程式](../../../python/2025-03/beginner/Gravitation.py)

驗證以 [狀態表](../../../STATUS.md) 與 [測試報告](../../../validation.json) 為準。範例通過不等同官方評測 AC；未做跨平台效能排名，沒有宣稱全球最快。
