# 1-紅包

2026/03/16~2026/03/20 · 新手組

[官方題目](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202603/RedEnvelope.pdf) · [官方參考資料](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202603/RedEnvelope.zip) · [官方繁體中文詳解投影片](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202603/RedEnvelope.odp)

以下思路、正確性與複雜度以本儲存庫的 Python 版為主；C++ 檔是官方參考實作，其資料結構與常數可能不同，並未逐題證明為最快。

## 解題思路

依序讀入每個紅包三種鈔票的張數，乘以面額後加入總額。不必保存全部紅包資料。

## 正確性

單一紅包金額為 100a+500b+1000c。每處理一個紅包，累加器就等於已處理紅包金額總和；因此處理 N 個後得到所有紅包的總額。

## 複雜度

時間 O(N)，除讀入緩衝區外額外空間 O(1)。

## 實作注意

三個欄位依序對應 100、500、1000；張數可以為 0。

[C++ 程式](../../../cpp/2026-03/beginner/RedEnvelope.cpp)

[Python 程式](../../../python/2026-03/beginner/RedEnvelope.py)

驗證以 [狀態表](../../../STATUS.md) 與 [測試報告](../../../validation.json) 為準。範例通過不等同官方評測 AC；未做跨平台效能排名，沒有宣稱全球最快。
