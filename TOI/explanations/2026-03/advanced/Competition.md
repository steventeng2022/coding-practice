# 3-三仙鬥法

2026/03/16~2026/03/20 · 潛力組

[官方題目](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202603/Competition.pdf) · [官方參考資料](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202603/Competition.zip) · [官方繁體中文詳解投影片](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202603/Competition.odp)

以下思路、正確性與複雜度以本儲存庫的 Python 版為主；C++ 檔是官方參考實作，其資料結構與常數可能不同，並未逐題證明為最快。

## 解題思路

每回合三人的數值都加或減 1，所以三者奇偶性同時翻轉，誰與另兩人奇偶性不同永遠不變。若存在此人，只輸出該人的學院；若三人奇偶性相同，輸出 A B C。完全不必模擬高達 10^18 的靈氣值。

## 正確性

終局有兩個值為 0；若初始有唯一奇偶不同者，終局仍是此人與另外兩人奇偶不同，所以他必須是唯一正值者。若三人初始同奇偶，先依大小排序：最大與最小差至少 2 時，一回合差值不增；若最小值並列而差值未降，下一回合便會下降。故最後到達差小於 2 的狀態。同奇偶又使差值必為偶數，因此先到達三值相等。此時規則對三個標號完全對稱，三者勝率相同。

## 複雜度

時間 O(R)，每輪 O(1)；除輸入與輸出緩衝區外額外空間 O(1)。

## 實作注意

Python 整數可處理 10^18，C++ 應使用 long long。位元判斷與相等比較混用時，C++ 的括號不可省略。

[C++ 程式](../../../cpp/2026-03/advanced/Competition.cpp)

[Python 程式](../../../python/2026-03/advanced/Competition.py)

驗證以 [狀態表](../../../STATUS.md) 與 [測試報告](../../../validation.json) 為準。範例通過不等同官方評測 AC；未做跨平台效能排名，沒有宣稱全球最快。
