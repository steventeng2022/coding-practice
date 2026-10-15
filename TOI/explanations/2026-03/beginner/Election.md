# 2-選舉

2026/03/16~2026/03/20 · 新手組

[官方題目](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202603/Election.pdf) · [官方參考資料](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202603/Election.zip)

以下思路、正確性與複雜度以本儲存庫的 Python 版為主；C++ 檔是官方參考實作，其資料結構與常數可能不同，並未逐題證明為最快。

## 解題思路

每區只比較普選票數，較高者取得該區全部選舉人票。分別累計兩人的選舉人票，再輸出較大者及其票數。

## 正確性

各區選舉人票歸屬只依該區普選結果決定，與其他區無關。逐區分配後兩個累加器即為最終選舉人票；比較兩者即可找出勝者。

## 複雜度

時間 O(K)，除讀入緩衝區外額外空間 O(1)。

## 實作注意

比較的是選舉人票總和，不能直接加總普選票判斷總統勝負。題目保證最終沒有平手。

[C++ 程式](../../../cpp/2026-03/beginner/Election.cpp)

[Python 程式](../../../python/2026-03/beginner/Election.py)

驗證以 [狀態表](../../../STATUS.md) 與 [測試報告](../../../validation.json) 為準。範例通過不等同官方評測 AC；未做跨平台效能排名，沒有宣稱全球最快。
