# 2-試算表

2025/09/29~2025/10/03 · 潛力組

[官方題目](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202509/sheet.pdf) · [官方參考資料](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202509/sheet.zip) · [官方繁體中文詳解投影片](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202509/sheet.odp)

## 解題思路

將儲存格參照建成依賴圖，從常數或只含常數的公式開始拓樸計算。每當一個格子完成，就把值加給依賴它的公式，並減少尚未完成參照數。最後仍有未完成參照的格子，包含循環本身與依賴循環者，全部輸出 ERROR。

## 正確性

入隊時所有參照都已完成，累加值正好等於公式各項之和，取模即為正確結果。無循環依賴的格子按拓樸順序都會完成。循環中每格永遠等待另一個循環格，且依賴它的格子也無法完成，所以剩餘集合恰好是錯誤格與其所有受影響格。

## 複雜度

V=MN，參照邊數 E≤2V，時間 O(V+E)，空間 O(V+E)。

## 實作注意

同一格可能在公式中被參照兩次，應計兩條依賴與兩次加總。不能只將循環上的格子標 ERROR，依賴它們的格子也會出錯。

[C++ 程式](../../../cpp/2025-09/advanced/sheet.cpp)

[Python 程式](../../../python/2025-09/advanced/sheet.py)

驗證以 [狀態表](../../../STATUS.md) 與 [測試報告](../../../validation.json) 為準。範例通過不等同官方評測 AC；未做跨平台效能排名，沒有宣稱全球最快。
