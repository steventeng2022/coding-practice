# 1-巫師帽

2025/11/10~2025/11/14 · 潛力組

[官方題目](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202511/Hat.pdf) · [官方參考資料](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202511/Hat.zip) · [官方繁體中文詳解投影片](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202511/Hat.odp)

以下思路、正確性與複雜度以本儲存庫的 Python 版為主；C++ 檔是官方參考實作，其資料結構與常數可能不同，並未逐題證明為最快。

## 解題思路

回答 x 表示該顏色總共有 x+1 人。相同回答的受訪者每 x+1 人可歸為同一顏色，最後不足一組仍需補足整組。因此這類回答最少需要 ceil(人數/(x+1))×(x+1) 人。

## 正確性

相同顏色的人必須給相同回答，因此不同回答不能共用顏色。每個顏色最多容納 x+1 個此類受訪者，組數至少為上取整；按此數量分組並補上未受訪者就能達成下界，故總和最小。

## 複雜度

時間期望 O(N+U)，空間 O(U)，U 為不同回答數，另計輸入。

## 實作注意

回答的是「其他」同色人數，組大小應是 x+1；不是 x。

[C++ 程式](../../../cpp/2025-11/advanced/Hat.cpp)

[Python 程式](../../../python/2025-11/advanced/Hat.py)

驗證以 [狀態表](../../../STATUS.md) 與 [測試報告](../../../validation.json) 為準。範例通過不等同官方評測 AC；未做跨平台效能排名，沒有宣稱全球最快。
