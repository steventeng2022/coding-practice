# 1-加密系統

2025/03/17~2025/03/21 · 潛力組

[官方題目](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202503/Encryption.pdf) · [官方參考資料](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202503/Encryption.zip) · [官方繁體中文詳解投影片](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202503/Encryption.odp)

以下思路、正確性與複雜度以本儲存庫的 Python 版為主；C++ 檔是官方參考實作，其資料結構與常數可能不同，並未逐題證明為最快。

## 解題思路

OR 為 1、AND 為 0 的位置必由 x、y 其中一方持有，而共同為 1 的位元對差值互相抵銷。可分配位元總和 g=a−b。全部分給同一人時差值最大 g；最小差則將最高位 h 放一邊，其餘所有位放另一邊，得到 2h−g。

## 正確性

最高不同位 h 嚴格大於所有更低位的總和，因此持有此位的一方必較大。要讓差值最小，應讓該方不持有任何其他不同位，將全部低位分給另一方，差值為 h−(g−h)。最大差值不可能超過全部不同位總和 g，且可直接達成。

## 複雜度

在題目固定 30 位元範圍內，每筆時間 O(1)，總時間 O(T)，除輸入輸出外額外空間 O(1)。

## 實作注意

a=b 時沒有最高不同位，需先處理。輸入應符合某組 OR、AND 的合法關係。

[C++ 程式](../../../cpp/2025-03/advanced/Encryption.cpp)

[Python 程式](../../../python/2025-03/advanced/Encryption.py)

驗證以 [狀態表](../../../STATUS.md) 與 [測試報告](../../../validation.json) 為準。範例通過不等同官方評測 AC；未做跨平台效能排名，沒有宣稱全球最快。
