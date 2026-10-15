# 2-餅乾促銷

2025/11/10~2025/11/14 · 潛力組

[官方題目](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202511/Cookies.pdf) · [官方參考資料](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202511/Cookies.zip) · [官方繁體中文詳解投影片](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202511/Cookies.odp)

以下思路、正確性與複雜度以本儲存庫的 Python 版為主；C++ 檔是官方參考實作，其資料結構與常數可能不同，並未逐題證明為最快。

## 解題思路

每個促銷方案當作可無限選用的物品：取得 A+B 包、花費 A 元。dp[j] 表示剛好取得 j 包的最低花費，數量正序更新以允許同方案重複購買。最後取 j≥C 的最小值。只需算到 C−1+最大方案包數。

## 正確性

最優選法中若總包數至少為 C 加上一個最大方案包數，移除任一方案後仍達標且花費更低，矛盾。因此上述上界包含最優解。完全背包轉移枚舉最後使用的方案，涵蓋所有可行組合，所以所得最小花費正確。

## 複雜度

令 W=C−1+max(A+B)，時間 O(NW)，空間 O(W)，另計輸入。

## 實作注意

目標是至少 C 包，不能只取 dp[C]；數量要正序，倒序會變成每個方案只能用一次。

[C++ 程式](../../../cpp/2025-11/advanced/Cookies.cpp)

[Python 程式](../../../python/2025-11/advanced/Cookies.py)

驗證以 [狀態表](../../../STATUS.md) 與 [測試報告](../../../validation.json) 為準。範例通過不等同官方評測 AC；未做跨平台效能排名，沒有宣稱全球最快。
