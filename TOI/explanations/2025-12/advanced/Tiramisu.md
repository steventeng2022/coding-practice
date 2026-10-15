# 2-提拉米蘇

2025/12/22~2025/12/26 · 潛力組

[官方題目](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202512/Tiramisu.pdf) · [官方參考資料](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202512/Tiramisu.zip) · [官方繁體中文詳解投影片](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202512/Tiramisu.odp)

以下思路、正確性與複雜度以本儲存庫的 Python 版為主；C++ 檔是官方參考實作，其資料結構與常數可能不同，並未逐題證明為最快。

## 解題思路

每段折線與 x 軸圍出一個梯形，其面積兩倍為 Δx×(左高+右高)。分別累加上折線與下折線的梯形面積兩倍，再相減，即得到中間厚度為 1 的蛋糕體積兩倍。

## 正確性

題目保證兩折線不相交，且覆蓋相同水平範圍。上曲線下方面積減下曲線下方面積，正好剩下兩曲線之間區域；沿各自頂點切分不改變總面積，因此不必合併兩組 x 座標。

## 複雜度

時間 O(M+N)，除讀入緩衝區外額外空間 O(1)。

## 實作注意

全程計算兩倍面積可避免浮點數；C++ 中乘法與累加需用 64 位元整數。

[C++ 程式](../../../cpp/2025-12/advanced/Tiramisu.cpp)

[Python 程式](../../../python/2025-12/advanced/Tiramisu.py)

驗證以 [狀態表](../../../STATUS.md) 與 [測試報告](../../../validation.json) 為準。範例通過不等同官方評測 AC；未做跨平台效能排名，沒有宣稱全球最快。
