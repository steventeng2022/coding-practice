# 2-捷運

2025/03/17~2025/03/21 · 新手組

[官方題目](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202503/MRT.pdf) · [官方參考資料](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202503/MRT.zip) · [官方繁體中文詳解投影片](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202503/MRT.odp)

以下思路、正確性與複雜度以本儲存庫的 Python 版為主；C++ 檔是官方參考實作，其資料結構與常數可能不同，並未逐題證明為最快。

## 解題思路

先加總原票價，依搭乘次數套用百分比 100、95、90、85。用 (總額×折扣率+50)//100 進行非負數的四捨五入，最後與月票上限 1200 取較小值。

## 正確性

百分比形式使折扣後價格可完全用整數表示到分母 100，加 50 再整除正好實現五入。上限本身為整數，先四捨五入再取最小值與題意等價。

## 複雜度

時間 O(N)，除讀入緩衝區外額外空間 O(1)。

## 實作注意

Python round 在恰好 .5 時採偶數捨入，與本題四捨五入不同；次數門檻為 11、21、41。

[C++ 程式](../../../cpp/2025-03/beginner/MRT.cpp)

[Python 程式](../../../python/2025-03/beginner/MRT.py)

驗證以 [狀態表](../../../STATUS.md) 與 [測試報告](../../../validation.json) 為準。範例通過不等同官方評測 AC；未做跨平台效能排名，沒有宣稱全球最快。
