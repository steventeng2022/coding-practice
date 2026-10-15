# 3-橋牌

2025/06/09~2025/06/13 · 新手組

[官方題目](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202506/Bridge.pdf) · [官方參考資料](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202506/Bridge.zip) · [官方繁體中文詳解投影片](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202506/Bridge.odp)

以下思路、正確性與複雜度以本儲存庫的 Python 版為主；C++ 檔是官方參考實作，其資料結構與常數可能不同，並未逐題證明為最快。

## 解題思路

牌的第一個字元代表花色，第二個字元代表點數。累加 S、H、D、C 四種花色數量，並對 A、K、Q、J 加上 4、3、2、1 點。

## 正確性

每張牌恰屬一種花色，且只有四種大牌提供點數，所以逐牌分別累加花色與點數就等於整手牌的兩種統計。

## 複雜度

時間 O(1)，空間 O(1)，因牌數固定 13 張。

## 實作注意

花色輸出順序是 S H D C；10 或其他數字牌皆不計大牌點。

[C++ 程式](../../../cpp/2025-06/beginner/Bridge.cpp)

[Python 程式](../../../python/2025-06/beginner/Bridge.py)

驗證以 [狀態表](../../../STATUS.md) 與 [測試報告](../../../validation.json) 為準。範例通過不等同官方評測 AC；未做跨平台效能排名，沒有宣稱全球最快。
