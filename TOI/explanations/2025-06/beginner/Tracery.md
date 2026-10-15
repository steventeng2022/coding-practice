# 1-窗花

2025/06/09~2025/06/13 · 新手組

[官方題目](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202506/Tracery.pdf) · [官方參考資料](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202506/Tracery.zip) · [官方繁體中文詳解投影片](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202506/Tracery.odp)

以下思路、正確性與複雜度以本儲存庫的 Python 版為主；C++ 檔是官方參考實作，其資料結構與常數可能不同，並未逐題證明為最快。

## 解題思路

每列先接上左右鏡射的反向列，再將所有列由下往上重複一次，完成左右與上下對稱的四象限圖案。

## 正確性

對原圖每個座標 (r,c)，左右鏡射將其放到 (r,2W−1−c)，上下鏡射再產生對應的後半列。列內反轉與列順序反轉恰好實現這兩個映射，所以四個象限都正確。

## 複雜度

時間 O(WH)，空間 O(WH)，包含輸出。

## 實作注意

中線相鄰兩列與兩行都要保留，不能去重；原圖寬度在輸入的第一個數字。

[C++ 程式](../../../cpp/2025-06/beginner/Tracery.cpp)

[Python 程式](../../../python/2025-06/beginner/Tracery.py)

驗證以 [狀態表](../../../STATUS.md) 與 [測試報告](../../../validation.json) 為準。範例通過不等同官方評測 AC；未做跨平台效能排名，沒有宣稱全球最快。
