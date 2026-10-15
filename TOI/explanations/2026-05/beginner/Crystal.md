# 1-水晶共鳴

2026/05/04~2026/05/08 · 新手組

[官方題目](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202605/Crystal.pdf) · [官方參考資料](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202605/Crystal.zip) · [官方繁體中文詳解投影片](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202605/Crystal.odp)

以下思路、正確性與複雜度以本儲存庫的 Python 版為主；C++ 檔是官方參考實作，其資料結構與常數可能不同，並未逐題證明為最快。

## 解題思路

相鄰且屬性相同的能量團會合併，所以答案是連續相同值各段的長度。從左到右作游程編碼，屬性改變時結束前一段。

## 正確性

每一段都是極大的連續相同屬性區間，段內可以全部合併，段與段之間屬性不同而不能合併，因此這些段長恰好是最後各能量團強度。

## 複雜度

時間 O(N)，除輸入與輸出字串之外，游程掃描額外空間 O(1)。

## 實作注意

只合併相鄰相同值；不能把不同位置但相同屬性的所有值合併。最後一段也必須輸出。

[C++ 程式](../../../cpp/2026-05/beginner/Crystal.cpp)

[Python 程式](../../../python/2026-05/beginner/Crystal.py)

驗證以 [狀態表](../../../STATUS.md) 與 [測試報告](../../../validation.json) 為準。範例通過不等同官方評測 AC；未做跨平台效能排名，沒有宣稱全球最快。
