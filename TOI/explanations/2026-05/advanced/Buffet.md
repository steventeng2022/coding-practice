# 2-吃自助餐

2026/05/04~2026/05/08 · 潛力組

[官方題目](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202605/Buffet.pdf) · [官方參考資料](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202605/Buffet.zip) · [官方繁體中文詳解投影片](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202605/Buffet.odp)

以下思路、正確性與複雜度以本儲存庫的 Python 版為主；C++ 檔是官方參考實作，其資料結構與常數可能不同，並未逐題證明為最快。

## 解題思路

依餐區逐區做背包。global[p] 代表前面餐區花費不超過 p 的最大滿意度；處理新區時增加「此區最多選 k 道」維度。每道菜以 0/1 背包方式更新，菜數 k 倒序以避免重複使用同道菜。完成餐區後只保留 k=min(本區菜數,R) 的那一層。

## 正確性

狀態涵蓋每個合法選法的預算與當區道數上限。對一道菜，最佳選法不是不選，就是由少一道、扣除價格的狀態轉移後加上滿意度。k 倒序保證來源尚未處理本菜，故同菜最多一次。各區之間只需保留總預算最佳值，符合最優子結構。

## 複雜度

設菜數總和為 S，時間 O(SRP)，空間 O(RP)，P 為預算，R 為每區菜數上限；另計輸入。

## 實作注意

Python 版與 C++ 同為此複雜度，但極限資料仍需依評測時限實測，不能僅依範例宣稱通過。倒序更新菜數才能避免無限次取菜。

[C++ 程式](../../../cpp/2026-05/advanced/Buffet.cpp)

[Python 程式](../../../python/2026-05/advanced/Buffet.py)

驗證以 [狀態表](../../../STATUS.md) 與 [測試報告](../../../validation.json) 為準。範例通過不等同官方評測 AC；未做跨平台效能排名，沒有宣稱全球最快。
