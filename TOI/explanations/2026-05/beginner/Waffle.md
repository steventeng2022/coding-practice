# 2-鬆餅

2026/05/04~2026/05/08 · 新手組

[官方題目](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202605/Waffle.pdf) · [官方參考資料](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202605/Waffle.zip) · [官方繁體中文詳解投影片](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202605/Waffle.odp)

以下思路、正確性與複雜度以本儲存庫的 Python 版為主；C++ 檔是官方參考實作，其資料結構與常數可能不同，並未逐題證明為最快。

## 解題思路

維護兩台烤爐的最早空閒時間。依訂單順序，將下一筆訂單交給最早空閒的烤爐，再增加該口味所需時間。最後答案是兩台烤爐完成時間的最大值。

## 正確性

任何時刻下一筆尚未處理的訂單只能等待最早空閒的烤爐。用其當前完成時間加上烘烤時間，恰好得到這筆訂單的完成時刻。逐筆模擬符合題目指定的派工規則，所有訂單完成的時刻即兩爐最大值。

## 複雜度

時間 O(M)，除讀入緩衝區外額外空間 O(1)。

## 實作注意

不能重新排序訂單。兩爐同時空閒時選其中一台即可，因兩爐烘烤時間相同。

[C++ 程式](../../../cpp/2026-05/beginner/Waffle.cpp)

[Python 程式](../../../python/2026-05/beginner/Waffle.py)

驗證以 [狀態表](../../../STATUS.md) 與 [測試報告](../../../validation.json) 為準。範例通過不等同官方評測 AC；未做跨平台效能排名，沒有宣稱全球最快。
