# 3-排列順序

2025/06/09~2025/06/13 · 潛力組

[官方題目](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202506/Permutation.pdf) · [官方參考資料](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202506/Permutation.zip) · [官方繁體中文詳解投影片](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202506/Permutation.odp)

## 解題思路

計算字典序排在輸入排列之前的排列數。固定第一個不同位置 i，可選的較小未使用數字數量用 Fenwick 樹求出；後面可任意填入剩餘的 N−i−1 個不同數字，方法數為 P(M−i−1,N−i−1)。兩者相乘後對所有位置累加。

## 正確性

任何較小排列都有唯一的第一個不同位置，所以各位置計數互斥且完整。Fenwick 樹維護前面已使用數字數量，從 value−1 扣除不再可用者，得到正確候選數。後綴為從剩餘數字選取並排序的排列數。其階乘分母恆為 (M−N)!，只需一次模逆元。

## 複雜度

時間 O(M+N log M+log MOD)，空間 O(M)。

## 實作注意

答案是從 0 起算的排序位置，不要加 1；輸入是不重複的長度 N 排列，取自 1..M。

[C++ 程式](../../../cpp/2025-06/advanced/Permutation.cpp)

[Python 程式](../../../python/2025-06/advanced/Permutation.py)

驗證以 [狀態表](../../../STATUS.md) 與 [測試報告](../../../validation.json) 為準。範例通過不等同官方評測 AC；未做跨平台效能排名，沒有宣稱全球最快。
