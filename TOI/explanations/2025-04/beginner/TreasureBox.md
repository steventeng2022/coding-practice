# 3-地底寶藏

2025/04/28~2025/05/02 · 新手組

[官方題目](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202504/TreasureBox.pdf) · [官方參考資料](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202504/TreasureBox.zip) · [官方繁體中文詳解投影片](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202504/TreasureBox.odp)

以下思路、正確性與複雜度以本儲存庫的 Python 版為主；C++ 檔是官方參考實作，其資料結構與常數可能不同，並未逐題證明為最快。

## 解題思路

先找最小值 X 以及出現位置。只出現一次，就由該位置往右移 X 格；有多次，就由最右出現位置往左移 X 格，讀出 Y。最後取從左數第 Y 個箱子的數字。

## 正確性

程式依三個線索依序實作；最小值多次出現時保留最右位置，正好套用反向規則。最後將 1 起算的 Y 轉成陣列索引 Y−1，得到密碼。

## 複雜度

時間 O(N)，空間 O(N)。

## 實作注意

依範例與官方程式，第二步是從最小值箱子的下一格起數，故索引偏移 X；第三步則是從最左箱子本身算第 1 個。

[C++ 程式](../../../cpp/2025-04/beginner/TreasureBox.cpp)

[Python 程式](../../../python/2025-04/beginner/TreasureBox.py)

驗證以 [狀態表](../../../STATUS.md) 與 [測試報告](../../../validation.json) 為準。範例通過不等同官方評測 AC；未做跨平台效能排名，沒有宣稱全球最快。
