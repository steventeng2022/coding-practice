# 2-角色升級

2025/06/09~2025/06/13 · 潛力組

[官方題目](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202506/Upgrade.pdf) · [官方參考資料](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202506/Upgrade.zip) · [官方繁體中文詳解投影片](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202506/Upgrade.odp)

以下思路、正確性與複雜度以本儲存庫的 Python 版為主；C++ 檔是官方參考實作，其資料結構與常數可能不同，並未逐題證明為最快。

## 解題思路

只看攻擊與防禦差值，技能的影響為增加 uA−uD。問題轉成能否挑選某個子集合，使初始差值加技能差值和為 0。將技能分兩半，左半所有可能和放入集合，再枚舉右半和，查詢其相反值是否存在。

## 正確性

任意技能子集合唯一分成左半與右半兩部分。左半集合完整包含其差值加初始差值；枚舉右半時找到相反值，等價於總差值為 0。枚舉涵蓋所有子集合，故能且僅能在存在合法升級方案時回傳 1。

## 複雜度

期望時間 O(2^(N/2))，空間 O(2^(N/2))，另計輸入；右半遞迴深度 O(N)。

## 實作注意

技能可以不選，所以兩半都包含空集合；攻擊與防禦的變化必須相減，不能相加。

[C++ 程式](../../../cpp/2025-06/advanced/Upgrade.cpp)

[Python 程式](../../../python/2025-06/advanced/Upgrade.py)

驗證以 [狀態表](../../../STATUS.md) 與 [測試報告](../../../validation.json) 為準。範例通過不等同官方評測 AC；未做跨平台效能排名，沒有宣稱全球最快。
