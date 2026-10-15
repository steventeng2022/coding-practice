# 1-樂透

2025/11/10~2025/11/14 · 新手組

[官方題目](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202511/Lotto.pdf) · [官方參考資料](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202511/Lotto.zip) · [官方繁體中文詳解投影片](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202511/Lotto.odp)

以下思路、正確性與複雜度以本儲存庫的 Python 版為主；C++ 檔是官方參考實作，其資料結構與常數可能不同，並未逐題證明為最快。

## 解題思路

以集合交集計算一般號碼命中數，再檢查特別號是否在彩券中。將「一般命中數、是否中特別號」對照題目獎項表。

## 正確性

一般號碼與特別號分開判斷，這兩個統計量已完整決定獎項。查表涵蓋 A 到 H 的情況，未列出的情況輸出 X，與逐條判斷等價。

## 複雜度

時間 O(1)，空間 O(1)，因為號碼數固定為 6。

## 實作注意

特別號不能加到一般命中數中；三個一般號碼加特別號對應 F，兩個一般號碼加特別號對應 G。

[C++ 程式](../../../cpp/2025-11/beginner/Lotto.cpp)

[Python 程式](../../../python/2025-11/beginner/Lotto.py)

驗證以 [狀態表](../../../STATUS.md) 與 [測試報告](../../../validation.json) 為準。範例通過不等同官方評測 AC；未做跨平台效能排名，沒有宣稱全球最快。
