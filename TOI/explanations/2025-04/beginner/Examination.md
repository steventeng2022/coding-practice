# 2-學測

2025/04/28~2025/05/02 · 新手組

[官方題目](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202504/Examination.pdf) · [官方參考資料](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202504/Exam.zip) · [官方繁體中文詳解投影片](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202504/Exam.odp)

以下思路、正確性與複雜度以本儲存庫的 Python 版為主；C++ 檔是官方參考實作，其資料結構與常數可能不同，並未逐題證明為最快。

## 解題思路

每科先判斷是否為 0 分，是則輸出 X；其餘依由高到低的五個標準，取第一個達標門檻對應 A..E；連最低門檻都未達則是 F。

## 正確性

門檻由高至低排列，第一個不高於分數的門檻就是最高可達等級。0 分有獨立規則，先處理可避免被誤歸類。

## 複雜度

時間 O(1)，空間 O(1)，因科數固定六科、每科五個標準。

## 實作注意

即使該科為 0 分，仍要讀完該科五個門檻；邊界分數等於門檻時算達標。

[C++ 程式](../../../cpp/2025-04/beginner/Examination.cpp)

[Python 程式](../../../python/2025-04/beginner/Examination.py)

驗證以 [狀態表](../../../STATUS.md) 與 [測試報告](../../../validation.json) 為準。範例通過不等同官方評測 AC；未做跨平台效能排名，沒有宣稱全球最快。
