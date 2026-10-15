# 1-建築物拆除

2025/04/28~2025/05/02 · 潛力組

[官方題目](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202504/Building.pdf) · [官方參考資料](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202504/Building.zip) · [官方繁體中文詳解投影片](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202504/Building.odp)

以下思路、正確性與複雜度以本儲存庫的 Python 版為主；C++ 檔是官方參考實作，其資料結構與常數可能不同，並未逐題證明為最快。

## 解題思路

按每日罰金 a 與拆除時間 b 的比例 a/b 由大到小拆除，以交叉相乘 a1b2 與 a2b1 比較，避免浮點誤差。維護尚未拆完建物的罰金總和，乘上當次拆除時間累加。

## 正確性

只比較相鄰兩棟 i、j，先 i 後 j 的交互等待成本為 a[j]b[i]，先 j 後 i 則為 a[i]b[j]。若 a[i]b[j]≥a[j]b[i]，先 i 不會較差。反覆交換所有逆序相鄰對，就得到比例降序的最優排序。

## 複雜度

時間 O(N log N)，空間 O(N)。

## 實作注意

比例相同時任意順序皆可。C++ 交叉相乘與累計費用需要足夠寬的整數。

[C++ 程式](../../../cpp/2025-04/advanced/Building.cpp)

[Python 程式](../../../python/2025-04/advanced/Building.py)

驗證以 [狀態表](../../../STATUS.md) 與 [測試報告](../../../validation.json) 為準。範例通過不等同官方評測 AC；未做跨平台效能排名，沒有宣稱全球最快。
