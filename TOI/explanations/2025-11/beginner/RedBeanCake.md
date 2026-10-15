# 3-紅豆餅

2025/11/10~2025/11/14 · 新手組

[官方題目](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202511/RedBeanCake.pdf) · [官方參考資料](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202511/RedBeanCake.zip) · [官方繁體中文詳解投影片](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202511/RedBeanCake.odp)

以下思路、正確性與複雜度以本儲存庫的 Python 版為主；C++ 檔是官方參考實作，其資料結構與常數可能不同，並未逐題證明為最快。

## 解題思路

統計六種餐點，綠豆沙為編號 0，其餘為紅豆餅。每杯飲料與一個餅可組成 59 元套餐，比單買 70 元省 11 元，因此盡量配對，配對數為兩種數量的最小值。

## 正確性

每多組一份套餐都固定少 11 元，且不同配對不會改變折扣。因此最便宜方案必定使用最大可能套餐數；剩下餐點按單價計算即可。

## 複雜度

時間 O(N)，除讀入緩衝區外額外空間 O(1)。

## 實作注意

紅豆餅五種口味都能配套餐，先加總全部餅數。輸出包含六個分類數量與最後總價。

[C++ 程式](../../../cpp/2025-11/beginner/RedBeanCake.cpp)

[Python 程式](../../../python/2025-11/beginner/RedBeanCake.py)

驗證以 [狀態表](../../../STATUS.md) 與 [測試報告](../../../validation.json) 為準。範例通過不等同官方評測 AC；未做跨平台效能排名，沒有宣稱全球最快。
